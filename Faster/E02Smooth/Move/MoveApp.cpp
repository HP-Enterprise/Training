#include "stdafx.h"
#include "MoveApp.h"

MoveApp::MoveApp()
{
}

MoveApp::~MoveApp()
{
	
}

int MoveApp::Run(PWSTR pCmdLine, int nCmdShow)
{
	// ����������
	m_wndMain.Create();

	// ������Ϣѭ��
	int nRet = App::Run(pCmdLine, nCmdShow);

	return nRet;
}
