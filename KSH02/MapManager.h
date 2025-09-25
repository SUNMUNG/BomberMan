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
	void InitializeMap(); // �ʱ�ʻ���
	void PrintMap(Player* player,Enemy* enemy); // ����ʻ��� ����Ʈ
	void TileStateChange(int posX, int posY, int TileState);
	bool CanMove(int posX, int posY); //�÷��̾� �̵������Ѱ�����
	bool UnBreakable(int inPosX, int inPosY); //��ź�� �μ����ִ°�����
	bool isPlayerHit(int inPosX, int inPosY); //�÷��̾� �¾Ҵ���
	bool isEnemyHit(int inPosX, int inPosY); //�� �¾Ҵ���
	bool isBreakableHit(int inPosX, int inPosY); //�μ��� �ִ� �� �¾Ҵ���

	int RemainEnemy = 1;
	static const int MapSize = 11;
	int Map[MapSize][MapSize];
};
