#pragma once
#include "model.h"

// ��ǰ����
typedef struct ViewFunctions ViewFunctions;

// ��ͼ: ����һ���̶�ֻ��1�иߵ���ͼ
typedef struct tagView
{
	Model		*pModel;
	HWND		hWnd;
	HPEN		hPen;
	HBRUSH		brBack;
	HFONT		fontText;
	COLORREF	color;
	int			nPadding;
	// APIָ��
	ViewFunctions	*pAPI;
} View;

// API����
View* ViewInit(View*, Model*, HWND);

typedef void(*fnViewOnPaint)(View*, HDC hdc);
typedef int(*fnViewGetHeight)(View*);
typedef void(*fnViewClose)(View*);
typedef void(*fnViewChangeColor)(View*, COLORREF);

struct ViewFunctions
{
	fnViewOnPaint		OnPaint;
	fnViewGetHeight		GetHeight;
	fnViewClose			Close;
	fnViewChangeColor	ChangeColor;
};