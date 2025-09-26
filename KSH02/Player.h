#pragma once
#include "Actor.h"
class Player :public Actor
{
public:

	Player() = default;
	virtual ~Player();

	// --- Getter �Լ��� ---
	inline int ExpectedGetPosY() const { return ExpectedPosY; } // �̵� ���� y��ǥ
	inline int ExpectedGetPosX() const { return ExpectedPosX; } // �̵� ���� x��ǥ
	inline int GetPosX() override { return PosX; }
	inline int GetPosY() override { return PosY; }
	inline int GetHP() override { return HP; }

	// --- Actor�κ��� ��ӹ޾� ������ �Լ��� ---
	void setDefault(int x, int y) override;
	int TakeDamage(int indamage) override;

	// --- Player �̵� ���� �Լ� ---
	void PosXMove() override; // x������ ���� �̵� Ȯ��
	void PosYMove() override; // y������ ���� �̵� Ȯ��
	void ExpectedPosXMove(int inPosX); // x�� �̵� ���� ��ġ ���
	void ExpectedPosYMove(int inPosY); // y�� �̵� ���� ��ġ ���

	// --- Player ���� �� �ɷ�ġ ---
	bool isDead = false;
	int UpgradeChance = 1;    // ���׷��̵� ���� Ƚ��
	int maxBombs = 1;         // ��ġ ������ �ִ� ��ź ����
	int currentBombs = 0;     // ���� ��ġ�� ��ź ����
	int bombRange = 2;        // ��ź�� ���� ����
private:
	int ExpectedPosX = 1;
	int ExpectedPosY = 1;
	int PosX = 1;
	int PosY = 1;
	int HP = 5;
	const int defaultHp = 5; // �⺻ ü��
};

