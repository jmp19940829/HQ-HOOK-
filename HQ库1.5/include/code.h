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
	/*
	RC4对称加密
	szSource：要加密得明文
	szPassWord：参与加密得密码
	返回值：成功返回密文16进制 失败 返回NULL
	*/
	string Rc4Encrypt(const char* szSource, const char* szPassWord);
	/*
	RC4对称解密
	szSource：要解密得密文
	szPassWord：参与解密得密码
	返回值：成功返回解密后得明文失败 返回NULL
	*/
	string Rc4Decrypt(const char* szSource, const char* szPassWord);
	/*
	TEA对称加密
	szSource：要加密得明文（加密完成后 此参数里 存放的是加密后的数据）
	nLen:明文长度（也是TEA的 循环轮次数）
	szPassWord：参与加密得密码
	*/
	void TeaEncrypt(BYTE* szSource, int nLen, BYTE* szPassWord);
	/*
	TEA对称解密
	szSource：要解密得密文（解密完成后 此参数里 存放的是解密后的数据）
	nLen:密文长度（也是TEA的 循环轮次数）
	szPassWord：参与解密得密码
	*/
	void TeaDecrypt(BYTE* szSource, int nLen, BYTE* szPassWord);
	/*
	Base64编码
	data:要编码的数据
	data_len：要编码数据的长度
	szBuf:存放编码后的数据
	返回值:返回编码后的长度
	*/
	int Base64Encrypt(const char* data, int data_len,OUT char* szBuf);
	/*
	Base64解码
	data:要解码的数据
	data_len：要解码数据的长度
	szBuf:存放解码后的数据
	返回值:返回解码后的长度
	*/
	int Base64Decrypt(const char* data, int data_len,OUT char* szBuf);
	/*
	AES加密
	data：待加密的数据(如果返回函数返回真 这个参数里保存着加密后的数据)
	nSize:加密多少字节
	key：加密key
	nlen：加密key长度
	AES_KEY_SIZE_128
	AES_KEY_SIZE_192
	AES_KEY_SIZE_256
	Buf：存放加密后得数据 （申请得数组尽量大些防止不够）
	返回值：成功返回加密后得字节数
	*/
	int AesEncrypt(void* data, int nSize, IN void* key, int nlen,OUT char *Buf);
	/*
	AES解密
	data：待解密的数据(如果返回函数返回真 这个参数里保存着加密后的数据)
	nSize:解密多少字节 
	key：解密key
	nlen：解密key长度
	AES_KEY_SIZE_128
	AES_KEY_SIZE_192
	AES_KEY_SIZE_256
	Buf：存放加密后得数据 （申请得数组尽量大些防止不够）
	*/
	int AesDecrypt(void* data, int nSize, IN void* key, int nlen,OUT char *Buf);
	/*
	初始化SHA25
	Sha:作为输出参数
	*/
	VOID Sha256Init(OUT Sha256* Sha);
	/*
	更新Sha256数据
	Sha：Sha256Init 所传出的值
	Data：要添加的数据
	nlen：要添加数据的大小
	说明（可以循环调用此函数直到将要计算的数据添加完毕）
	*/
	VOID Sha256Update(Sha256* Sha,void* Data,int nlen);
	/*
	计算Sha256 32位值
	Sha：Sha256Init 所传出的值
	byBuf：请传入一个32字节的BYTE数组 执行完毕后 会将计算后的32字节值存储到BYTE数组里
	*/
	VOID Sha256Finalise(Sha256* Sha,OUT BYTE* byBuf);
};