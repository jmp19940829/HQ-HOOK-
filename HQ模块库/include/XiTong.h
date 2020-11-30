#pragma once
#include "hongdingyi.h"
//��Ļ�ֱ�����Ϣ
struct strPingMuFenBianlv
{
	int nSeShen;//ɫ��
	int nWide;//��
	int nHigh;//��
	int nHz;//ˢ����hz
};
class PORTDLLCLASS XiTong
{
public:

	XiTong();
	virtual ~XiTong();

public:
	/*
	��ʱת�ÿ���Ȩ���Ա��� Windows ����ϵͳ�л��ᴦ�����������û����̻����������¼���
	ֱ������ϵͳ�����������������е������¼�������Ż᷵�ء�
	*/
	void XiTong_ChuLiShiJian();
	/*
	��ȡϵͳ����ʱ��
	���ص�λΪ����
	*/
	int XiTong_GetKongXianshijian();
	/*
	ϵͳ_������ԭ��
	������szData
	����:nTyp
	APPCHENGXU_HUANYUAN_ANZHUANG ����װ
	APPCHENGXU_HUANYUAN_XIEZAI ����ж��
	DRIVER_HUANYUAN_ANZHUANG  ������װ
	WINDOW_HUANYUAN ϵͳ
	����ֵ���ɹ� ����ϵͳ��ԭID ʧ��<0
	*/
	DWORD XiTong_CreateHuanyuanDian(LPWSTR szData, int nTyp);
	/*
	ϵͳ_ɾ����ԭ��
	dwId����ԭ��ID
	*/
	bool XiTong_DeleteHuanyuanDian(DWORD dwId);
	/*
	�̷�:szData
	���ָ���ľ��Ƿ�֧��ϡ���ļ�
	*/
	bool XiTong_CiPanIsXishuWenjian(LPWSTR szData);
	/*
	szNmae:������������ ����"%TEMP%"
	��ȡ��������
	����ֵ:�ɹ�������ȡ�õ�ֵ
	*/
	LPCWSTR XiTong_ReadHuanjingBianliang(LPWSTR szName);
	/*
	ϵͳ_�ػ�
	*/
	bool XiTong_Guanji();
	/*
	ϵͳ_����
	*/
	bool XiTong_ChongQi();
	/*
	ϵͳ_ע��
	*/
	bool XiTong_ZhuXiao();
	/*
	ϵͳ_ǿ�ƹػ�
	*/
	bool XiTong_GuanjiEx();
	/*
	ϵͳ_ǿ������
	*/
	bool XiTong_ChongQiEx();
	/*
	ϵͳ_ǿ��ע��
	*/
	bool XiTong_ZhuXiaoEx();
	/*
	ϵͳ_��Ȩ
	*/
	bool XiTong_TiShengQuanXian();

	/*
	 bIs���Ƿ���������
	*/
	bool XiTong_XiuMianguanli(bool bIs);
	/*
		ϵͳ_�ָ�����
	*/
	bool XiTong_HuiFuPingBao();
	/*
	ϵͳ_��������
	*/
	bool XiTong_JinZhiPingBao();
	/*
	ϵͳ_�������״̬
	*/
	bool XiTong_JinRuDaiji();
	/*
	ϵͳ_����DPI����
	*/
	bool XiTong_JinYongDPIsuofang();
	/*
	��ʱ���尲װ��ж��
	szNmae:����·��
	bIs:true ��װ false ж��
	*/
	DWORD XiTong_TempAnZhuangZiTi(LPWSTR szNmae,bool bIs);

	/*
	ϵͳ_�ж���������ͷ
	����ֵ����������ͷ����
	*/
	int XiTong_IsYouWuSheXiangtou();
	/*
	ϵͳ_��ջ���վ
	*/
	bool XiTong_QingKongHuiShouZhan();
	/*
	�ж��Ƿ�Ϊ64λϵͳ
	*/
	bool XiTong_IsWindows64();
	/*
	ϵͳ_ȡ�ı�ע����
	nTyp:��Ŀ¼ 1��HKEY_CLASSES_ROOT|2��HKEY_CURRENT_USER|3��HKEY_LOCAL_MACHINE|4��HKEY_USERS|5��HKEY_CURRENT_CONFIG
	szPathName��ȫ·��ע����
	szName:������
	*/
	LPCWSTR XiTong_GetTextZhuCeBiaoXiang(int nTyp, LPCWSTR szPathName, LPCWSTR szName);
	//ϵͳ_ȡ��ֵע����
	int XiTong_GetIntZhuCeBiaoXiang(int nTyp, LPCWSTR szPathName, LPCWSTR szName);
	/*
	ϵͳ_ɾ��ע�����
	nTyp:��Ŀ¼ 1��HKEY_CLASSES_ROOT|2��HKEY_CURRENT_USER|3��HKEY_LOCAL_MACHINE|4��HKEY_USERS|5��HKEY_CURRENT_CONFIG
	szPathName��ȫ·��ע����
	szName:������
	bIs��trueɾ��·��������ֵ false ֻɾ��ָ��·����ָ��ֵ
	*/
	bool XiTong_DeleteZhuCeXiang(int nTyp, LPCWSTR szPathName, LPCWSTR szName, bool bIs = true);
	/*
	��ȡIE������İ汾
	*/
	LPCWSTR XiTong_GetIEver();
	/*
	ϵͳ_ע����Ŀ¼ȡhKey
	*/
	DWORD XiTong_GetGenMuluKey(int nTyp);
	/*
	ϵͳ_��ȡϵͳ������Ϣ�ı�
	*/
	LPCWSTR XiTong_GetErrorText(int nErrTyp);

