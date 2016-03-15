#pragma once
#include "model.h"

// ��ǰ����
typedef struct ViewMatrixFunctions ViewMatrixFunctions;

// ��ͼ: ����һ���ڿ͵۹�������ͼ
typedef struct tagViewMatrix
{
	Model		*pModel;
	HWND		hWnd;
	HPEN		hPen;
	HBRUSH		brBack;
	HFONT		fontText;
	COLORREF	color;
	int			nPadding;
	RECT		rect;
	POINT		*pPoints;
	// APIָ��
	ViewMatrixFunctions	*pAPI;
} ViewMatrix;

// API����
ViewMatrix* ViewMatrixInit(ViewMatrix*, Model*, HWND);

typedef void(*fnViewMatrixOnPaint)(ViewMatrix*, HDC hdc);
typedef void(*fnViewMatrixChangeColor)(ViewMatrix*, COLORREF);
typedef void(*fnViewMatrixSetRect)(ViewMatrix*, RECT*);
typedef void(*fnViewMatrixClose)(ViewMatrix*);

struct ViewMatrixFunctions
{
	fnViewMatrixOnPaint		OnPaint;
	fnViewMatrixChangeColor	ChangeColor;
	fnViewMatrixClose		Close;
	fnViewMatrixSetRect		SetRect;
};