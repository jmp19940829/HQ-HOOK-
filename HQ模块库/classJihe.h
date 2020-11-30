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
	作者：亿万少女的梦
	QQ：2865298812
	最后更新日期：2020-11-28
	版本:v1.2
	说明：静态库或动态库免费版只支持32位编译  赞助版支持X64
*/
/***************************************************************************************************/




#define APPCHENGXU_HUANYUAN_ANZHUANG 1 
#define APPCHENGXU_HUANYUAN_XIEZAI 2
#define DRIVER_HUANYUAN_ANZHUANG 3
#define WINDOW_HUANYUAN 4
/*
全局函数_多字节转宽字节
*/
__declspec(dllexport)std::wstring atow(char* str);
/*
全局函数_宽字节转载字节
*/
__declspec(dllexport)std::string  wtoa(WCHAR* str);
/*
全局函数_自实现GetProcAddress 与GetProcAddress功能相同
*/
__declspec(dllexport)ULONG_PTR MyGetProcAddress(
	HMODULE hModule,    // handle to DLL module  
	LPCSTR lpProcName   // function name  
);
/*
全局函数_获取资源内存地址数据
szRcName：资源名称
dwRcId:资源id
dwSize:返回资源大小
szName：资源所属文件 如果是EXE 就留NULL 是DLL填写DLL名字
成功返回:资源所在内存的首地址
*/
__declspec(dllexport)LPVOID GetResou(LPWSTR szRcName, DWORD dwRcId, OUT DWORD* dwSize, LPWSTR szName = NULL);
