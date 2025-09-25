#include "GameManager.h"
#include <iostream>
#include <stdio.h>

GameManager::~GameManager()
{
	delete player;
	player = nullptr;
}

void GameManager::Clear()
{
	delete bomb;
	bomb = nullptr;
	delete enemy;
	enemy = nullptr;
	delete player;
	player = nullptr;


}

void GameManager::StagePlay()
{
	int PlayerSelect=-2;
	mapManager.InitializeMap();
	printf("���������� �����մϴ� !!\n");
	printf("������� óġ�ϼ���\n");

	while (!isStageClear) {
		mapManager.PrintMap(player, enemy);
		//PrintMap();
		printf("���ϴ� �ൿ�� �޴��� �°� �Է����ּ���.\n");
		printf("1.��  2.�Ʒ�\n3.���� 4.������\n");
		printf("5.��ź��ġ\n6.�������� ����\n");
		std::cin >> PlayerSelect;

		//�÷��̾� ������ġ
		mapManager.Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(MTileState::Road);
		
		switch (PlayerSelect)
		{
		case 1: 
			BombStateCheck();
			PlaceBomb();
			PlayerMoveYPlus();
			break;
		case 2:	
			BombStateCheck();
			PlaceBomb();
			PlayerMoveYMinus();
			break;
		case 3: 
			BombStateCheck();
			PlaceBomb();
			PlayerMoveXMinus();
			break;
		case 4: 
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
			else { OnBomb = true; isPresentBomb = true;		
			printf("���� ��ġ�� ��ź�� ��ġ�Ǿ����ϴ�.\n");
			}
			break;
		case 6: printf("�������� ����\n");
			break;
		default: printf("��ȿ���� ���� �޴� ��ȣ�Դϴ�.\n");
			break;
		}

	}
	mapManager.PrintMap(player, enemy);
	
}

void GameManager::PlayerMoveXPlus()
{
	if (mapManager.CanMove(player->GetPosX() + 1, player->GetPosY())) {
		player->PosXMove(+1);
	}
	else {
		printf("�̵� �Ұ����մϴ� .\n");
	}
}

void GameManager::PlayerMoveXMinus()
{
	if (mapManager.CanMove(player->GetPosX() - 1, player->GetPosY())) {
		player->PosXMove(-1);
	}
	else {
		printf("�̵� �Ұ����մϴ� .\n");
	}
}

void GameManager::PlayerMoveYMinus()
{
	if (mapManager.CanMove(player->GetPosX(), player->GetPosY() + 1)) {
		player->PosYMove(+1);
	}
	else {
		printf("�̵� �Ұ����մϴ� .\n");
	}
}

void GameManager::PlayerMoveYPlus()
{
	if (mapManager.CanMove(player->GetPosX(), player->GetPosY() - 1)) {
		player->PosYMove(-1);
	}
	else {
		printf("�̵� �Ұ����մϴ� .\n");
	}
}

void GameManager::BombStateCheck()
{

	if (isPresentBomb) {
		bomb->ExplosiveTime--;
		printf("���� Ÿ�̸� : %d\n", bomb->ExplosiveTime);
		if (bomb->isExplosive()) {
			ExplosiveTileChange(bomb->PosX, bomb->PosY);
			bomb->ExplosiveTime = bomb->DefaultExplosiveTime;
		}
	}
	
	if (WasPresentBomb) {
		bomb->ExplosiveRemoveTime--;
		printf("���� ����Ÿ�̸� : %d\n", bomb->ExplosiveRemoveTime);
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
		printf("������\n");
		printf("[1. Stage1 2. Stage2 ]\n");
		printf("[-1�Է½� ����]\n");
		std::cin >> MenuNumber;
		switch (MenuNumber) {
		case 1: StagePlay();
			break;
		case 2: StagePlay();
			break;
		default:
			break;
		}
	}
	

}


void GameManager::ExplosiveTileChange(int inPosX, int inPosY)
{
	if (mapManager.UnBreakable(inPosX, inPosY)) {
		isHit(inPosX, inPosY);
		mapManager.Map[inPosY][inPosX] = static_cast<int>(MTileState::HitBombEffect);
	}
	
	for (int i = 0; i <= bomb->ExplosiveRange; i++) {
		if (mapManager.UnBreakable(inPosX + i, inPosY)) {
			isHit(inPosX+i, inPosY);
			mapManager.Map[inPosY][inPosX + i] = static_cast<int>(MTileState::HitBombEffect);
		}
		else {
			break;
		}
	}
	for (int i = 0; i <= bomb->ExplosiveRange; i++) {
		if (mapManager.UnBreakable(inPosX - i, inPosY)) {
			isHit(inPosX - i, inPosY);
			mapManager.Map[inPosY][inPosX - i] = static_cast<int>(MTileState::HitBombEffect);
		}
		else {
			break;
		}
	}
	for (int i = 0; i <= bomb->ExplosiveRange; i++) {
		if (mapManager.UnBreakable(inPosX, inPosY + i)) {
			isHit(inPosX, inPosY+i);
			mapManager.Map[inPosY+i][inPosX] = static_cast<int>(MTileState::HitBombEffect);
		}
		else {
			break;
		}
	}
	for (int i = 0; i <= bomb->ExplosiveRange; i++) {
		if (mapManager.UnBreakable(inPosX, inPosY - i)) {
			isHit(inPosX, inPosY-i);
			mapManager.Map[inPosY-i][inPosX] = static_cast<int>(MTileState::HitBombEffect);
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
			if (mapManager.UnBreakable(inPosX + i, inPosY)) {
				mapManager.Map[inPosY][inPosX + i] = static_cast<int>(MTileState::Road);
			}
			
		}
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (mapManager.UnBreakable(inPosX - i, inPosY)) {
				mapManager.Map[inPosY][inPosX - i] = static_cast<int>(MTileState::Road);
			}
			
		}
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (mapManager.UnBreakable(inPosX, inPosY + i)) {
				mapManager.Map[inPosY + i][inPosX] = static_cast<int>(MTileState::Road);
			}
			
		}
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (mapManager.UnBreakable(inPosX, inPosY - i)) {
				mapManager.Map[inPosY - i][inPosX] = static_cast<int>(MTileState::Road);
			}
			
		}

		mapManager.Map[inPosY][inPosX] = static_cast<int>(MTileState::Road);
	}

	WasPresentBomb = false;
	
}


bool GameManager::isClear()
{
	bool isClear = false;

	return isClear;
}

void GameManager::isHit(int inPosX, int inPosY)
{
	if (mapManager.isPlayerHit(inPosX, inPosY)) {
		player->TakeDamage(1);
		printf("�÷��̾ �¾ҽ��ϴ� : %d\n", player->GetHP());
	}
	if (mapManager.isEnemyHit(inPosX, inPosY)) {
		enemy->TakeDamage(1);
		if (enemy->isDead == true) {
			enemy->PosXMove(20);
			enemy->PosYMove(20);
			enemy->isDead = false;
			mapManager.RemainEnemy--;
			if (mapManager.RemainEnemy <= 0) {
				printf("��� ���� óġ�߽��ϴ�\n");
				isStageClear = true;
			}
		}
		printf("���� �¾ҽ��ϴ� : %d\n", enemy->GetHP());
	}
	if (mapManager.isBreakableHit(inPosX, inPosY)) {

	}
}

