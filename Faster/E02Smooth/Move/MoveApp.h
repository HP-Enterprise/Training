#pragma once
#include "MainWnd.h"

class MoveApp : public App
{
public:
	MoveApp();
	virtual ~MoveApp();

	// ����Ϣѭ��
	int Run(PWSTR pCmdLine, int nCmdShow) override;
private:
	MainWnd m_wndMain;
};

