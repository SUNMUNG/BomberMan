#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bomb.h"

enum class MTileState
{

	Road = 0,
	Wall = 1,
	SoftRock = 10,
	Bomb = 20,
	HitBombEffect = 21,
	Player = 50,
	Enemy = 60
};
class MapManager
{

public:
	//�������� 1, 2 �ʱⰪ ����
	void InitializeMap1(Player* player,Enemy* enemy, Enemy* enemy2); // �ʱ�ʻ���
	void InitializeMap2(Player* player,Enemy* enemy,Enemy* enemy2); // �ʱ�ʻ���
	// ����ʻ��� ����Ʈ
	void PrintMap(Player* player, Enemy* enemy1, Enemy* enemy2);
	//�÷��̾�,�� �̵������Ѱ�����
	bool CanMove(int posX, int posY) const; 
	//��ź�� �μ����ִ°�����
	bool CanBreak(int inPosX, int inPosY) const; 
	//�÷��̾� �¾Ҵ���
	bool isPlayerHit(int inPosX, int inPosY, Player* player) const;
	//�� �¾Ҵ���
	bool isEnemyHit(int inPosX, int inPosY, Enemy* enemy) const;
	//�μ��� �ִ� �� �¾Ҵ���

	bool isBreakableHit(int inPosX, int inPosY) const; 
	const int Stage1RemainEnemy = 2;
	const int Stage2RemainEnemy = 2;
	int RemainEnemy;
	static const int MapSize = 11;
	int Map[MapSize][MapSize];
};
