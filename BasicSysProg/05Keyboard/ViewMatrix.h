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
	HFONT			fontTexts[8];
	COLORREF		color;
	int				nPadding;
	RECT			rect;
	int				nMaxX;
	int				nMaxZ;
	ViewMatrixPoint	*pPoints;
	// APIָ��
	ViewMatrixFunctions	*pAPI;
} ViewMatrix;

struct tagViewMatrixPoint
{
	int		x;
	int		y;
	int		z;
	int		nCharPos;
	float	fSpeed; // pixels/s
	int		nShadow;
	DWORD	dwTick; // ms
	DWORD	dwCharTick;
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