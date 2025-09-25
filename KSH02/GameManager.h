#pragma once
#include "MapManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bomb.h"

class GameManager
{
public:

	GameManager() = default;
	~GameManager();
	MapManager mapManager;
	Player* player = new Player();
	Enemy* enemy = new Enemy();
	Bomb* bomb = new Bomb();
	void Clear(); //�����Ҵ� ����
	void StagePlay(); //������
	void PlayerMoveXPlus();
	void PlayerMoveXMinus();
	void PlayerMoveYMinus();
	void PlayerMoveYPlus();
	void BombStateCheck(); //��ź �ð����ҹ����� 
	void PlaceBomb(); //��ź ��ġ �Լ�
	void StageMenu();
	void ExplosiveTileChange(int inPosX,int inPosY); //���߹�����ŭ Ÿ�� �ٲ���
	void ExplosiveTileRemove(int inPosX,int inPosY); //���߹�����ŭ �ٲ��� Ÿ�� �����·�
	bool isClear(); //���� Ŭ����
	void isHit(int inPosX, int inPosY);
	bool isPresentBomb = false; //����Ʈ���� ��ź����Ȯ�� bool
	bool WasPresentBomb = false; //����Ÿ������Ʈ����  bool
	bool isStageClear = false;
	bool OnBomb = false;
	static const int MapSize = 11;
	int Map[MapSize][MapSize];
};

