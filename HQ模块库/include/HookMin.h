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
	Ϊָ����Ŀ�꺯������һ������
	lpOrgBase    [in]  һ��ָ��HookĿ�꺯����ָ�루����Ŀ���ַ��
	lpJmpBase   [in]  ָ���Լ��ص�������ָ��
	lpCarry [out] һ��ָ��Ĵ�������ָ�룬���������ڵ���ԭʼĿ�꺯��,������������� NULL.
	bIs���Ƿ�����ִ��HOOK Ĭ��Ϊtrue ����ִ�� falseΪ�ȴ�����Hook_Start �Ż�ִ��hook
	����ֵ���ɹ�����true ʧ�ܷ���false �����ô����� ����Hook_GetError��ȡʧ��ԭ��
	*/
	bool Hook_Create(LPVOID lpOrgBase, LPVOID lpJmpBase, LPVOID* lpCarry = NULL, bool bIs = true);
	/*
	��ʼִ��HOOK
	lpBase:һ��ָ��HookĿ�꺯����ָ�루����Ŀ���ַ��
	����ֵ���ɹ�����true ʧ�ܷ���false �����ô����� ����Hook_GetError��ȡʧ��ԭ��
	*/
	bool Hook_Start(LPVOID lpBase);
	/*
	��ִͣ��HOOK(���ƻָ�hook)
	lpBase:һ��ָ��HookĿ�꺯����ָ�루����Ŀ���ַ��
	����ֵ���ɹ�����true ʧ�ܷ���false �����ô����� ����Hook_GetError��ȡʧ��ԭ��
	*/
	bool Hook_Stop(LPVOID lpBase);
	/*
	��ȡ���һ�δ����ԭ��
	����ֵ�����ش���ԭ��
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
	og_fun��ԭʼ������ַ
	hk_fun��ת���ַ
	nInex��vehhook���� 0-3 ����·�˵��
	˵����VEH_Hook ԭ����Ӳ���ϵ�ԭ��һ�� ���ֻ��ͬʱHOOK 4����ַ Ҳ����0-3������
	����ֵ���ɹ�����true ʧ�ܷ���false
	*/
	static bool VEH_Hook(uintptr_t og_fun, uintptr_t hk_fun, int nInex);
	/*
	ȡ��:vehHook
	nInex����Ӧvehhook������ֵ 0-3
	����ֵ���ɹ�����true ʧ�ܷ���false
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
	��ʼ��COM HOOK ����COM���
	szClsid��CoClass id�ַ��� ���� {XXXXXXX-XXXX-XXXX-XXXX-XXXXXX}
	szRiid:����id�ַ��� ���� {XXXXXXX-XXXX-XXXX-XXXX-XXXXXX}
	*/
	ComHook(LPCWSTR szClsid, LPCWSTR szRiid);
	ComHook();
	~ComHook();
public:
	/*
	��COM���
	szClsid��CoClass id�ַ��� ���� {XXXXXXX-XXXX-XXXX-XXXX-XXXXXX}
	szRiid:����id�ַ��� ���� {XXXXXXX-XXXX-XXXX-XXXX-XXXXXX}
	*/
	bool OpenCom(LPCWSTR szClsid, LPCWSTR szRiid);
	/*
	����COMHOOK ���Ƽ��ں��ʵ�ʱ�����ô˺�����
	����ֵ���ɹ�����true 
	*/
	bool CreateComInitHook();
	/*
	COM��������HOOK 
	pHookFunc������ת���µĺ�����ַ
	Index��COM�������������0��ʼ
	pOldFunc��һ��ָ��Ĵ�������ָ�룬���������ڵ���ԭʼĿ�꺯�� �ú���������ΪNULL �ָ�HOOKʱ��Ҫ��д�˲���
	*******************************************************************
	��ע�����������ʽ    
	DWORD_PTR WINAPI fun(LPVOID pthis,����1������2������3 ,.....,OUT LPWSTR* szRet)
	pthis:��һ��������ԶΪthisָ��
	szRet�����һ��������Զ������������ֵ
	�м�д����������Ҫ�õ��Ĳ��� ע�� ����в�����Ϊ����ֵҪ��ԭ�����ϼӸ�*����˵���������������˵���ʾ��
	�Զ����fun����ֵ S_OK;
	pOldFunc��COMԭ��������Ҳ������� static DWORD_PTR(WINAPI*fun)(LPVOID pthis,����1������2������3 ,.....,OUT LPWSTR* szRet);
	*/
	
	void Permit_Hook(IN PVOID pHookFunc, IN DWORD Index, OUT LPVOID* pOldFunc);
	/*
	�ָ�COMHOOK
	pHookFunc:���Ƕ�ӦPermit_Hook���������һ������
	Index�����Ƕ�ӦPermit_Hook������Index����
	*/
	void Prohibit_Hook(IN LPVOID pHookFunc, IN DWORD Index);
private:
	CLSID m_clsid;
	IID m_iid;
	IUnknown * m_pUnknown = NULL;
	IDispatch * m_obj;
	HANDLE m_Hprocess = NULL;
};

//Hook Ipת��
class PORTDLLCLASS HookIpTo:public HookMin
{
public:
	bool Hook_HookWSAConnectToIp(char* szOrigIp, char* szToIp, short sProt);
};

