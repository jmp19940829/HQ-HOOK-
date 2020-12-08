#pragma once
#include "hongdingyi.h"
class PORTDLLCLASS CSysCall
{
public:
	~CSysCall();
	CSysCall();
public:
	/*
	syscall 打开进程或线程 获取句柄
	dwhandle：存放获取到的句柄
	dwPid：进程PID
	dwRight：打开权限 默认PROCESS_ALL_ACCESS
	dwThid：线程ID 默认0
	返回值：成功返回TRUE 失败FALSE
	*/
	BOOL sysOpenProcess(OUT DWORD64& dwhandle, DWORD64 dwPid, DWORD64 dwRight= PROCESS_ALL_ACCESS, DWORD64 dwThid=0);
	/*
	syscall 修改指定进程内存属性
	dwhandle：目标进程句柄
	dwAddess：要修改得内存地址
	dwSize：修改多少字节
	*******************************************************************
	dwXin：要设置新得内存属性  具体如下
	请求保护方式：
	PAGE_READONLY 该区域为只读
	PAGE_READWRITE 区域可被应用程序读写
	PAGE_EXECUTE 区域包含可被系统执行的代码，试图读写该区域的操作将被拒绝，
	PAGE_EXECUTE_READ 区域包含可执行代码，应用程序可以读该区域
	PAGE_EXECUTE_READWRITE 区域包含可执行代码 应用系可以读写该区域
	**********************************************************************
	dwJiu：保存原来得旧得内存属性
	返回值：成功返回TRUE 失败FALSE
	*/
	BOOL sysVirtualProtectEx(DWORD64 dwhandle, DWORD64 dwAddess, DWORD64 dwSize, DWORD64 dwXin,OUT PDWORD64 dwJiu);
	/*
	syscall 读指定进程内存字节数据
	dwhandle：目标进程句柄
	dwAddessBase：要读取得内存地址
	byBuf：存放数据得指针
	dwSize：读取多少字节
	返回值：成功返回TRUE 失败FALSE
	*/
	BOOL sysReadProcessMemory(DWORD64 dwhandle, DWORD64 dwAddessBase,OUT LPVOID byBuf, DWORD64 dwSize);
	/*
	syscall 写指定进程内存字节数据
	dwhandle：目标进程句柄
	dwAddessBase：要写得内存地址
	byBuf：要写入得数据地址
	dwSize：写入多少字节
	返回值：成功返回TRUE 失败FALSE
	*/
	BOOL sysWriteProcessMemory(DWORD64 dwhandle, DWORD64 dwAddessBase,IN LPVOID byBuf, DWORD64 dwSize);
};
