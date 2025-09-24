#include "GameManager.h"
#include <iostream>
#include <stdio.h>

GameManager::~GameManager()
{
	delete player;
	player = nullptr;
}

void GameManager::InitializeMap()
{

	for (int i = 0; i < MapSize; i++) {
		for (int j = 0; j < MapSize; j++) {
			if (i == MapSize - 1 || j == MapSize - 1 || i==0||j==0) {
				Map[i][j] = static_cast<int>(TileState::Wall);
			}
			else if (i%2==0&&j%2==0) {
				Map[i][j] = static_cast<int>(TileState::Wall);
			}
			else {
				Map[i][j] = static_cast<int>(TileState::Road);
			}
			
		}
	}

	Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(TileState::Player);

	
}

void GameManager::PrintMap()
{
	//�÷��̾� �̵���ġ ����ȭ
	Map[player->GetPosY()][player->GetPosX()]= static_cast<int>(TileState::Player);

	for(int i=0;i<MapSize;i++){
		for (int j = 0; j < MapSize; j++) {
			if (Map[i][j] == static_cast<int>(TileState::Road)) {
				printf("�� ");
			}
			else if (Map[i][j] == static_cast<int>(TileState::Wall)) {
				printf("�� ");
			}
			else if (Map[i][j] == static_cast<int>(TileState::SoftRock)) {
				printf("�� ");
			}
			else if (Map[i][j] == static_cast<int>(TileState::UnbreakableRock)) {
				printf("�� ");
			}
			else if (Map[i][j] == static_cast<int>(TileState::Bomb)) {
				printf("�� ");
			}
			else if (Map[i][j] == static_cast<int>(TileState::HitBombEffect)) {
				printf("�� ");
			}
			else if (Map[i][j] == static_cast<int>(TileState::NotHitBombEffect)) {
				printf("�� ");
			}
			else if (Map[i][j] == static_cast<int>(TileState::Player)) {
				printf("�� ");
			}
			else if (Map[i][j] == static_cast<int>(TileState::Enemy)) {
				printf("�� ");
			}
			else {
				printf("E ");
				//������ȵ� ��ȿ�����ʴ°�
			}
		}
		printf("\n");
	}
	printf("\n");
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
	
	printf("���������� �����մϴ� !!\n");
	printf("������� óġ�ϼ���\n");

	while (!isStageClear) {
		PrintMap();
		printf("���ϴ� �ൿ�� �޴��� �°� �Է����ּ���.\n");
		printf("1.��  2.�Ʒ�\n3.���� 4.������\n");
		printf("5.��ź��ġ\n6.�������� ����\n");
		std::cin >> PlayerSelect;
		
		Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(TileState::Road);

		switch (PlayerSelect)
		{
		case 1: 
			if (isPresentBomb) { //��ź���� //isPresentBomb ��ź�� �����ϴ��� bool 
				if (bomb->isExplosive()) { //isExplosive ��ź�� Ÿ�̸Ӱ� ���� ������������
					ExplosiveTileChange(bomb->PosX, bomb->PosY); //����Ÿ�� ����
					bomb->ExplosiveTime = bomb->DefaultExplosiveTime; //����Ÿ�̸� �������
				}
				else {
					
					printf("���� Ÿ�̸� : %d\n",bomb->ExplosiveTime);
				}
			}
			else {
				bomb->ExplosiveRemoveTime--;
				ExplosiveTileRemove(bomb->PosX, bomb->PosY);
			}
			if (OnBomb) { //��ź��ġ�Լ�
				bomb->PosX = player->GetPosX(); //��ź XY Ȯ��
				bomb->PosY = player->GetPosY();
				Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(TileState::Bomb);
				OnBomb = false; // Ÿ�� ��ġ�ϰ� ��ź ��ġ���� Ʈ���� False
			}
			//�����ϼ� ������ �����δ�
			if (CanMove(player->GetPosX(), player->GetPosY()-1)) {
				player->PosYMove(-1);
			}
			else {
				printf("�̵� �Ұ����մϴ� .\n");
			}
			break;
		case 2:	
			if (isPresentBomb) { 
				if (bomb->isExplosive()) {
					ExplosiveTileChange(bomb->PosX, bomb->PosY);
					bomb->ExplosiveTime = bomb->DefaultExplosiveTime;
				}
				else {
					printf("���� Ÿ�̸� : %d\n", bomb->ExplosiveTime);
				}
			}
			else {
				bomb->ExplosiveRemoveTime--;
				ExplosiveTileRemove(bomb->PosX, bomb->PosY);
			}
			if (OnBomb) {
				bomb->PosX = player->GetPosX();
				bomb->PosY = player->GetPosY();
				Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(TileState::Bomb);
				OnBomb = false;
			}
			if (CanMove(player->GetPosX(), player->GetPosY()+1)) {
				player->PosYMove(+1);
			}
			else {
				printf("�̵� �Ұ����մϴ� .\n");
			}
			break;
		case 3: 
			if(isPresentBomb){ 
				if (bomb->isExplosive()) {
					ExplosiveTileChange(bomb->PosX, bomb->PosY);
					bomb->ExplosiveTime = bomb->DefaultExplosiveTime;
				}
				else {
					printf("���� Ÿ�̸� : %d\n", bomb->ExplosiveTime);
				}
			}
			else {
				bomb->ExplosiveRemoveTime--;
				ExplosiveTileRemove(bomb->PosX, bomb->PosY);
			}
			if (OnBomb) {
				bomb->PosX = player->GetPosX();
				bomb->PosY = player->GetPosY();
				Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(TileState::Bomb);
				OnBomb = false;
			}
			if (CanMove(player->GetPosX()-1, player->GetPosY())) {
				player->PosXMove(-1);
			}
			else {
				printf("�̵� �Ұ����մϴ� .\n");
			}
			break;
		case 4: 
			if (isPresentBomb) { 
				if (bomb->isExplosive()) {
					ExplosiveTileChange(bomb->PosX, bomb->PosY);
					bomb->ExplosiveTime = bomb->DefaultExplosiveTime;
				}
				else {
					printf("���� Ÿ�̸� : %d\n", bomb->ExplosiveTime);
				}
			}
			else {
				bomb->ExplosiveRemoveTime--;
				ExplosiveTileRemove(bomb->PosX, bomb->PosY);
			}
			if (OnBomb) {
				bomb->PosX = player->GetPosX();
				bomb->PosY = player->GetPosY();
				Map[player->GetPosY()][player->GetPosX()] = static_cast<int>(TileState::Bomb);
				OnBomb = false;
			}
			if (CanMove(player->GetPosX()+1, player->GetPosY())) {
				player->PosXMove(+1);
			}
			else {
				printf("�̵� �Ұ����մϴ� .\n");
			}
			break;
		case 5: 
			//���� �̵������� ��ź�� �򸮵��� bool OnBomb isPresentBomb true;
			printf("���� ��ġ�� ��ź�� ��ġ�Ǿ����ϴ�.\n");
			//��ź�� �����ϸ� �ȱ򸮵���  �÷��̾� �ִ���ź�� 1
			if (isPresentBomb) { printf("��ġ�� �Ұ����մϴ�. �̹� ����\n"); }
			else { OnBomb = true; isPresentBomb = true; }
			break;
		case 6: printf("�������� ����\n");
			break;
		default: printf("��ȿ���� ���� �޴� ��ȣ�Դϴ�.\n");
			break;
		}

	}
	
}


