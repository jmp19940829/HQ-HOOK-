#pragma once
#include "hongdingyi.h"
class PORTDLLCLASS XiTongFuWu :public XiTong
{
public:
	XiTongFuWu();
	virtual ~XiTongFuWu();

public:
	/*
	��װ���� ����һ��ϵͳ������
	szSerName:�������� "ϵͳ�������ݿ���ID����,����Ϊ����"
	szShowName����ʾ����
	szPath��ִ���ļ�
	szText:�������� ��NULL
	bIs���������潻�� Ĭ��false
	nServTyp:�������� Ĭ��16  1���ں����� 2���ļ�ϵͳ���� 16������ 32����������
	nQiTyp���������� Ĭ��3    2���Զ� 3���ֶ� 4������
	szYicunGuanxi�������ϵ Ĭ���� 
	szUser:��¼�û� Ĭ����
	szPass:��¼���� Ĭ����
	����ֵ���ɹ�����true ʧ�ܷ��� false
	*/
	bool FuWu_AnZhuangFuwu(LPCWSTR szSerName, LPCTSTR szShowName, LPCWSTR szPath, LPCWSTR szText = L"", bool bIs=false, int nServTyp=16, int nQiTyp=3, LPCWSTR szYicunGuanxi = L"", LPCWSTR szUser =L"", LPCWSTR szPass = L"");
	/*
	�÷������� �޸�ָ��ϵͳ��������
	szName:����������
	szText:�µķ���������
	����ֵ;�ɹ�����true ����false
	*/
	bool FuWu_SetMiaoshu(LPCWSTR szName, LPCWSTR szText);
	/*
	�ָ�����
	�ָ�����ͣ��ϵͳ����
	szName:������
	����ֵ;�ɹ�����true ����false
	*/
	bool FuWu_HuiFu(LPCWSTR szName);
	/*
	��ʼ����
	����һ��ϵͳ����
	szName:������
	����ֵ;�ɹ�����true ����false
	*/
	virtual  bool FuWu_KaiQiFuwu(LPCWSTR szName);
	/*
	ȡ��������
	szName:������
	1���豸����
	2���ļ�ϵͳ����
	16������
	32���Լ����̻���������
	256����������
	*/
	int FuWu_QuFuWuleixing(LPCWSTR szName);
	/*
	ȡ��������
	szName:������
	����ֵ���ɹ����ط��������ı�
	*/
	LPCWSTR FuWu_QuFuwuMiaoshu(LPCWSTR szName);
	/*
	ȡ��������
	szName:��ʾ����
	����ֵ���ɹ����ط��������ı�
	*/
	LPCWSTR FuWu_QuFuwuName(LPCWSTR szName);
	/*
	ȡ����״̬
	szName:������
	����ֵ������״̬
	1����ֹͣ 2����ʼ 3��ֹͣ 4���������� 5���������� 6����ͣ���� 7����ͣ
	*/
	int FuWu_QuFuwuZhuangTai(LPCWSTR szName);
	/*
	ȡ��ʾ���� ����ϵͳ�������ݿ����ƻ�ȡ��ʾ����
	szName:������
	����ֵ�����ط�����ʾ����
	*/
	LPCWSTR FuWu_QuXianShiName(LPCWSTR szName);
	/*
	�����Ƿ����
	szName:������
	*/
	bool FuWu_IsServer(LPCWSTR szName);
	/*
	ֹͣ���� ֹͣһ���������е�ϵͳ����
	szName:������
	*/
	bool FuWu_TingZhi(LPCWSTR szName);
	/*
	ж�ط��� ������������˶�����ֹͣ����Ȼ����ɾ��
	szName:������
	*/
	bool FuWu_XieZai(LPCWSTR szName);
	/*
	��ͣ���� ��ͣһ���������е�ϵͳ����
	szName:������
	*/
	bool FuWu_ZanTingStop(LPCWSTR szName);
private:
	std::wstring m_strDescription;
	std::wstring m_strServerName;
};

