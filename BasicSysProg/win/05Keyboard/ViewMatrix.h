#pragma once
#include "model.h"

// ��ǰ����
typedef struct tagViewMatrixFunctions ViewMatrixFunctions;
typedef struct tagViewMatrixPoint ViewMatrixPoint;

// ��ͼ: ����һ���ڿ͵۹�������ͼ
typedef struct tagViewMatrix
{
	Model			*pModel;
	HWND			hWnd;
	HPEN			hPen;
	HBRUSH			brBack;
	HFONT			fontText;
	COLORREF		color;
	int				nPadding;
	RECT			rect;
	ViewMatrixPoint	*pPoints;
	// APIָ��
	ViewMatrixFunctions	*pAPI;
} ViewMatrix;

struct tagViewMatrixPoint
{
	int x;
	int y;
};

// API����
ViewMatrix* ViewMatrixInit(ViewMatrix*, Model*, HWND);

typedef void(*fnViewMatrixOnPaint)(ViewMatrix*, HDC hdc);
typedef void(*fnViewMatrixChangeColor)(ViewMatrix*, COLORREF);
typedef void(*fnViewMatrixSetRect)(ViewMatrix*, RECT*);
typedef void(*fnViewMatrixClose)(ViewMatrix*);

struct tagViewMatrixFunctions
{
	fnViewMatrixOnPaint		OnPaint;
	fnViewMatrixChangeColor	ChangeColor;
	fnViewMatrixClose		Close;
	fnViewMatrixSetRect		SetRect;
};