	/*
	ϵͳ_ȡ�������
	*/
	LPCWSTR XiTong_GetWindowsName();
	/*
	ϵͳ_ȡ��Ļ�ֱ�����Ϣ
	*/
	strPingMuFenBianlv& XiTong_GetPingMuFenBianlv(int nIndex=0);
	/*
	ϵͳ_ȡ���ڸ�ʽ
	*/
	LPCWSTR XiTong_GetRiQiGeshi();
	/*
	ϵͳ_ȡʱ���ʽ
	*/
	LPCWSTR XiTong_GetTimeGeshi();
	/*
	ϵͳ_ȡʱ��
	*/
	LPCWSTR XiTong_GetShiQu();
	/*
	ϵͳ_ȡ��������״̬
	*/
	bool XiTong_IsWangluoZhuangtai();
	/*
	ϵͳ_ȡ����������
	*/
	LPCWSTR XiTong_GetWangluoZhujiName();
	/*
	ϵͳ_ȡϵͳDPI
	*/
	int XiTong_GetWindowDPI();
	/*
		ϵͳ_ȡ����Դ����
		����˯�ߡ�����
	*/
	bool XiTong_QuXiaoDianYuanGuanli();

	/*
	ϵͳ_�ָ���Դ����
	
	*/
	bool XiTong_HuiFuDianYuanGuanli();
	/*
	ϵͳ_ȡ�û���
	*/
	LPCWSTR XiTong_GetUserName();

	/*
	ϵͳ_�Ƿ�Ϊ����Ա
	�жϵ�ǰ�����Ƿ��ڹ���Աģʽ������
	*/
	bool XiTong_IsAdminRun();
	/*
	ϵͳ_�Ƿ�ΪĬ������
	*/
	bool XiTong_IsMoRenZiTi();
	/*
	ϵͳ_ˢ��
	����ˢ��ϵͳ����ע����µ�����������Ч��
	*/
	void XiTong_ShuXin();
	/*
	ϵͳ_д��ֵע����
	nVal����Ŀ¼ 
	1��HKEY_CLASSES_ROOT
	2��HKEY_CURRENT_USER
	3��HKEY_LOCAL_MACHINE
	4��HKEY_USERS
	5��HKEY_CURRENT_CONFIG
	szPath��ȫ·��
	nTyp:ע�������
	0��REG_NONE
	1��REG_SZ
	2��REG_EXPAND_SZ
	3��REG_BINARY
	4��REG_DWORD
	5��REG_DWORD_BIG_ENDIAN
	6��REG_LINK
	7��REG_MULTI_SZ
	8��REG_RESOURCE_LIST
	9��REG_FULL_RESOURCE_DESCRIPTOR
	10��REG_RESOURCE_REQUIREMENTS_LIST
	11��REG_QWORD
	szName:������
	dwVal:��д���ֵ
	*/
	bool XiTong_WriteIntReg(int nVal, LPCWSTR szPath, int nTyp,LPCWSTR szName,DWORD dwVal);
	/*
	ϵͳ_д�ı�ע����
	��������ο� д��ֵע���� ��������ǣ�
	*/
	bool XiTong_WriteTextReg(int nVal, LPCWSTR szPath, int nTyp, LPCWSTR szName, LPCWSTR szVal);
	/*
	ϵͳ_�����汳�� ���������ֽ
	szName:ͼƬ·��
	nTyp:���췽ʽ  0��ƽ��1������2������3����Ӧ4�����5������
	*/
	bool XiTong_SetWindowBiZhi(LPCWSTR szPath, int nTyp);
	/*
	ϵͳ_������Դ������
	*/
	bool XiTong_ChongQiZiyuanguanLiqi();
	/*
	ϵͳ_���巢��
	*/
	void XiTong_ZhuBanFasheng(DWORD dwPinLv, DWORD dwMs);
	/*
	ϵͳ_�޸���ҳ��ַ
	szBase:��ҳ��ַ
	*/
	bool XiTong_XiuGaiZhuye(LPCWSTR szBase);
	/*
	ϵͳ_��ȡ��ҳ��ַ
	*/
	LPCWSTR XiTong_QuZhuyeBase();
private:

private:
	std::wstring m_strResult;
	std::wstring m_strData;
	std::wstring m_strErr;
	strPingMuFenBianlv m_PingMuData;
	std::wstring m_strTime;
	std::wstring m_strShiQu;
}; 



