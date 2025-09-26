#include "GameManager.h"
#include <iostream>
#include <stdio.h>

void GameManager::Clear()
{
	delete bomb;
	bomb = nullptr;
	delete enemy2;
	enemy2 = nullptr;
	delete enemy;
	enemy = nullptr;
	delete player;
	player = nullptr;
}


void GameManager::StagePlay(int StageNum)
{
	char PlayerSelect=-2;
	if (StageNum == 1) {
		mapManager.InitializeMap1(player,enemy,enemy2);
		mapManager.RemainEnemy = mapManager.Stage1RemainEnemy;
	}
	else if (StageNum == 2) {
		mapManager.InitializeMap2(player, enemy , enemy2);
		mapManager.RemainEnemy = mapManager.Stage2RemainEnemy;
	}
	
	printf("���������� �����մϴ� !!\n");
	printf("������� óġ�ϼ���\n");

	while (!isStageClear && !isStageFail) {
		mapManager.PrintMap(player, enemy);
		printf("���ϴ� �ൿ�� �޴��� �°� �Է����ּ���.\n");
		printf("1.�� [W(w)] 2.�Ʒ� [S(s)]\n3.���� [A(a)] 4.������ [D(d)]\n");
		printf("5.��ź��ġ [B(b)]\n6.�������� ����\n");
		std::cin >> PlayerSelect;
		KeyChange(PlayerSelect);
		
		switch (PlayerSelect)
		{
		case 1:
			player->ExpectedPosYMove(-1);
			BombStateCheck();
			PlaceBomb();
			PlayerMoveYPlus();
			break;
		case 2:
			player->ExpectedPosYMove(+1);
			BombStateCheck();
			PlaceBomb();
			PlayerMoveYMinus();
			break;
		case 3:
			player->ExpectedPosXMove(-1);
			BombStateCheck();
			PlaceBomb();
			PlayerMoveXMinus();
			break;
		case 4:
			player->ExpectedPosXMove(+1);
			BombStateCheck();
			PlaceBomb();
			PlayerMoveXPlus();

			break;
		case 5:
			//���� �̵������� ��ź�� �򸮵��� bool OnBomb isPresentBomb true;
			//��ź�� �����ϸ� �ȱ򸮵���  �÷��̾� �ִ���ź�� 1
			if (isPresentBomb || WasPresentBomb) {
				printf("��ġ�� �Ұ����մϴ�. �̹� ����\n");
			}
			else {
				OnBomb = true; isPresentBomb = true;
				printf("���� ��ġ�� ��ź�� ��ġ�Ǿ����ϴ�.\n");
			}
			break;
		case 6:
			printf("�������� ����\n");
			isStageFail = true;
			break;
		default: printf("��ȿ���� ���� �޴� ��ȣ�Դϴ�.\n");
			break;
		}
		EnemyYMove(enemy);
		EnemyYMove(enemy2);

	}


	
}

void GameManager::EnemyYMove(Enemy* enemy)
{
	//false �� -y���� true�� +y����
	if (enemy->MoveDir) {
		if (mapManager.CanMove(enemy->GetPosX(), enemy->GetPosY() - 1)) {
			mapManager.Map[enemy->GetPosY()][enemy->GetPosX()] = static_cast<int>(MTileState::Road);
			enemy->PosYMove(-1);
			mapManager.Map[enemy->GetPosY()][enemy->GetPosX()] = static_cast<int>(MTileState::Enemy);
		}
		else {
			enemy->MoveDir = false;
		}
	}
	else {
		if (mapManager.CanMove(enemy->GetPosX(), enemy->GetPosY() + 1)) {
			mapManager.Map[enemy->GetPosY()][enemy->GetPosX()] = static_cast<int>(MTileState::Road);
			enemy->PosYMove(+1);
			mapManager.Map[enemy->GetPosY()][enemy->GetPosX()] = static_cast<int>(MTileState::Enemy);
		}
		else {
			enemy->MoveDir = true;
		}
	}
	
	
	
}

void GameManager::KeyChange(char& PlayerSelect)
{
	if (PlayerSelect == 'W' || PlayerSelect == 'w') {
		PlayerSelect = 1;
	}
	else if (PlayerSelect == 'S' || PlayerSelect == 's') {
		PlayerSelect = 2;
	}
	else if (PlayerSelect == 'A' || PlayerSelect == 'a') {
		PlayerSelect = 3;
	}
	else if (PlayerSelect == 'D' || PlayerSelect == 'd') {
		PlayerSelect = 4;
	}
	else if (PlayerSelect == 'B' || PlayerSelect == 'b') {
		PlayerSelect = 5;
	}
	else {
		PlayerSelect -= '0';
	}

}

