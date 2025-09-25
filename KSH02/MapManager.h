#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bomb.h"

enum class MTileState
{

	Road = 0,
	Wall = 1,
	SoftRock = 10,
	UnbreakableRock = 100,
	Bomb = 20,
	HitBombEffect = 21,
	NotHitBombEffect = 22,
	Player = 50,
	Enemy = 60
};
class MapManager
{

public:
	void InitializeMap1(); // �ʱ�ʻ���
	void InitializeMap2(); // �ʱ�ʻ���

	void PrintMap(Player* player,Enemy* enemy); // ����ʻ��� ����Ʈ
	void TileStateChange(int posX, int posY, int TileState);
	bool CanMove(int posX, int posY) const; //�÷��̾� �̵������Ѱ�����
	bool CanBreak(int inPosX, int inPosY) const; //��ź�� �μ����ִ°�����
	bool isPlayerHit(int inPosX, int inPosY, Player* player) const; //�÷��̾� �¾Ҵ���
	bool isEnemyHit(int inPosX, int inPosY) const; //�� �¾Ҵ���
	bool isBreakableHit(int inPosX, int inPosY) const; //�μ��� �ִ� �� �¾Ҵ���
	int RemainEnemy = 1;
	static const int MapSize = 11;
	int Map[MapSize][MapSize];
};
