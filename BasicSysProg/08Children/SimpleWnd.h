#pragma once

// ��ǰ����
typedef struct tagSimpleWndFunctions SimpleWndFunctions;

// �Ӵ���
typedef struct tagSimpleWnd
{
    HWND hwnd;
    // APIָ��
    SimpleWndFunctions	*pAPI;
} SimpleWnd;

// API����
SimpleWnd* SimpleWndInit(SimpleWnd*);

typedef void(*fnSimpleWndCreate)(SimpleWnd*, HWND, const RECT*, const wchar_t*);

struct tagSimpleWndFunctions
{
    wchar_t                 *pwszClsName;
    fnSimpleWndCreate       Create;
};