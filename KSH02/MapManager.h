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
	void InitializeMap1(Player* player,Enemy* enemy, Enemy* enemy2); // �ʱ�ʻ���
	void InitializeMap2(Player* player,Enemy* enemy,Enemy* enemy2); // �ʱ�ʻ���

	void PrintMap(Player* player); // ����ʻ��� ����Ʈ
	bool CanMove(int posX, int posY) const; //�÷��̾�,�� �̵������Ѱ�����
	bool CanBreak(int inPosX, int inPosY) const; //��ź�� �μ����ִ°�����
	bool isPlayerHit(int inPosX, int inPosY, Player* player) const; //�÷��̾� �¾Ҵ���
	bool isEnemyHit(int inPosX, int inPosY) const; //�� �¾Ҵ���
	bool isBreakableHit(int inPosX, int inPosY) const; //�μ��� �ִ� �� �¾Ҵ���
	const int Stage1RemainEnemy = 2;
	const int Stage2RemainEnemy = 2;
	int RemainEnemy;
	static const int MapSize = 11;
	int Map[MapSize][MapSize];
};
