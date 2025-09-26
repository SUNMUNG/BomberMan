#pragma once
class Actor
{
public:
	Actor() = default;
	virtual ~Actor()=default; // �Ҹ��ڿ� virtual �߰�

	virtual inline int GetPosX() = 0;
	virtual inline int GetPosY() = 0;
	virtual inline int GetHP() = 0;
	virtual void setDefault(int x, int y) =0;
	virtual int TakeDamage(int indamage) = 0;
	virtual void PosXMove() {};
	virtual void PosYMove() {};

};

