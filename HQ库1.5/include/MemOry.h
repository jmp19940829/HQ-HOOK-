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
	内存_写内存数据 (可绕过VMP内存保护)
	dwPid:进程pid
	lpBaseAddess:欲写入得目标地址
	lpBuf:欲写入得数据
	nSize:写入多少字节
	返回值：成功返回true
	*/
	bool mem_WriteMemory(DWORD dwPid, LPVOID lpBaseAddess,LPVOID lpBuf, int nSize);
	/*
	内存_读内存数据 (可绕过VMP内存保护)
	dwPid:进程pid
	lpBaseAddess:欲读取得目标地址
	lpBuf:存放读取数据得地址
	nSize:读多少字节
	返回值：成功返回true
	*/
	bool mem_ReadMemory(DWORD dwPid, LPVOID lpBaseAddess,OUT LPVOID lpBuf, int nSize);
	/*
	字节集转16进制文本
	pszDest：存放16进制字节文本得地址
	pbSrc：欲转换得字节集地址
	nLen:转换多少字节
	*/
	void mem_HexToStr(OUT char *pszDest, byte *pbSrc, int nLen);
	/*
	内存_16进制文本转字节集
	pszDest：存放16进制字节得地址
	pbSrc：欲转换得地址
	nLen:转换多少字节
	*/
	void mem_StrToHex(OUT byte *pbDest, char *pszSrc, int nLen);
	/*
	内存_取内存HEX
	Bin：内存地址
	Binlen：要取的字节数
	Hex：用来接收字符串的缓冲区
	IsUpper:是否是大小写TRUE为大写
	nLen:转换多少字节
	*/
	void mem_BinToHex(const char* Bin, size_t Binlen, char* Hex, bool IsUpper=true);
	/*
	内存_特征码搜索匹配
	dwPid：进程pid
	Value:特征码 支持通配符??(?必须成对存在??)
	Start：欲搜索的起始地址（模块基址）
	End：搜索的结束地址
	返回值：搜索成功返回到的全部地址
	*/
	std::vector <DWORD_PTR>  mem_FindHex(DWORD dwPid, const char* Value, ULONG64 Start, ULONG64 End);
	/*
	内存_加载DLL
	lpData:dll在内存中的地址
	dwSize：dll的大小
	返回值：成功返回dll句柄 失败返回NULL
	*/
	HMEMORYMODULE mem_LoadLibrary(LPVOID lpData, DWORD dwSize);
	/*
	内存_获取内存dll函数地址
	meMolde:内存dll句柄
	szName:函数名称
	返回值：成功返回函数地址
	*/
	DWORD_PTR mem_GetProcAddress(HMEMORYMODULE meMolde, char* szName);
	/*
	抹除内存DLL PE标识 防止内存扫描（必须在你获取完所有你会用到的 导出函数地址后在调用）
	byBuf:dll在内存中的地址
	meMolde：Load 后得DLL句柄
	返回值：成功返回TRUE
	(说明： 抹除PE标识 必须在你内存DLL 获取完你所有DLL中得导出函数地址后在调用！
	 否则当你在GetProcAddress函数时必然会导致程序崩溃)
	*/
	BOOL mem_ReasePE(LPVOID byBuf, HMEMORYMODULE meMolde);
	/*
	内存_释放内存加载的dll
	meMolde:内存dll句柄
	*/
	void mem_FerrLibrary(HMEMORYMODULE meMolde);
};
//共享内存类
class PORTDLLCLASS ShareMemory
{
public:
		ShareMemory();
		~ShareMemory();
public:
	/*
	创建共享内存
	szMemOrName：共享内存名称
	nLen：要创建的共享内存长度,以4096为倍数 最大65536个字节长度
	返回值：成功返回true 否则 false
	*/
	bool CreareShareMemory(LPWSTR szMemOrName, int nLen=4096);
	/*
	写共享内存数据
	lpBuf:欲写入数据得地址
	nSize:写入多少字节 整数 4字节 float 4字节 double 8字节！字符串sizeof(字符串)+1 
	nOffset:共享内存写入内存偏移量 默认0
	*/
	void WriteMemOry(LPVOID lpBuf, int nSize,int nOffset=0);
	/*
	打开共享内存
	szMenOry：共享内存名称
	返回值：成功返回true 否则 false
	*/
	bool OpenShareMemory(LPWSTR szMenOry);
	/*
	读共享内存数据
	返回值：返回共享内存得数据
	*/
	LPVOID ReadShareMemory();
	//重写下标符
	ShareMemory& operator[](int Index);
private:
	HANDLE m_hMapping;//创建共享内存句柄
	HANDLE m_hMapFile;//打开共享内存得句柄
	LPVOID m_lpBuf;
	LPVOID m_lpBase;
};

