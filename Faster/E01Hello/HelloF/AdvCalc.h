#pragma once
enum SIMD
{
	NA = 0,
	MMX,
	SSE,
	AVX,
	FMA,
	AVX512
};

class AdvCalc
{
public:
	AdvCalc();
	virtual ~AdvCalc();

	// SIMD֧������
	BOOL IsSupport(SIMD level);

	// ��������
	float calcBasic();
	// MMX
	float calcSSE();
	// AVX
	float calcAVX();
	// FMA
	float calcFMA();
	// AVX512
	float calcAVX512();
private:
	// stress
	const int c_loop = 10000;
	// count
	const int c_len = 8000;
	// float a
	const float m_fA = 3.6f;
	// float b
	const float m_fB = 120.86f;
	// float values
	float* m_pV = NULL;
};
