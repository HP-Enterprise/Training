#include "stdafx.h"
#include "Car.h"

const float Car::c_fLength = 4.519f;
const float Car::c_fWidth = 1.852f;

Car::Car()
{
}

Car::~Car()
{
}

// ��ȡ��ǰλ��
FLOAT2 Car::GetPos()
{
	FLOAT2 pos(m_fX, m_fY);
	return pos;
}

// �ƶ�λ��
FLOAT2 Car::Move(float fDeltaX, float fDeltaY)
{
	m_fX += fDeltaX;
	m_fY += fDeltaY;

	return GetPos();
}
