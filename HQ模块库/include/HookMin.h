#pragma once
#include "hongdingyi.h"
#ifdef _WIN64
#define XIP Rip
#else
#define XIP Eip
#endif


//lnline Hook
class PORTDLLCLASS HookMin
{
public:
	HookMin();
	~HookMin();
public:
	/*
	为指定的目标函数创建一个钩子
	lpOrgBase    [in]  一个指向Hook目标函数的指针（就是目标地址）
	lpJmpBase   [in]  指向自己回调函数的指针
	lpCarry [out] 一个指向蹦床函数的指针，它将是用于调用原始目标函数,这个参数可以是 NULL.
	bIs：是否立即执行HOOK 默认为true 立即执行 false为等待调用Hook_Start 才会执行hook
	返回值：成功返回true 失败返回false 并将置错误码 调用Hook_GetError获取失败原因
	*/
	bool Hook_Create(LPVOID lpOrgBase, LPVOID lpJmpBase, LPVOID* lpCarry = NULL, bool bIs = true);
	/*
	开始执行HOOK
	lpBase:一个指向Hook目标函数的指针（就是目标地址）
	返回值：成功返回true 失败返回false 并将置错误码 调用Hook_GetError获取失败原因
	*/
	bool Hook_Start(LPVOID lpBase);
	/*
	暂停执行HOOK(类似恢复hook)
	lpBase:一个指向Hook目标函数的指针（就是目标地址）
	返回值：成功返回true 失败返回false 并将置错误码 调用Hook_GetError获取失败原因
	*/
	bool Hook_Stop(LPVOID lpBase);
	/*
	获取最后一次错误得原因
	返回值：返回错误原因
	*/
	const char* Hook_GetError();
private:
	int m_nError;


};

//Veh Hook
class PORTDLLCLASS LeoHook {
public:
	LeoHook();
	~LeoHook();
public:
	/*
	vehHook
	og_fun：原始函数地址
	hk_fun：转向地址
	nInex：vehhook索引 0-3 详见下方说名
	说明：VEH_Hook 原理与硬件断点原理一样 最多只能同时HOOK 4个地址 也就是0-3得索引
	返回值：成功返回true 失败返回false
	*/
	static bool VEH_Hook(uintptr_t og_fun, uintptr_t hk_fun, int nInex);
	/*
	取消:vehHook
	nInex：对应vehhook得索引值 0-3
	返回值：成功返回true 失败返回false
	*/
	static bool VEH_Unhook(int nInex);

private:
	static uintptr_t og_fun1[4];
	static uintptr_t hk_fun1[4];
	static PVOID VEH_Handle1[4];
	static DWORD oldProtection1[4];

	static bool AreInSamePage(const uint8_t* Addr1, const uint8_t* Addr2);
	static LONG WINAPI LeoHandler(EXCEPTION_POINTERS *pExceptionInfo);
};
//com Hook
class PORTDLLCLASS ComHook
{
public:
	/*
	初始化COM HOOK 并打开COM组件
	szClsid：CoClass id字符串 比如 {XXXXXXX-XXXX-XXXX-XXXX-XXXXXX}
	szRiid:方法id字符串 比如 {XXXXXXX-XXXX-XXXX-XXXX-XXXXXX}
	*/
	ComHook(LPCWSTR szClsid, LPCWSTR szRiid);
	ComHook();
	~ComHook();
public:
	/*
	打开COM组件
	szClsid：CoClass id字符串 比如 {XXXXXXX-XXXX-XXXX-XXXX-XXXXXX}
	szRiid:方法id字符串 比如 {XXXXXXX-XXXX-XXXX-XXXX-XXXXXX}
	*/
	bool OpenCom(LPCWSTR szClsid, LPCWSTR szRiid);
	/*
	创建COMHOOK （推荐在合适的时机调用此函数）
	返回值：成功返回true 
	*/
	bool CreateComInitHook();
	/*
	COM函数拦截HOOK 
	pHookFunc：欲跳转的新的函数地址
	Index：COM组件方法索引从0开始
	pOldFunc：一个指向蹦床函数的指针，它将是用于调用原始目标函数 该函数不可以为NULL 恢复HOOK时需要填写此参数
	*******************************************************************
	备注：函数定义格式    
	DWORD_PTR WINAPI fun(LPVOID pthis,参数1，参数2，参数3 ,.....,OUT LPWSTR* szRet)
	pthis:第一个参数永远为this指针
	szRet：最后一个参数永远用作传出返回值
	中间写函数真正需要用到的参数 注意 如果有参数作为传出值要在原基础上加个*（此说明给基础较弱的人的提示）
	自定义的fun返回值 S_OK;
	pOldFunc：COM原函数定义也遵从上述 static DWORD_PTR(WINAPI*fun)(LPVOID pthis,参数1，参数2，参数3 ,.....,OUT LPWSTR* szRet);
	*/
	
	void Permit_Hook(IN PVOID pHookFunc, IN DWORD Index, OUT LPVOID* pOldFunc);
	/*
	恢复COMHOOK
	pHookFunc:就是对应Permit_Hook函数的最后一个参数
	Index：就是对应Permit_Hook函数的Index参数
	*/
	void Prohibit_Hook(IN LPVOID pHookFunc, IN DWORD Index);
private:
	CLSID m_clsid;
	IID m_iid;
	IUnknown * m_pUnknown = NULL;
	IDispatch * m_obj;
	HANDLE m_Hprocess = NULL;
};

//Hook Ip转向
class PORTDLLCLASS HookIpTo:public HookMin
{
public:
	bool Hook_HookWSAConnectToIp(char* szOrigIp, char* szToIp, short sProt);
};

