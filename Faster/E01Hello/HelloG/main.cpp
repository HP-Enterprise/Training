#include <wchar.h>
#include <stdlib.h>
#include "x.h"

// function declare
void HowToRefVar();
void HowToInterpretation();
void HowToInterpretation2();

typedef void(*HowTo)();

int wmain()
{
	// ������ָ�� vs ����������
	HowToRefVar();

	// ��ν���
	HowToInterpretation();
	HowToInterpretation2();

	// �����������ڴ��׵�ַ����ʾ
	HowTo fnHowTo;
	fnHowTo = HowToInterpretation;
	fnHowTo();

	// �������׵�ַҲ���Դ����һ��������
	HowTo* pFn = &fnHowTo;
	(*pFn)();
	*pFn = HowToRefVar;
	(*pFn)();

	//////////////////////////////////////////////////
	// C++
	CBase* pB1 = new CBase();
	CBase* pB2 = new CBase();
	int size = sizeof(CBase);
	pB1->Output();

	CSon* pSon = new CSon();
	pSon->Output();
	CBase* pB3 = pSon;
	pB3->Output();

	delete pB1, pB2, pSon;
	
	//////////////////////////////////////////////////

	CBase2* p2B1 = new CBase2();
	CBase2* p2B2 = new CBase2();
	int size2 = sizeof(CBase2);
	p2B1->Output();

	CSon2* p2Son = new CSon2();
	p2Son->Output();
	CBase2* p2B3 = p2Son;
	p2B3->Output();

	delete p2B1, p2B2, p2Son;
	

	return 0;
}

// function implementation
void HowToRefVar()
{
	// ����
	int x = 0x61;
	

	// ������ָ��
	int* px = &x;

	// ����������
	int& rx = x;

	wchar_t buf[128];
	swprintf_s(buf, L"%x : %x : %x", x, *px, rx);			// ��16������ʾ��ֵ
	swprintf_s(buf, L"%d : %d : %d", x, *px, rx);			// ��10������ʾ��ֵ
	swprintf_s(buf, L"%p : %p : %p", &x, px, &rx);			// ��ʾ����x���ڴ��ַ
	swprintf_s(buf, L"%p : %p : %p", &px, buf, &buf[0]);	// px���ڴ��ַ,buf���׵�ַ,buf��һ��Ԫ�صĵ�ַ
}

void HowToInterpretation()
{
	// ���ݱ�����ֻ���ڴ�,��ô�������������Լ�����
	char data[8];

	for (int i = 0; i < 8; i++)
	{
		data[i] = 0x61 + i;
	}

	wchar_t buf[64];
	swprintf_s(buf, L"%d %d %d %d", data[0], data[1], data[2], data[3]);
	swprintf_s(buf, L"%x %x %x %x", data[0], data[1], data[2], data[3]);
	swprintf_s(buf, L"0x%x 0x%x 0x%x 0x%x", data[0], data[1], data[2], data[3]);
	swprintf_s(buf, L"%c %c %c %c", data[0], data[1], data[2], data[3]);

	swprintf_s(buf, L"0x%x 0x%x 0x%x 0x%x", *((short*)& data[0]), *((short*)& data[2]), *((short*)& data[4]), *((short*)& data[6]));
	swprintf_s(buf, L"%d %d %d %d", *((short*)&data[0]), *((short*)& data[2]), *((short*)& data[4]), *((short*)& data[6]));
}

struct S4
{
	char s0;
	char s1;
	char s2;
	char s3;
};

struct T1
{
	int t0;
};

void HowToInterpretation2()
{
	wchar_t buf[64];

	void* p = malloc(5);

	char* p1 = (char*)p;
	*p1 = 'a';
	*(p1 + 1) = 'b';
	*(p1 + 2) = 'c';
	p1[3] = 'd';
	p1[4] = 0;
	swprintf_s(buf, L"%d %d %d %d", p1[0], p1[1], p1[2], *(p1+3));

	short* p2 = (short*)p;
	p2[0] = 0x4241;
	p2[1] = 0x4443;
	swprintf_s(buf, L"%d %d %d %d", p1[0], p1[1], p1[2], p1[3]);
	swprintf_s(buf, L"%S", (char*)p2);

	S4* pS4 = (S4*)p;
	S4& rS4 = *pS4;
	swprintf_s(buf, L"%d %d %d %d", pS4->s0, pS4->s1, rS4.s2, rS4.s3);

	T1* pT1 = (T1*)p;
	swprintf_s(buf, L"%d", pT1->t0);

	free(p);
}