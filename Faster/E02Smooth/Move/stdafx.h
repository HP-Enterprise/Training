// Ԥ����ͷ�ļ�,�����仯��ϵͳͷ�ļ����з�������
#pragma once

#include <assert.h>
#include <string>

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <windowsx.h>

#include "..\\XWndLib\\XWndLib.h"
// $(Configuration)
#ifdef _DEBUG
	#pragma comment(lib, "..\\x64\\Debug\\XWndLib.lib")
#else
	#pragma comment(lib, "..\\x64\\Release\\XWndLib.lib")
#endif // _DEBUG