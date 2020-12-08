#pragma once
#include "hongdingyi.h"
//进程信息
typedef struct PROCDATA
{
	DWORD dwPid;
	WCHAR arrName[124];
}PROCESSDATA ,*PPROCESSDATA;

typedef struct PROCOBJECT
{
	DWORD dwPid;//进程PID
	WCHAR szName[MAX_PATH];//内核句柄标识
	WCHAR szTyp[MAX_PATH];//内核句柄类型
}PROCOBJECTDATA, *PPROCOBJECTDATA;

//详细进程信息
typedef struct PROCMODELE
{
	DWORD dwPid;//进程PID
	WCHAR MoledName[124];//模块名称
	WCHAR MoledPaht[MAX_PATH];//模块路径
	DWORD_PTR dwMoledBase;//模块基址
	DWORD_PTR dwMoledSize;//模块大小
}PROCESSMODELE, *PPROCESSMODELE;

class PORTDLLCLASS process :public XiTong
{
public:
	process();

	~process();
public:
	/*
	进程_ID取进程名
	nPid:进程pid
	返回值：返回进程名字
	*/
	std::wstring pro_GetProcesName(int nPid);
	/*
	进程_取启动参数
	返回值：返回进程启动参数
	*/
	std::wstring pro_GetStartCanShu();
	/*
	进程_取线程数
	nPid:进程的Pid
	返回值：返回进程的线程数量
	*/
	int pro_GetThreadNum(int nPid);
	/*
	进程_取自进程ID
	*/
	int pro_GetCurrPorcessId();
	/*
	进程_是否存在
	szProcName:进程名称
	bIs：是否区分进程名称大小写 默认不区分
	*/
	bool  pro_ProcessExist(LPCWSTR szProcName,bool bIs=false);
	/*
	进程_以管理员权限运行
	szPath：程序路径
	*/
	bool pro_RunAdminpro(LPCWSTR szPath);
	/*
	进程_获取进程快照列表
	proList：保存进程信息
	*/
	bool pro_GetProcesList(OUT vector<PROCESSDATA>& proList);
	/*
	进程_遍历进程模块信息
	dwPID:进程pid
	proessList:存放进程模块信息 (此函数只能遍历 相同位数得进程  32位获取32位 64位获取64位程序模块信息)
	*/
	bool pro_ListProcessModules(DWORD dwPID, OUT vector<PROCESSMODELE>& proessList);

	
	/*
	进程_获取进程中指定模块基址
	dwPID:进程pid
	szModuleName:模块名称 (此函数只能遍历 相同位数得进程  32位获取32位 64位获取64位程序模块信息)
	返回值：成功返回指定模块基址 失败返回0
	*/
	DWORD_PTR pro_GetProcessModuleBaseAddess(DWORD dwPid, LPCWSTR szModuleName);
	/*
	进程_进程创建或注入
	szProPath：进程路径
	szDllPath：dll路径可NULL默认不注入
	nTyp：注入方式 默认1 远程线程注入 2 APC投递注入
	*/
	DWORD pro_CreateProcessIniJect(LPCWSTR szProPath, LPCWSTR szDllPath=NULL, int nTyp=1);
	/*
	进程_遍历指定进程objectHandle
	dwPid:指定进程PID
	proObjectList：存放遍历到得信息得动态结构数组
	成功返回TRUE
	*/
	bool pro_ListObject(DWORD dwPid, OUT vector<PROCOBJECTDATA>& proObjectList);
	/*
	进程_关闭指定进程内核句柄
	dwPid:进程PID
	szName：句柄标识
	szTyp：句柄类型 
	*/
	bool pro_CloseHandel(DWORD dwPid, LPWSTR szName, LPWSTR szTyp);
	
private:
	//bool Iniject(LPCWSTR szModule, DWORD dwID);
	HANDLE  pro_ClossHandleEx(DWORD pid, HANDLE handle_source, DWORD flags);
	BOOL  pro_InjectDllByRemoteThread(ULONG32 ulTargetProcessID, const  WCHAR* wzDllFullPath);//远程线程
	bool pro_InjectDllWithApc(WCHAR* DllFullPath, ULONG ProcessId);//APC
};

