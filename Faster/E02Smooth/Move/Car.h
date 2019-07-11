#pragma once
#include "phy.h"

class Car
{
public:
	Car();
	virtual ~Car();

	// ��ȡ�����ߴ�(��λ:��)
	FLOAT2 GetSize() { return FLOAT2(c_fWidth, c_fLength); }
	// ��ȡ��ǰλ��(��λ:��)
	inline FLOAT2 GetPos();
	// �ƶ�λ��,������λ������(��λ:��)
	FLOAT2 Move(float fDeltaX, float fDeltaY);
protected:
	// ��(��λ:��)
	static const float c_fLength;
	// ��(��λ:��)
	static const float c_fWidth;
private:
	// ���ĵ�X����(��λ:��)
	float m_fX = 0.0f;
	// ���ĵ�Y����(��λ:��)
	float m_fY = 0.0f;
};