void GameManager::PlayerMoveXPlus()
{
	if (mapManager.CanMove(player->GetPosX() + 1, player->GetPosY())) {
		if (mapManager.Map[player->GetPosY()][player->GetPosX()] != static_cast<int>(MTileState::Bomb)) {
			mapManager.Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(MTileState::Road);
		}
		player->PosXMove();
		//�÷��̾� �̵���ġ ����ȭ
		mapManager.Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(MTileState::Player);
	}
	else {
		printf("�̵� �Ұ����մϴ� .\n");
	}
}

void GameManager::PlayerMoveXMinus()
{
	if (mapManager.CanMove(player->GetPosX() - 1, player->GetPosY())) {
		if (mapManager.Map[player->GetPosY()][player->GetPosX()] != static_cast<int>(MTileState::Bomb)) {
			mapManager.Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(MTileState::Road);
		}
		player->PosXMove();
		//�÷��̾� �̵���ġ ����ȭ
		mapManager.Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(MTileState::Player);
	}
	else {
		printf("�̵� �Ұ����մϴ� .\n");
	}
}

void GameManager::PlayerMoveYMinus()
{
	
	if (mapManager.CanMove(player->GetPosX(), player->GetPosY() + 1)) {
		if (mapManager.Map[player->GetPosY()][player->GetPosX()] != static_cast<int>(MTileState::Bomb)) {
			mapManager.Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(MTileState::Road);
		}
		player->PosYMove();
		//�÷��̾� �̵���ġ ����ȭ
		mapManager.Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(MTileState::Player);
	}
	else {
		printf("�̵� �Ұ����մϴ� .\n");
	}
}

void GameManager::PlayerMoveYPlus()
{
	//�÷��̾� ������ġ
	if (mapManager.CanMove(player->GetPosX(), player->GetPosY() - 1)) {
		if (mapManager.Map[player->GetPosY()][player->GetPosX()] != static_cast<int>(MTileState::Bomb)) {
			mapManager.Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(MTileState::Road);
		}
		player->PosYMove();
		//�÷��̾� �̵���ġ ����ȭ
		mapManager.Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(MTileState::Player);
	}
	else {
		printf("�̵� �Ұ����մϴ� .\n");
	}
}

void GameManager::BombStateCheck()
{

	if (isPresentBomb) {
		bomb->ExplosiveTime--;
		printf("[ ���� Ÿ�̸� : %d ]\n", bomb->ExplosiveTime);
		if (bomb->isExplosive()) {
			ExplosiveTileChange(bomb->PosX, bomb->PosY);
			bomb->ExplosiveTime = bomb->DefaultExplosiveTime;
		}
	}
	
	if (WasPresentBomb) {
		bomb->ExplosiveRemoveTime--;
		printf("[ ���� ����Ÿ�̸� : %d ]\n", bomb->ExplosiveRemoveTime);
		if (bomb->ExplosiveRemoveTime == 0) {
			ExplosiveTileRemove(bomb->PosX, bomb->PosY);
			bomb->ExplosiveRemoveTime = bomb->DefaultExplosiveRemoveTime;
		}
	}
}

void GameManager::PlaceBomb()
{
	if (OnBomb) { //��ź��ġ�Լ�
		bomb->PosX = player->GetPosX(); //��ź XY Ȯ��
		bomb->PosY = player->GetPosY();
		mapManager.Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(MTileState::Bomb);
		OnBomb = false; // Ÿ�� ��ġ�ϰ� ��ź ��ġ���� Ʈ���� False
	}
}

void GameManager::StageMenu()
{
	int MenuNumber = -2;
	while (MenuNumber!=-1)
	{
		isStageClear = false;
		isStageFail = false;
		printf("������\n");
		printf("[ 1. Stage1 2. Stage2 3.��ź ���� ���׷��̵� ]\n");
		printf("[ -1�Է½� ���� ]\n");
		std::cin >> MenuNumber;
		switch (MenuNumber) {
		case 1: StagePlay(MenuNumber);
			break;
		case 2: StagePlay(MenuNumber);
			break;
		case 3: 
			printf("���� ���׷��̵� ����Ƚ���� : %d �Դϴ�\n", player->UpgradeChance);
			printf("���׷��̵� Ƚ���� �Ҹ��Ͽ� ��ź������ ���׷��̵� �Ͻðڽ��ϱ�?\n");
			printf("[ 1.Yes ] [ 2.NO ]\n");
			std::cin >> MenuNumber;
			if (MenuNumber == 1) {
				if (player->UpgradeChance <= 0) {
					printf("Ƚ���� �����մϴ�.\n");
				}
				else {
					bomb->ExplosiveRange++;
					player->UpgradeChance--;
					printf("������ %d �� �Ǿ����ϴ�.\n", bomb->ExplosiveRange);
				}
			}
			break;
		default:
			break;
		}
	}
	

}


