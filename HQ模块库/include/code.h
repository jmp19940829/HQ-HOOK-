#pragma once
#include "hongdingyi.h"
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

};