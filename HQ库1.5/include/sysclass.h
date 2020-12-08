#pragma once
#include "hongdingyi.h"
class PORTDLLCLASS CSysCall
{
public:
	~CSysCall();
	CSysCall();
public:
	/*
	syscall �򿪽��̻��߳� ��ȡ���
	dwhandle����Ż�ȡ���ľ��
	dwPid������PID
	dwRight����Ȩ�� Ĭ��PROCESS_ALL_ACCESS
	dwThid���߳�ID Ĭ��0
	����ֵ���ɹ�����TRUE ʧ��FALSE
	*/
	BOOL sysOpenProcess(OUT DWORD64& dwhandle, DWORD64 dwPid, DWORD64 dwRight= PROCESS_ALL_ACCESS, DWORD64 dwThid=0);
	/*
	syscall �޸�ָ�������ڴ�����
	dwhandle��Ŀ����̾��
	dwAddess��Ҫ�޸ĵ��ڴ��ַ
	dwSize���޸Ķ����ֽ�
	*******************************************************************
	dwXin��Ҫ�����µ��ڴ�����  ��������
	���󱣻���ʽ��
	PAGE_READONLY ������Ϊֻ��
	PAGE_READWRITE ����ɱ�Ӧ�ó����д
	PAGE_EXECUTE ��������ɱ�ϵͳִ�еĴ��룬��ͼ��д������Ĳ��������ܾ���
	PAGE_EXECUTE_READ ���������ִ�д��룬Ӧ�ó�����Զ�������
	PAGE_EXECUTE_READWRITE ���������ִ�д��� Ӧ��ϵ���Զ�д������
	**********************************************************************
	dwJiu������ԭ���þɵ��ڴ�����
	����ֵ���ɹ�����TRUE ʧ��FALSE
	*/
	BOOL sysVirtualProtectEx(DWORD64 dwhandle, DWORD64 dwAddess, DWORD64 dwSize, DWORD64 dwXin,OUT PDWORD64 dwJiu);
	/*
	syscall ��ָ�������ڴ��ֽ�����
	dwhandle��Ŀ����̾��
	dwAddessBase��Ҫ��ȡ���ڴ��ַ
	byBuf��������ݵ�ָ��
	dwSize����ȡ�����ֽ�
	����ֵ���ɹ�����TRUE ʧ��FALSE
	*/
	BOOL sysReadProcessMemory(DWORD64 dwhandle, DWORD64 dwAddessBase,OUT LPVOID byBuf, DWORD64 dwSize);
	/*
	syscall дָ�������ڴ��ֽ�����
	dwhandle��Ŀ����̾��
	dwAddessBase��Ҫд���ڴ��ַ
	byBuf��Ҫд������ݵ�ַ
	dwSize��д������ֽ�
	����ֵ���ɹ�����TRUE ʧ��FALSE
	*/
	BOOL sysWriteProcessMemory(DWORD64 dwhandle, DWORD64 dwAddessBase,IN LPVOID byBuf, DWORD64 dwSize);
};
