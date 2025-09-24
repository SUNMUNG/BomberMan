#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bomb.h"

enum class TileState
{

	Road = 0,
	Wall = 1,
	SoftRock = 10,
	UnbreakableRock = 100,
	Bomb = 20,
	HitBombEffect =21,
	NotHitBombEffect =22,
	Player=50,
	Enemy=60
};

class GameManager
{
public:

	GameManager() = default;
	~GameManager();
	Player* player = new Player();
	Enemy* enemy = new Enemy();
	Bomb* bomb = new Bomb();
	void InitializeMap(); // �ʱ�ʻ���
	void PrintMap(); // ����ʻ��� ����Ʈ
	void Clear(); //�����Ҵ� ����
	void StagePlay(); //������
	void ExplosiveTileChange(int inPosX,int inPosY); //���߹�����ŭ Ÿ�� �ٲ���
	void ExplosiveTileRemove(int inPosX,int inPosY); //���߹�����ŭ �ٲ��� Ÿ�� �����·�
	bool CanMove(int posX, int posY); //�÷��̾� �̵������Ѱ�����
	bool UnBreakable(int inPosX, int inPosY); //��ź�� �μ����ִ°�����
	bool isClear(); //���� Ŭ����
	bool isHit(); //�÷��̾� or �� �¾Ҵ���

	bool isPresentBomb = false;
	bool isStageClear = false;
	bool OnBomb = false;
	static const int MapSize = 11;
	int Map[MapSize][MapSize];
};

