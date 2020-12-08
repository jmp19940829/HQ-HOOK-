#pragma once
#include "hongdingyi.h"
typedef struct
{
	uint64_t    length;
	uint32_t    state[8];
	uint32_t    curlen;
	uint8_t     buf[64];
} Sha256;
#define AES_KEY_SIZE_128        16
#define AES_KEY_SIZE_192        24
#define AES_KEY_SIZE_256        32
class PORTDLLCLASS CodePassWord
{
public:
	CodePassWord();
	~CodePassWord();
public:
	
	/*
	�ַ������ܵ�MD5
	szData���ַ���
	����ֵ���ɹ�����MD5
	*/
	string strToMd5(char* szData);
	/*
	�ڴ��ֽ������ܵ�MD5
	szBuf���ڴ��ַ
	nSize�����ܶ����ֽڵ�MD5
	����ֵ���ɹ�����MD5
	*/
	string byToMd5(LPVOID szBuf, int nSize);
	/*
	Сд�ַ���ת��д
	strData��Сд���ַ���
	����ֵ������ת����Ĵ�д
	*/
	string toCapital(string strData);
	/*
	��д�ַ���תСд
	strData����д���ַ���
	����ֵ������ת�����Сд
	*/
	string toLowErcase(string strData);
	/*
	RC4�ԳƼ���
	szSource��Ҫ���ܵ�����
	szPassWord��������ܵ�����
	����ֵ���ɹ���������16���� ʧ�� ����NULL
	*/
	string Rc4Encrypt(const char* szSource, const char* szPassWord);
	/*
	RC4�Գƽ���
	szSource��Ҫ���ܵ�����
	szPassWord��������ܵ�����
	����ֵ���ɹ����ؽ��ܺ������ʧ�� ����NULL
	*/
	string Rc4Decrypt(const char* szSource, const char* szPassWord);
	/*
	TEA�ԳƼ���
	szSource��Ҫ���ܵ����ģ�������ɺ� �˲����� ��ŵ��Ǽ��ܺ�����ݣ�
	nLen:���ĳ��ȣ�Ҳ��TEA�� ѭ���ִ�����
	szPassWord��������ܵ�����
	*/
	void TeaEncrypt(BYTE* szSource, int nLen, BYTE* szPassWord);
	/*
	TEA�Գƽ���
	szSource��Ҫ���ܵ����ģ�������ɺ� �˲����� ��ŵ��ǽ��ܺ�����ݣ�
	nLen:���ĳ��ȣ�Ҳ��TEA�� ѭ���ִ�����
	szPassWord��������ܵ�����
	*/
	void TeaDecrypt(BYTE* szSource, int nLen, BYTE* szPassWord);
	/*
	Base64����
	data:Ҫ���������
	data_len��Ҫ�������ݵĳ���
	szBuf:��ű���������
	����ֵ:���ر����ĳ���
	*/
	int Base64Encrypt(const char* data, int data_len,OUT char* szBuf);
	/*
	Base64����
	data:Ҫ���������
	data_len��Ҫ�������ݵĳ���
	szBuf:��Ž���������
	����ֵ:���ؽ����ĳ���
	*/
	int Base64Decrypt(const char* data, int data_len,OUT char* szBuf);
	/*
	AES����
	data�������ܵ�����(������غ��������� ��������ﱣ���ż��ܺ������)
	nSize:���ܶ����ֽ�
	key������key
	nlen������key����
	AES_KEY_SIZE_128
	AES_KEY_SIZE_192
	AES_KEY_SIZE_256
	Buf����ż��ܺ������ ����������龡����Щ��ֹ������
	����ֵ���ɹ����ؼ��ܺ���ֽ���
	*/
	int AesEncrypt(void* data, int nSize, IN void* key, int nlen,OUT char *Buf);
	/*
	AES����
	data�������ܵ�����(������غ��������� ��������ﱣ���ż��ܺ������)
	nSize:���ܶ����ֽ� 
	key������key
	nlen������key����
	AES_KEY_SIZE_128
	AES_KEY_SIZE_192
	AES_KEY_SIZE_256
	Buf����ż��ܺ������ ����������龡����Щ��ֹ������
	*/
	int AesDecrypt(void* data, int nSize, IN void* key, int nlen,OUT char *Buf);
	/*
	��ʼ��SHA25
	Sha:��Ϊ�������
	*/
	VOID Sha256Init(OUT Sha256* Sha);
	/*
	����Sha256����
	Sha��Sha256Init ��������ֵ
	Data��Ҫ��ӵ�����
	nlen��Ҫ������ݵĴ�С
	˵��������ѭ�����ô˺���ֱ����Ҫ��������������ϣ�
	*/
	VOID Sha256Update(Sha256* Sha,void* Data,int nlen);
	/*
	����Sha256 32λֵ
	Sha��Sha256Init ��������ֵ
	byBuf���봫��һ��32�ֽڵ�BYTE���� ִ����Ϻ� �Ὣ������32�ֽ�ֵ�洢��BYTE������
	*/
	VOID Sha256Finalise(Sha256* Sha,OUT BYTE* byBuf);
};