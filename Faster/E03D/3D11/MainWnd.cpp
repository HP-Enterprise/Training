#include "stdafx.h"
#include "resource.h"
#include "MainWnd11.h"

MainWnd::MainWnd()
{
}

MainWnd::~MainWnd()
{
}

ATOM MainWnd::Register()
{
	// ����������ע��,�����˻��෽��
	WNDCLASS wcls;
	ZeroMemory(&wcls, sizeof(WNDCLASS));
	wcls.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcls.lpfnWndProc = XWnd::WindowProc;
	wcls.hInstance = m_hInst;
	wcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcls.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICON_APP)); // ͼ��
	wcls.lpszClassName = m_wstrClsName.c_str();

	return RegisterClass(&wcls);
}

BOOL MainWnd::Create()
{
	// ���ڳߴ��λ��
	int cxScreen = GetSystemMetrics(SM_CXSCREEN);
	int cyScreen = GetSystemMetrics(SM_CYSCREEN);
	int width = cxScreen > 800 ? 800 : cxScreen;
	int height = cyScreen > 600 ? 600 : cyScreen;

	WNDCLASS cls;
	if (!GetClassInfo(m_hInst, m_wstrClsName.c_str(), &cls)) Register();

	// ��������
	wstring wstrTitle(L"3D");
	m_hwnd = CreateWindow(m_wstrClsName.c_str(), wstrTitle.c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		(cxScreen - width) / 2, (cyScreen - height) / 2, width, height,
		NULL, NULL, m_hInst, this);
	if (!m_hwnd) return FALSE;

	// ��һ��ˢ�´���
	UpdateWindow(m_hwnd);

	return TRUE;
}

LRESULT MainWnd::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// ��Ϣ����
	switch (uMsg) {
		HANDLE_MSG(hWnd, WM_ERASEBKGND, OnEraseBkgnd);
		break;
	default:
		return XWnd::WndProc(hWnd, uMsg, wParam, lParam);
	}
}

BOOL MainWnd::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
	__super::OnCreate(hwnd, lpCreateStruct);


	return TRUE;
}

void MainWnd::OnDestroy(HWND hwnd)
{
	__super::OnDestroy(hwnd);

	PostQuitMessage(0);
}

void MainWnd::OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);
	EndPaint(hwnd, &ps);
}

BOOL MainWnd::OnEraseBkgnd(HWND hwnd, HDC hdc)
{
	return FALSE;
}