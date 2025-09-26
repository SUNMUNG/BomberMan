#pragma once
#include "MapManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bomb.h"
#include <vector>
#include <utility>
class GameManager
{
public:

	GameManager() = default;
	~GameManager()=default;
	MapManager mapManager;
	Player* player = new Player();
	Enemy* enemy = new Enemy();
	Enemy* enemy2 = new Enemy();
	std::vector<Bomb*> bombs; // ��ź ������
	void Clear(); //�����Ҵ� ����
	void StagePlay(int StageNum); //������
	void EnemyYMove(Enemy* enemy); 
	void KeyChange(char& PlayerSelect); //�Է¹޴� char int�� ��ȯ
	

	//�÷��̾� �̵��Լ� 4����
	void PlayerMoveXPlus();
	void PlayerMoveXMinus();
	void PlayerMoveYMinus();
	void PlayerMoveYPlus();
	//��ź ��ġ �� ��ź �� �ð����� 
	void BombStateCheck(); 
	void PlaceBomb();
	void ExplosiveTileChange(Bomb* bomb); //���߹�����ŭ Ÿ�� �ٲ���
	void ExplosiveTileRemove(Bomb* bomb); //���߹�����ŭ �ٲ��� Ÿ�� �����·�
	
	void StageMenu();
	//Ʈ���ſ� bool����
	bool isHit(int inPosX, int inPosY);
	bool isStageClear = false;
	bool isStage1Clear = false;
	bool isStage2Clear = false;
	bool isStageFail = false;


};

