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
    // APIָ��
    ViewFunctions	*pAPI;
} View;

// API����
View* ViewInit(View*, Model*, HWND);

typedef void(*fnViewOnPaint)(View*, HDC hdc);
typedef void(*fnViewClose)(View*);

struct tagViewFunctions
{
    fnViewOnPaint		OnPaint;
    fnViewClose			Close;
};