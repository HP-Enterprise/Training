#pragma once
#include "phy.h"

class Car
{
public:
	Car();
	virtual ~Car();

	// ��ȡ�����ߴ�
	FLOAT2 GetSize() { return FLOAT2(c_fWidth, c_fLength); }
	// ��ȡ��ǰλ��
	inline FLOAT2 GetPos();
	// �ƶ�λ��,������λ������
	FLOAT2 Move(float fDeltaX, float fDeltaY);
protected:
	// ��
	static const float c_fLength;
	// ��
	static const float c_fWidth;
private:
	// ���ĵ�X����
	float m_fX = 0.0f;
	// ���ĵ�Y����
	float m_fY = 0.0f;
};

