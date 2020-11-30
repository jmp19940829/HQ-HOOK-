#pragma once
#include "hongdingyi.h"
class  PORTDLLCLASS driver :
	public XiTongFuWu
{
public:
	driver();
	virtual ~driver();

public:
	/*
	驱动_卸载驱动
	*/
	BOOL UnloadDriver(WCHAR* ServiceName);
	/*
	驱动_加载驱动
	*/
	BOOL LoadDriver(LPCWSTR DriverSavePath, LPCWSTR ServiceName);
	/*
	驱动_获取驱动权限
	*/
	BOOL EnableLoadDriverPrivilege(BOOL bEnable);
	HANDLE LinkDiver(const LPCTSTR szLinkName);
private:
	VOID DeleteKey(HKEY hkey);

	
};

class PORTDLLCLASS __declspec(dllexport) driverMem :public driver, public MemOry,public WenJian
{
public:

	//初始化读写驱动
	bool driverMem_InitialDriver(DWORD dwPid);
	//卸载读写驱动
	bool driverMem_DriverUnLoad();
	/*
	驱动_获取模块地址
	szModuName:模块名称
	nTyp：目标进程系统位数32 /64
	*/
	DWORD64 driverMem_GetModuleAddeeBase(LPCSTR szModuName, int nTyp);
	/*
	驱动_读取进程内存整数指针
	dwBaseAddess:内存地址
	Is32_64：true目标是32位程序 false 目标是64
	IsTyp：默认以兼容模式读取 不容易蓝屏 false可以增加读写速度
	返回值：返回读取到得地址
	*/
	DWORD64  driverMem_ReadMemoryBaseAddess(DWORD64 dwBaseAddess, bool Is32_64=true, bool  IsTyp=true);
	/*
	驱动_读取进程内存字节数据
	dwBase：内存地址
	dwSize:读取多少字节
	lpBuf:存放读取到得字节数据
	IsTyp：默认以兼容模式读取 不容易蓝屏 false可以增加读写速度
	返回值:成功返回false
	*/
	bool driverMem_ReadMemoryByte(DWORD64 dwBase, DWORD dwSize,OUT LPVOID lpBuf, bool  IsTyp = true);
	/*
	驱动_写进程内存
	dwBase：内存地址
	dwSize:写入多少字节
	lpBuf:写入得数据地址
	IsTyp：默认以兼容模式读取 不容易蓝屏 false可以增加读写速度
	返回值:成功返回false
	*/
	bool driverMem_WriteMemory(DWORD64 dwBase, DWORD dwSize, LPVOID lpBuf,bool IsTyp = true);
	/*
	驱动_结束进程
	dwPid:进程PID
	*/
	bool driverMem_KilledProcess(DWORD dwPid);
	/*
	驱动_保护进程 防止进程被调试或结束
	dwPid:保护进程PID
	Is:默认为true 开始保护 false停止保护
	*/
	bool driverMem_MyProtect(DWORD dwPid, bool Is = true);
public:
	DWORD m_dwPid;
	HANDLE hDevice;
	DWORD64 staRet;
};



