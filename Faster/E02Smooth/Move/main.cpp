#include "stdafx.h"
#include "MoveApp.h"

// Windows������ڵ�
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrev, _In_ LPWSTR pCmdLine, _In_ int nCmdShow)
{
	// ����MoveApp����
	MoveApp *pMoveApp = new MoveApp();

	// ִ�г����߼�
	if (!pMoveApp->Init(hInstance)) return GetLastError();
	int nRet = pMoveApp->Run(pCmdLine, nCmdShow);
	pMoveApp->UnInit();

	// ����MoveApp����

	// �˳�����
	return nRet;
}