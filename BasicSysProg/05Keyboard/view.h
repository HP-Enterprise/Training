#pragma once
#include "model.h"

// ��ǰ����
typedef struct tagViewFunctions ViewFunctions;

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
	int			nFPS;
	int			nMaxFPS;
	BOOL		bNoLimit;
	// APIָ��
	ViewFunctions	*pAPI;
} View;

// API����
View* ViewInit(View*, Model*, HWND);

typedef void(*fnViewOnPaint)(View*, HDC hdc);
typedef int(*fnViewGetHeight)(View*);
typedef void(*fnViewChangeColor)(View*, COLORREF);
typedef void(*fnViewSetFPS)(View*, int, int, BOOL);
typedef void(*fnViewClose)(View*);

struct tagViewFunctions
{
	fnViewOnPaint		OnPaint;
	fnViewGetHeight		GetHeight;
	fnViewChangeColor	ChangeColor;
	fnViewSetFPS		SetFPS;
	fnViewClose			Close;
};