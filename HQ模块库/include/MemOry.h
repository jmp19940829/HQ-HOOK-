#pragma once
#include "hongdingyi.h"
typedef void *HMEMORYMODULE;
typedef void *HMEMORYRSRC;
typedef void *HCUSTOMMODULE;


class PORTDLLCLASS  MemOry :
	public process
{
public:
	MemOry();
	virtual ~MemOry();
public:
	/*
	�ڴ�_д�ڴ����� (���ƹ�VMP�ڴ汣��)
	dwPid:����pid
	lpBaseAddess:��д���Ŀ���ַ
	lpBuf:��д�������
	nSize:д������ֽ�
	����ֵ���ɹ�����true
	*/
	bool mem_WriteMemory(DWORD dwPid, LPVOID lpBaseAddess,LPVOID lpBuf, int nSize);
	/*
	�ڴ�_���ڴ����� (���ƹ�VMP�ڴ汣��)
	dwPid:����pid
	lpBaseAddess:����ȡ��Ŀ���ַ
	lpBuf:��Ŷ�ȡ���ݵõ�ַ
	nSize:�������ֽ�
	����ֵ���ɹ�����true
	*/
	bool mem_ReadMemory(DWORD dwPid, LPVOID lpBaseAddess,OUT LPVOID lpBuf, int nSize);
	/*
	�ֽڼ�ת16�����ı�
	pszDest�����16�����ֽ��ı��õ�ַ
	pbSrc����ת�����ֽڼ���ַ
	nLen:ת�������ֽ�
	*/
	void mem_HexToStr(OUT char *pszDest, byte *pbSrc, int nLen);
	/*
	�ڴ�_16�����ı�ת�ֽڼ�
	pszDest�����16�����ֽڵõ�ַ
	pbSrc����ת���õ�ַ
	nLen:ת�������ֽ�
	*/
	void mem_StrToHex(OUT byte *pbDest, char *pszSrc, int nLen);
	/*
	�ڴ�_ȡ�ڴ�HEX
	Bin���ڴ��ַ
	Binlen��Ҫȡ���ֽ���
	Hex�����������ַ����Ļ�����
	IsUpper:�Ƿ��Ǵ�СдTRUEΪ��д
	nLen:ת�������ֽ�
	*/
	void mem_BinToHex(const char* Bin, size_t Binlen, char* Hex, bool IsUpper=true);
	/*
	�ڴ�_����������ƥ��
	dwPid������pid
	Value:������ ֧��ͨ���??(?����ɶԴ���??)
	Start������������ʼ��ַ��ģ���ַ��
	End�������Ľ�����ַ
	����ֵ�������ɹ����ص���ȫ����ַ
	*/
	std::vector <DWORD_PTR>  mem_FindHex(DWORD dwPid, const char* Value, ULONG64 Start, ULONG64 End);
	/*
	�ڴ�_����DLL
	lpData:dll���ڴ��еĵ�ַ
	dwSize��dll�Ĵ�С
	����ֵ���ɹ�����dll��� ʧ�ܷ���NULL
	*/
	HMEMORYMODULE mem_LoadLibrary(LPVOID lpData, DWORD dwSize);
	/*
	�ڴ�_��ȡ�ڴ�dll������ַ
	meMolde:�ڴ�dll���
	szName:��������
	����ֵ���ɹ����غ�����ַ
	*/
	DWORD_PTR mem_GetProcAddress(HMEMORYMODULE meMolde, char* szName);
	/*
	Ĩ���ڴ�DLL PE��ʶ ��ֹ�ڴ�ɨ�裨���������ȡ����������õ��� ����������ַ���ڵ��ã�
	byBuf:dll���ڴ��еĵ�ַ
	meMolde��Load ���DLL���
	����ֵ���ɹ�����TRUE
	(˵���� Ĩ��PE��ʶ ���������ڴ�DLL ��ȡ��������DLL�еõ���������ַ���ڵ��ã�
	 ��������GetProcAddress����ʱ��Ȼ�ᵼ�³������)
	*/
	BOOL mem_ReasePE(LPVOID byBuf, HMEMORYMODULE meMolde);
	/*
	�ڴ�_�ͷ��ڴ���ص�dll
	meMolde:�ڴ�dll���
	*/
	void mem_FerrLibrary(HMEMORYMODULE meMolde);
};
//�����ڴ���
class PORTDLLCLASS ShareMemory
{
public:
		ShareMemory();
		~ShareMemory();
public:
	/*
	���������ڴ�
	szMemOrName�������ڴ�����
	nLen��Ҫ�����Ĺ����ڴ泤��,��4096Ϊ���� ���65536���ֽڳ���
	����ֵ���ɹ�����true ���� false
	*/
	bool CreareShareMemory(LPWSTR szMemOrName, int nLen=4096);
	/*
	д�����ڴ�����
	lpBuf:��д�����ݵõ�ַ
	nSize:д������ֽ� ���� 4�ֽ� float 4�ֽ� double 8�ֽڣ��ַ���sizeof(�ַ���)+1 
	nOffset:�����ڴ�д���ڴ�ƫ���� Ĭ��0
	*/
	void WriteMemOry(LPVOID lpBuf, int nSize,int nOffset=0);
	/*
	�򿪹����ڴ�
	szMenOry�������ڴ�����
	����ֵ���ɹ�����true ���� false
	*/
	bool OpenShareMemory(LPWSTR szMenOry);
	/*
	�������ڴ�����
	����ֵ�����ع����ڴ������
	*/
	LPVOID ReadShareMemory();
	//��д�±��
	ShareMemory& operator[](int Index);
private:
	HANDLE m_hMapping;//���������ڴ���
	HANDLE m_hMapFile;//�򿪹����ڴ�þ��
	LPVOID m_lpBuf;
	LPVOID m_lpBase;
};

