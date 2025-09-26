#pragma once
#include "MapManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bomb.h"
#include <vector>
class GameManager
{
public:

	GameManager() = default;
	~GameManager()=default;
	MapManager mapManager;
	Player* player = new Player();
	Enemy* enemy = new Enemy();
	Enemy* enemy2 = new Enemy();
	Bomb* bomb = new Bomb();
	void Clear(); //�����Ҵ� ����
	void StagePlay(int StageNum); //������
	void EnemyYMove(Enemy* enemy);
	void KeyChange(char& PlayerSelect);
	void PlayerMoveXPlus();
	void PlayerMoveXMinus();
	void PlayerMoveYMinus();
	void PlayerMoveYPlus();
	void BombStateCheck(); //��ź �ð����ҹ����� 
	void PlaceBomb(); //��ź ��ġ �Լ�
	void StageMenu();
	void ExplosiveTileChange(int inPosX,int inPosY); //���߹�����ŭ Ÿ�� �ٲ���
	void ExplosiveTileRemove(int inPosX,int inPosY); //���߹�����ŭ �ٲ��� Ÿ�� �����·�
	bool isHit(int inPosX, int inPosY);
	bool isPresentBomb = false; //����Ʈ���� ��ź����Ȯ�� bool
	bool WasPresentBomb = false; //����Ÿ������Ʈ����  bool
	bool isStageClear = false;
	bool isStage1Clear = false;
	bool isStage2Clear = false;
	bool isStageFail = false;
	bool OnBomb = false;

};

