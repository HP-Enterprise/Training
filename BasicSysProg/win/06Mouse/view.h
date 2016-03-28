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
    Point       pointDragStart;
    int         nDragPoint;
    int         nHoverPoint;
    int         nRange;
    // APIָ��
    ViewFunctions	*pAPI;
} View;

// API����
View* ViewInit(View*, Model*, HWND);

typedef void(*fnViewOnPaint)(View*, HDC hdc);
typedef void(*fnViewClose)(View*);
typedef void(*fnViewDragStart)(View*, Point);
typedef BOOL(*fnViewDragEnd)(View*, Point);
typedef void(*fnViewDragging)(View*, Point);
typedef void(*fnViewHover)(View*, Point);

struct tagViewFunctions
{
    fnViewOnPaint		OnPaint;
    fnViewClose			Close;
    fnViewDragStart     DragStart;
    fnViewDragEnd       DragEnd;
    fnViewDragging      Dragging;
    fnViewHover         Hover;
};