void GameManager::ExplosiveTileChange(int inPosX, int inPosY)
{
	if (mapManager.CanBreak(inPosX, inPosY)) {
		isHit(inPosX, inPosY);
		mapManager.Map[inPosY][inPosX] = static_cast<int>(MTileState::HitBombEffect);
	}
	
	for (int i = 1; i <= bomb->ExplosiveRange; i++) {
		if (mapManager.CanBreak(inPosX + i, inPosY)) {
			if (isHit(inPosX + i, inPosY)) {
				break;
			}
			mapManager.Map[inPosY][inPosX + i] = static_cast<int>(MTileState::HitBombEffect);
		}
		else {
			break;
		}
	}
	for (int i = 1; i <= bomb->ExplosiveRange; i++) {
		if (mapManager.CanBreak(inPosX - i, inPosY)) {
			if (isHit(inPosX - i, inPosY)) {
				break;
			}
			mapManager.Map[inPosY][inPosX - i] = static_cast<int>(MTileState::HitBombEffect);
		}
		else {
			break;
		}
	}
	for (int i = 1; i <= bomb->ExplosiveRange; i++) {
		if (mapManager.CanBreak(inPosX, inPosY + i)) {
			if (isHit(inPosX, inPosY+i)) {
				break;
			}
			mapManager.Map[inPosY + i][inPosX] = static_cast<int>(MTileState::HitBombEffect);
		}
		else {
			break;
		}
	}
	for (int i = 1; i <= bomb->ExplosiveRange; i++) {
		if (mapManager.CanBreak(inPosX, inPosY - i)) {
			if (isHit(inPosX, inPosY - i)) {
				break;
			}
			mapManager.Map[inPosY - i][inPosX] = static_cast<int>(MTileState::HitBombEffect);
		}
		else {
			break;
		}
	}


	isPresentBomb = false;
	WasPresentBomb = true;
}

void GameManager::ExplosiveTileRemove(int inPosX, int inPosY)
{
	if (bomb->ExplosiveRemoveTime <= 0) {
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (mapManager.CanBreak(inPosX + i, inPosY)) {
				mapManager.Map[inPosY][inPosX + i] = static_cast<int>(MTileState::Road);
			}
			
		}
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (mapManager.CanBreak(inPosX - i, inPosY)) {
				mapManager.Map[inPosY][inPosX - i] = static_cast<int>(MTileState::Road);
			}
			
		}
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (mapManager.CanBreak(inPosX, inPosY + i)) {
				mapManager.Map[inPosY + i][inPosX] = static_cast<int>(MTileState::Road);
			}
			
		}
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (mapManager.CanBreak(inPosX, inPosY - i)) {
				mapManager.Map[inPosY - i][inPosX] = static_cast<int>(MTileState::Road);
			}
			
		}

		mapManager.Map[inPosY][inPosX] = static_cast<int>(MTileState::Road);
	}

	WasPresentBomb = false;
	
}


bool GameManager::isHit(int inPosX, int inPosY)
{
	bool isHit = false;
	if (mapManager.isPlayerHit(inPosX, inPosY,player)) {
		player->TakeDamage(1);
		isHit = true;
		printf("�÷��̾ �¾ҽ��ϴ� : %d\n", player->GetHP());
		if (player->isDead == true) {
			player->isDead = false;
			printf("�������� Ŭ���� ����!\n");
			isStageFail = true;
		}
	}
	if (mapManager.isEnemyHit(inPosX, inPosY)) {
		enemy->TakeDamage(1);
		isHit = true;
		printf("[ ���� �¾ҽ��ϴ� : %d ]\n", enemy->GetHP());
		if (enemy->isDead == true) {
			enemy->PosXMove(20);
			enemy->PosYMove(20);
			enemy->isDead = false;
			mapManager.RemainEnemy--;
			if (mapManager.RemainEnemy <= 0) {
				printf("�ظ�� ���� óġ�߽��ϴ�\n");
				printf("�ؽ������� Ŭ����!\n");
				player->UpgradeChance++;
				printf("���׷��̵� Ƚ�� : %d\n", player->UpgradeChance);
				mapManager.PrintMap(player, enemy);
				printf("[ ����Ϸ��� ���� ]\n");
				getchar();
				getchar();
				isStageClear = true;
			}
		}
	}
	if (mapManager.isBreakableHit(inPosX, inPosY)) {
		if (mapManager.Map[inPosY][inPosX] == static_cast<int>(MTileState::SoftRock)) {
			mapManager.Map[inPosY][inPosX] = static_cast<int>(MTileState::Road);
			isHit = true;
		}
	}
	return isHit;
}

