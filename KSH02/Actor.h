#pragma once
class Actor
{
public:
	Actor() = default;
	virtual ~Actor()=default; // �Ҹ��ڿ� virtual �߰�

	virtual inline int GetPosX() = 0; // x��ǥ ��ȯ
	virtual inline int GetPosY() = 0; // y��ǥ ��ȯ
	virtual inline int GetHP() = 0;   // ü��(HP) ��ȯ
	virtual void setDefault(int x, int y) = 0; // �⺻ ���� ����
	virtual int TakeDamage(int indamage) = 0; // �������� �޴� ó��
	virtual void PosXMove() {}; // x�� �̵�
	virtual void PosYMove() {}; // y�� �̵�

};

