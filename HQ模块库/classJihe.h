#pragma once

#include <windows.h>
#include <iostream>
#include "include/include.h"
#include "include/XiTong.h"
#include "include/XiTongFuWu.h"
#include "include/JiHe.h"
#include "include/process.h"
#include "include/MemOry.h"
#include "include/driver.h"
#include "include/ntdll.h"
#include"include/Log.h"
#include "include/HookMin.h"
#include "include/MinTcp.h"
#include "include/huibian.h"
#include "include/code.h"
#include "include/Thread.h"
/***************************************************************************************************/
/*
	���ߣ�������Ů����
	QQ��2865298812
	���������ڣ�2020-11-28
	�汾:v1.2
	˵������̬���̬����Ѱ�ֻ֧��32λ����  ������֧��X64
*/
/***************************************************************************************************/




#define APPCHENGXU_HUANYUAN_ANZHUANG 1 
#define APPCHENGXU_HUANYUAN_XIEZAI 2
#define DRIVER_HUANYUAN_ANZHUANG 3
#define WINDOW_HUANYUAN 4
/*
ȫ�ֺ���_���ֽ�ת���ֽ�
*/
__declspec(dllexport)std::wstring atow(char* str);
/*
ȫ�ֺ���_���ֽ�ת���ֽ�
*/
__declspec(dllexport)std::string  wtoa(WCHAR* str);
/*
ȫ�ֺ���_��ʵ��GetProcAddress ��GetProcAddress������ͬ
*/
__declspec(dllexport)ULONG_PTR MyGetProcAddress(
	HMODULE hModule,    // handle to DLL module  
	LPCSTR lpProcName   // function name  
);
/*
ȫ�ֺ���_��ȡ��Դ�ڴ��ַ����
szRcName����Դ����
dwRcId:��Դid
dwSize:������Դ��С
szName����Դ�����ļ� �����EXE ����NULL ��DLL��дDLL����
�ɹ�����:��Դ�����ڴ���׵�ַ
*/
__declspec(dllexport)LPVOID GetResou(LPWSTR szRcName, DWORD dwRcId, OUT DWORD* dwSize, LPWSTR szName = NULL);
