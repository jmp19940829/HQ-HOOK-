#pragma once
#include "hongdingyi.h"
//������Ϣ
typedef struct PROCDATA
{
	DWORD dwPid;
	WCHAR arrName[124];
}PROCESSDATA ,*PPROCESSDATA;

typedef struct PROCOBJECT
{
	DWORD dwPid;//����PID
	WCHAR szName[MAX_PATH];//�ں˾����ʶ
	WCHAR szTyp[MAX_PATH];//�ں˾������
}PROCOBJECTDATA, *PPROCOBJECTDATA;

//��ϸ������Ϣ
typedef struct PROCMODELE
{
	DWORD dwPid;//����PID
	WCHAR MoledName[124];//ģ������
	WCHAR MoledPaht[MAX_PATH];//ģ��·��
	DWORD_PTR dwMoledBase;//ģ���ַ
	DWORD_PTR dwMoledSize;//ģ���С
}PROCESSMODELE, *PPROCESSMODELE;

class PORTDLLCLASS process :public XiTong
{
public:
	process();

	~process();
public:
	/*
	����_IDȡ������
	nPid:����pid
	����ֵ�����ؽ�������
	*/
	std::wstring pro_GetProcesName(int nPid);
	/*
	����_ȡ��������
	����ֵ�����ؽ�����������
	*/
	std::wstring pro_GetStartCanShu();
	/*
	����_ȡ�߳���
	nPid:���̵�Pid
	����ֵ�����ؽ��̵��߳�����
	*/
	int pro_GetThreadNum(int nPid);
	/*
	����_ȡ�Խ���ID
	*/
	int pro_GetCurrPorcessId();
	/*
	����_�Ƿ����
	szProcName:��������
	bIs���Ƿ����ֽ������ƴ�Сд Ĭ�ϲ�����
	*/
	bool  pro_ProcessExist(LPCWSTR szProcName,bool bIs=false);
	/*
	����_�Թ���ԱȨ������
	szPath������·��
	*/
	bool pro_RunAdminpro(LPCWSTR szPath);
	/*
	����_��ȡ���̿����б�
	proList�����������Ϣ
	*/
	bool pro_GetProcesList(OUT vector<PROCESSDATA>& proList);
	/*
	����_��������ģ����Ϣ
	dwPID:����pid
	proessList:��Ž���ģ����Ϣ (�˺���ֻ�ܱ��� ��ͬλ���ý���  32λ��ȡ32λ 64λ��ȡ64λ����ģ����Ϣ)
	*/
	bool pro_ListProcessModules(DWORD dwPID, OUT vector<PROCESSMODELE>& proessList);

	
	/*
	����_��ȡ������ָ��ģ���ַ
	dwPID:����pid
	szModuleName:ģ������ (�˺���ֻ�ܱ��� ��ͬλ���ý���  32λ��ȡ32λ 64λ��ȡ64λ����ģ����Ϣ)
	����ֵ���ɹ�����ָ��ģ���ַ ʧ�ܷ���0
	*/
	DWORD_PTR pro_GetProcessModuleBaseAddess(DWORD dwPid, LPCWSTR szModuleName);
	/*
	����_���̴�����ע��
	szProPath������·��
	szDllPath��dll·����NULLĬ�ϲ�ע��
	nTyp��ע�뷽ʽ Ĭ��1 Զ���߳�ע�� 2 APCͶ��ע��
	*/
	DWORD pro_CreateProcessIniJect(LPCWSTR szProPath, LPCWSTR szDllPath=NULL, int nTyp=1);
	/*
	����_����ָ������objectHandle
	dwPid:ָ������PID
	proObjectList����ű���������Ϣ�ö�̬�ṹ����
	�ɹ�����TRUE
	*/
	bool pro_ListObject(DWORD dwPid, OUT vector<PROCOBJECTDATA>& proObjectList);
	/*
	����_�ر�ָ�������ں˾��
	dwPid:����PID
	szName�������ʶ
	szTyp��������� 
	*/
	bool pro_CloseHandel(DWORD dwPid, LPWSTR szName, LPWSTR szTyp);
	
private:
	//bool Iniject(LPCWSTR szModule, DWORD dwID);
	HANDLE  pro_ClossHandleEx(DWORD pid, HANDLE handle_source, DWORD flags);
	BOOL  pro_InjectDllByRemoteThread(ULONG32 ulTargetProcessID, const  WCHAR* wzDllFullPath);//Զ���߳�
	bool pro_InjectDllWithApc(WCHAR* DllFullPath, ULONG ProcessId);//APC
};

