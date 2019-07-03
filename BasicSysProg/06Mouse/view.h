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
    HPEN        hPenSelect;
    HBRUSH      hBrush;
    HBRUSH      hBrushBk;
    COLORREF    colorBk;
    Point       pointDragStart;
    int         nDragPoint;
    int         nHoverPoint;
    int         nRange;
    RECT        rcSelect;
    BOOL        bShowSelect;
    BOOL        selected[MAX_POINT_NUM];
    Point       pointMoving[MAX_POINT_NUM];
    Point       pointMoveTo;
    float       fTheta;
    float       fSpeed;
    int         nDuration; // ms
    LARGE_INTEGER tmMoveBegin;
    LARGE_INTEGER freq;
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
typedef void(*fnViewMoveToPoint)(View*, Point);
typedef void(*fnViewMoveSpeed)(View*, float);
typedef BOOL(*fnViewMoving)(View*);

struct tagViewFunctions
{
    fnViewOnPaint		OnPaint;
    fnViewClose			Close;
    fnViewDragStart     DragStart;
    fnViewDragEnd       DragEnd;
    fnViewDragging      Dragging;
    fnViewHover         Hover;
    fnViewMoveToPoint   MoveToPoint;
    fnViewMoving        Moving;
    fnViewMoveSpeed     MoveSpeed;
};