void GameManager::ExplosiveTileChange(int inPosX, int inPosY)
{

	Map[inPosY][inPosX] = static_cast<int>(TileState::HitBombEffect);
	
	for (int i = 0; i <= bomb->ExplosiveRange; i++) {
		if (UnBreakable(inPosX + i, inPosY)) {
			Map[inPosY][inPosX + i] = static_cast<int>(TileState::HitBombEffect);
		}
	}
	for (int i = 0; i <= bomb->ExplosiveRange; i++) {
		if (UnBreakable(inPosX - i, inPosY)) {
			Map[inPosY][inPosX - i] = static_cast<int>(TileState::HitBombEffect);
		}
	}
	for (int i = 0; i <= bomb->ExplosiveRange; i++) {
		if (UnBreakable(inPosX, inPosY + i)) {
			Map[inPosY+i][inPosX] = static_cast<int>(TileState::HitBombEffect);
		}
	}
	for (int i = 0; i <= bomb->ExplosiveRange; i++) {
		if (UnBreakable(inPosX, inPosY - i)) {
			Map[inPosY-i][inPosX ] = static_cast<int>(TileState::HitBombEffect);
		}
	}

	isPresentBomb = false;
	
}

void GameManager::ExplosiveTileRemove(int inPosX, int inPosY)
{
	if (bomb->ExplosiveRemoveTime <= 0) {
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (UnBreakable(inPosX + i, inPosY)) {
				Map[inPosY][inPosX + i] = static_cast<int>(TileState::Road);
			}
		}
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (UnBreakable(inPosX - i, inPosY)) {
				Map[inPosY][inPosX - i] = static_cast<int>(TileState::Road);
			}
		}
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (UnBreakable(inPosX, inPosY + i)) {
				Map[inPosY + i][inPosX] = static_cast<int>(TileState::Road);
			}
		}
		for (int i = bomb->ExplosiveRange; i >= 0; i--) {
			if (UnBreakable(inPosX, inPosY - i)) {
				Map[inPosY - i][inPosX] = static_cast<int>(TileState::Road);
			}
		}

		Map[inPosY][inPosX] = static_cast<int>(TileState::Road);
	}

	
}

bool GameManager::CanMove(int posX, int posY)
{
	bool CanMove = false;

	if (Map[posY][posX] == static_cast<int>(TileState::Wall) ||
		Map[posY][posX] == static_cast<int>(TileState::Bomb) ||
		Map[posY][posX] == static_cast<int>(TileState::Enemy)) {
		CanMove = false;
	}
	else {
		CanMove = true;
	}

	return CanMove;
}

bool GameManager::UnBreakable(int inPosX, int inPosY)
{
	bool CanBreak = true;
	if (Map[inPosY][inPosX] == static_cast<int>(TileState::Wall)) {
		CanBreak=false;
	}
	return CanBreak;
}

bool GameManager::isClear()
{
	bool isClear = false;

	return isClear;
}

bool GameManager::isHit()
{
	bool isHit = false;

	return isHit;
}
