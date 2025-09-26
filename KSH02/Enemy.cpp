#include "Enemy.h"

#include <stdio.h>
void Enemy::setDefault(int x,int y)
{
	PosX = x;
	PosY = y;
	HP = defaultHp;
}
int Enemy::TakeDamage(int indamage)
{
	HP -= indamage;
	if (HP <= 0) {
		isDead = true;
		printf("���� �׾����ϴ�.\n");
	}

	return HP;
}

void Enemy::PosXMove(int inPosX)
{
	PosX += inPosX;
}

void Enemy::PosYMove(int inPosY)
{
	PosY += inPosY;
}
