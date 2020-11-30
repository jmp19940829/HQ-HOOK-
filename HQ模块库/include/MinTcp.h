#pragma once
#include "hongdingyi.h"
typedef UINT_PTR        SOCKET;
// 1�������ָ�� 2���ͻ��˵�socket 3��1�ͻ��˽��� 2���ݵ���3�Ͷ˶Ͽ�����
//4�������ַ��5��������� 6���÷����Ŀǰ���ӵ�����
typedef void(__stdcall * tcp_fun)(HANDLE Server, SOCKET so, int type, char* buf, int len, int count);
// 1���ͻ��� 2�������socket 3��1�ͻ��˽��� 2���ݵ���3�Ͷ˶Ͽ�����
//4�������ַ��5���������
typedef void(__stdcall* tcp_fun_client)(HANDLE Client, SOCKET so, int type, char* buf, int len);


class PORTDLLCLASS TCP_Client
{
public:
	TCP_Client();
	virtual ~TCP_Client();
public:
	/*
	��ʼ���ͻ���
	funClient��tcp_fun_client  �ص����� �������ܷ���������������
	����ֵ���ɹ�����0
	*/
	int InitiaClinet(tcp_fun_client funClient);
	/*
	���ӷ�����
	szIp��������IP
	Port���������˿�
	bIs���Ƿ�����ģʽ Ĭ��false
	����ֵ�����ط����������Ӿ�� ʧ�ܷ���0
	*/
	HANDLE CreateClient(char* szIp, short Port,bool bIs=false);
	/*
	���������������
	so������˾��
	buf:���͵�����
	len:���Ͷ����ֽ�
	����ֵ���ɹ�����true
	*/
	bool Send(HANDLE so, char* buf, int len);
	/*
	�Ͽ������˵�����
	so�����������
	*/
	void close(HANDLE so);
};

class PORTDLLCLASS TCP_Server
{
public:
	TCP_Server();
	virtual ~TCP_Server();
public:
	/*
	��ʼ�������
	funClient��tcp_fun_client  �ص����� �������ܿͻ��˷���������
	����ֵ���ɹ�����0
	*/
	int InitiaServer(tcp_fun funServer);
	/*
	���������
	szIp��������ip
	Port���������˿�
	bIs���Ƿ�����ͨ��Ĭ��false
	*/
	bool CreateServer(char* szIp,short Port,bool bIs = false );
	/*
	�Ͽ���ָ���ͻ�������
	so:�ͻ��˵�SOCKET
	*/
	bool closeClinet(SOCKET so);
	/*
	��ȡ�ͻ�����Ϣ
	handle���ͻ���HANDLE
	so���ͻ��˵�SOCKET
	szIp��OUT ���IP
	port��OUT����˿�
	*/
	bool GetClinetData(HANDLE handle ,SOCKET so,OUT char* szIp,OUT short* port);
	/*
	��ͻ��˷�������
	sso���ͻ��˾��
	so:�ͻ���SOCKET
	buf:���͵�����
	len:���Ͷ����ֽ�
	����ֵ���ɹ�����true
	*/
	bool Send(HANDLE sso, SOCKET so, char* buf, int len);
	/*
	��ȡ����ip
	*/
	bool GetCurrenServerIp(OUT char* szIp);
};

