#pragma once
#include "Actor.h"
class Player :public Actor
{
public:

	Player() = default;
	virtual ~Player();

	//getter �Լ��� 
	inline int ExpectedGetPosY() const { return ExpectedPosY; }
	inline int ExpectedGetPosX() const { return ExpectedPosX; }
	inline int GetPosX() override { return PosX; }
	inline int GetPosY() override { return PosY; }
	inline int GetHP() override { return HP; }

	//�⺻ ��ġ �ʱⰪ ����
	void setDefault(int x,int y) override; 
	//��ź ������ ������
	int TakeDamage(int indamage) override;
	//�÷��̾� �̵��Լ�
	void PosXMove() override; 
	void PosYMove() override; 
	void ExpectedPosXMove(int inPosX);
	void ExpectedPosYMove(int inPosY);
	
	bool isDead = false;
	int UpgradeChance = 1;
	int maxBombs = 1; // �ִ� ��ź ����
	int currentBombs = 0; // ���� ��ġ�� ��ź ����
	int bombRange = 2; 

private:
	int ExpectedPosX =1;
	int ExpectedPosY =1;
	int PosX = 1;
	int PosY= 1;
	int HP = 5;
	const int defaultHp = 5;
};

