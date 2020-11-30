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
	����_ж������
	*/
	BOOL UnloadDriver(WCHAR* ServiceName);
	/*
	����_��������
	*/
	BOOL LoadDriver(LPCWSTR DriverSavePath, LPCWSTR ServiceName);
	/*
	����_��ȡ����Ȩ��
	*/
	BOOL EnableLoadDriverPrivilege(BOOL bEnable);
	HANDLE LinkDiver(const LPCTSTR szLinkName);
private:
	VOID DeleteKey(HKEY hkey);

	
};

class PORTDLLCLASS __declspec(dllexport) driverMem :public driver, public MemOry,public WenJian
{
public:

	//��ʼ����д����
	bool driverMem_InitialDriver(DWORD dwPid);
	//ж�ض�д����
	bool driverMem_DriverUnLoad();
	/*
	����_��ȡģ���ַ
	szModuName:ģ������
	nTyp��Ŀ�����ϵͳλ��32 /64
	*/
	DWORD64 driverMem_GetModuleAddeeBase(LPCSTR szModuName, int nTyp);
	/*
	����_��ȡ�����ڴ�����ָ��
	dwBaseAddess:�ڴ��ַ
	Is32_64��trueĿ����32λ���� false Ŀ����64
	IsTyp��Ĭ���Լ���ģʽ��ȡ ���������� false�������Ӷ�д�ٶ�
	����ֵ�����ض�ȡ���õ�ַ
	*/
	DWORD64  driverMem_ReadMemoryBaseAddess(DWORD64 dwBaseAddess, bool Is32_64=true, bool  IsTyp=true);
	/*
	����_��ȡ�����ڴ��ֽ�����
	dwBase���ڴ��ַ
	dwSize:��ȡ�����ֽ�
	lpBuf:��Ŷ�ȡ�����ֽ�����
	IsTyp��Ĭ���Լ���ģʽ��ȡ ���������� false�������Ӷ�д�ٶ�
	����ֵ:�ɹ�����false
	*/
	bool driverMem_ReadMemoryByte(DWORD64 dwBase, DWORD dwSize,OUT LPVOID lpBuf, bool  IsTyp = true);
	/*
	����_д�����ڴ�
	dwBase���ڴ��ַ
	dwSize:д������ֽ�
	lpBuf:д������ݵ�ַ
	IsTyp��Ĭ���Լ���ģʽ��ȡ ���������� false�������Ӷ�д�ٶ�
	����ֵ:�ɹ�����false
	*/
	bool driverMem_WriteMemory(DWORD64 dwBase, DWORD dwSize, LPVOID lpBuf,bool IsTyp = true);
	/*
	����_��������
	dwPid:����PID
	*/
	bool driverMem_KilledProcess(DWORD dwPid);
	/*
	����_�������� ��ֹ���̱����Ի����
	dwPid:��������PID
	Is:Ĭ��Ϊtrue ��ʼ���� falseֹͣ����
	*/
	bool driverMem_MyProtect(DWORD dwPid, bool Is = true);
public:
	DWORD m_dwPid;
	HANDLE hDevice;
	DWORD64 staRet;
};



