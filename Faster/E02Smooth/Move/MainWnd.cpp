#include "stdafx.h"
#include "resource.h"
#include "MainWnd.h"

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
	wcls.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICONAPP)); // ͼ��
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
	wstring wstrTitle(L"Move");
	m_hwnd = CreateWindow(m_wstrClsName.c_str(), wstrTitle.c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		(cxScreen - width) / 2, (cyScreen - height) / 2, width, height,
		NULL, NULL, m_hInst, this);
	if (!m_hwnd) {
		MessageBox(NULL, L"Create window failed", L"Error", MB_OK);
		return FALSE;
	}

	// ��һ��ˢ�´���
	UpdateWindow(m_hwnd);

	return TRUE;
}

LRESULT MainWnd::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// ��Ϣ����
	switch (uMsg) {
		HANDLE_MSG(hWnd, WM_KEYDOWN, OnKeyDown);
		break;
	case WM_CAR_MOVING:
		return OnCarMoving(hWnd, uMsg, wParam, lParam);
	default:
		return XWnd::WndProc(hWnd, uMsg, wParam, lParam);
	}
}

BOOL MainWnd::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
	__super::OnCreate(hwnd, lpCreateStruct);

	m_hDotPen = CreatePen(PS_DOT, 0, RGB(0xff, 0x00, 0x00));
	m_hbrCar = CreateSolidBrush(RGB(0x33, 0x33, 0xcc));
	return TRUE;
}

void MainWnd::OnDestroy(HWND hwnd)
{
	DeletePen(m_hDotPen);
	DeleteBrush(m_hbrCar);
	__super::OnDestroy(hwnd);
}

void MainWnd::OnPaint(HWND hwnd)
{
	// ��ȡ����ʾ���߶�(������Ϊ��λ)
	int pixelsInHeight = GetSystemMetrics(SM_CYSCREEN);
	int pixels = static_cast<int>(pixelsInHeight * 0.9f);
	// ��ȡ���ڳߴ�(����ʾ���豸����Ϊ��λ)
	RECT rc;
	GetClientRect(hwnd, &rc);

	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	// �趨����ϵͳ
	SetMapMode(hdc, MM_ISOTROPIC);
	SetWindowExtEx(hdc, 100000, 100000, NULL); // ��׼�����ж��
	SetViewportExtEx(hdc, pixels, -pixels, NULL); // ����ʾ���豸�ϵĶ�������չʾ��׼����
	SetViewportOrgEx(hdc, rc.right / 2, rc.bottom / 2, NULL); // ��׼�����(0,0)��Դ������Ͻ���ʲôλ��(����ʾ���豸����Ϊ��λ)

	// ��׼����߽�
	Rectangle(hdc, -50000, -50000, 50000, 50000);

	// ������
	SelectPen(hdc, m_hDotPen);
	MoveToEx(hdc, -50000, 0, NULL);
	LineTo(hdc, +50000, 0);
	MoveToEx(hdc, 0, -50000, NULL);
	LineTo(hdc, 0, +50000);

	// ����
	RECT rcCar;
	FLOAT2 pos = m_car.GetPos();
	FLOAT2 size = m_car.GetSize();
	rcCar.left = static_cast<int>(1000.0f * (pos.x - size.x / 2.0f));
	rcCar.right = static_cast<int>(1000.0f * (pos.x + size.x / 2.0f));
	rcCar.top = static_cast<int>(1000.0f * (pos.y + size.y / 2.0f));
	rcCar.bottom = static_cast<int>(1000.0f * (pos.y - size.y / 2.0f));
	FillRect(hdc, &rcCar, m_hbrCar);

	EndPaint(hwnd, &ps);

	// �����ƶ�
	PostMessage(hwnd, WM_CAR_MOVING, 0, 0);
}

void MainWnd::OnKeyDown(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	switch (vk)
	{
	case VK_UP:
	case VK_DOWN:
	case VK_LEFT:
	case VK_RIGHT:
		PostMessage(hwnd, WM_CAR_MOVING, 0, 0);
		break;
	default:
		break;
	}
}

LRESULT MainWnd::OnCarMoving(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// ����
	float fSpeed = 0.01f;
	// ����
	int iX = (GetKeyState(VK_RIGHT) >> 8 & 0x01) - (GetKeyState(VK_LEFT) >> 8 & 0x01);
	int iY = (GetKeyState(VK_UP) >> 8 & 0x01) - (GetKeyState(VK_DOWN) >> 8 & 0x01);

	// ����λ��
	float fDeltaX = fSpeed * iX;
	float fDeltaY = fSpeed * iY;

	// �����Ҫ�ƶ�����
	if (iX != 0 || iY != 0) {
		m_car.Move(fDeltaX, fDeltaY);
		InvalidateRect(hwnd, NULL, TRUE);
	}

	return 0L;
}
