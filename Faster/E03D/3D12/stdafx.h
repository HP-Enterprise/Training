// Ԥ����ͷ�ļ�,�����仯��ϵͳͷ�ļ����з�������
#pragma once

#include <assert.h>
#include <string>
#include <vector>

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <windowsx.h>
#include <wrl.h>
#include <dxgi1_6.h>
#pragma comment(lib, "dxgi.lib")
#include <d3d12.h>
#pragma comment(lib, "d3d12.lib")
#include <DirectXColors.h>

// $(Configuration)
#ifdef _DEBUG
	#include "..\\x64\\Debug\\XWndLib.h"
#else
	#include "..\\x64\\Release\\XWndLib.h"
#endif // _DEBUG