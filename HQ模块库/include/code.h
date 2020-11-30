#pragma once
#include "hongdingyi.h"
class PORTDLLCLASS CodePassWord
{
public:
	CodePassWord();
	~CodePassWord();
public:
	
	/*
	字符串加密到MD5
	szData：字符串
	返回值：成功返回MD5
	*/
	string strToMd5(char* szData);
	/*
	内存字节数加密到MD5
	szBuf：内存地址
	nSize：加密多少字节到MD5
	返回值：成功返回MD5
	*/
	string byToMd5(LPVOID szBuf, int nSize);
	/*
	小写字符串转大写
	strData：小写的字符串
	返回值：返回转换后的大写
	*/
	string toCapital(string strData);
	/*
	大写字符串转小写
	strData：大写的字符串
	返回值：返回转换后的小写
	*/
	string toLowErcase(string strData);

};