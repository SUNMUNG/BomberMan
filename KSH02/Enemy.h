#pragma once
#include "Actor.h"

class Enemy : public Actor
{

public:
	Enemy() = default;

	// --- Actor�κ��� ��ӹ޾� ������ �Լ��� ---
	inline int GetPosX() override { return PosX; }
	inline int GetPosY() override { return PosY; }
	inline int GetHP() override { return HP; }

	void setDefault(int x, int y) override; // ���� �ʱ� ��ġ�� ���� ����
	int TakeDamage(int indamage) override; // �������� �޴� ó��

	// --- Enemy ���� �Լ� ---
	void PosXMove(int inPosX); // x������ �̵�
	void PosYMove(int inPosY); // y������ �̵�

	// --- Enemy ���� ���� ---
	bool MoveDir = false; // �̵� ���� (����/�¿�) ����
	bool isDead = false;  // ��� ����

private:
	int PosX = 9;
	int PosY = 9;
	int HP = 1;
	const int defaultHp = 1; // �⺻ ü��
};

