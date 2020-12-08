#pragma once
#include "hongdingyi.h"
/*
szPath：保存着文件路径
szName：文件名称
*/
typedef void(WINAPI*MULUBIANLI)(LPCWSTR szPath, LPCWSTR szName);
/*
szData:当前正在解压得文件名称
nTyp：以下类型 
10、解压完成 0、解压当前文件  12、文件损坏或密码错误 22、解压密码错误 
*/
typedef void(WINAPI* RARHUIDIAO)(LPSTR szData, int nTyp);
struct WenjianTime
{
	std::wstring cReateTime;//创建时间
	std::wstring XiuGaiTime;//修改时间
	std::wstring FangWenTime;//访问时间
};

class PORTDLLCLASS JiHe :public XiTongFuWu
{
public:
	JiHe();
	virtual~JiHe();
public:
	/*
	剪辑板_取数据权窗口句柄 成功返回复制该数据的窗口句柄
	*/
	 DWORD_PTR JianQieBan_QuShujuQuanChuangKouhWnd();
	 /*
	 剪辑板_取文本 
	 */
	 LPCWSTR JianQieBan_GetTextBuf();
	 /*
	 剪辑板_置文本 设置指定文本到系统剪辑板
	 szText:要置的文本
	 */
	 void  JianQieBan_SetTextBuf(LPWSTR szText);
	/*
	剪贴板_监听 把指定的窗口句柄加入到剪贴板查看器链中
	*/
	 void JianQieBan_JianTing(HWND dwhWnd,LPVOID lpFun);
	 /*
	 剪贴板_停止监听
	 */
	 void JianQieBan_TingZhiJianTing(HWND hWnd);

private:
	std::wstring m_strJianQIeBanText;//剪切板得内容
};

class PORTDLLCLASS Mulu :public JiHe
{
public:
	Mulu();
	virtual~Mulu();

public:
	/*
	取当前目录
	返回值：返回取当前目录路径
	*/
	LPCWSTR Mulu_QuDangQianMulu();
	/*
	取临时目录
	返回值：返回临时目录路径
	*/
	LPCWSTR Mulu_QuLinshiMulu();
	/*
	目录_取特定目 
	1: #我的文档;  2: #我的收藏夹;  3: #系统桌面;  4: #系统字体;  5: #开始菜单组;  6: #程序菜单组; 
	 7: #启动菜单组;  8: #程序数据目录;  9: #Windows安装目录;  10: #Windows系统目录;  11: #临时文件目录。
	返回值:成功返回路径
	*/
	LPCWSTR Mulu_QuTeDingMulu(int nTyp);
	/*
	目录_取尾部目录名或文件名 
	返回值： 成功返回目录名或文件
	*/
	LPCWSTR Mulu_QuweiBuWenjianName(LPCWSTR szPaht);
	/*
	目录_是否存在
	szPath:欲判断的目录路径
	*/
	bool Mulu_IsPathMulu(LPCWSTR szPath);
	/*
	目录_是否为空
	szPath:欲判断的目录路径
	*/
	bool Mulu_IsMuluNull(LPCWSTR szPath);
	/*
	遍历目录
	szPath：要遍历的起始目录
	muliFunc：回调函数 具体请看函数注释说明
	*/
	bool Mulu_BianLiMulu(LPCWSTR szPath, MULUBIANLI muliFunc);
public:
	std::wstring m_strMulu;
private:
	//文件或文件夹是否存在
	BOOL IsDirExist(LPCWSTR csDir);
};

class PORTDLLCLASS WenJian :public Mulu
{
public:
	WenJian();
	virtual ~WenJian();
public:
	/*
	文件_创建稀疏文件
	szPath:文件路径
	返回值：成功返回文件句柄HANDLE
	*/
	DWORD_PTR WenJian_CreateXiShuWenJian(LPCWSTR szPath);
	/*
	文件_取大小
	返回值：返回大小 （字节）
	*/
	DWORD WenJian_GetFileSize(LPCWSTR szPaht);
	/*
	文件_取文件时间
	FileTime:传出值 保存文件时间信息
	返回值：成功返回true 
	*/
	bool WenJian_QuWenJianShiJian(LPCWSTR szPath, OUT WenjianTime& FileTime);
	/*
	文件_取实际大小
	szPath:文件路径
	*/
	DWORD_PTR WenJian_GetZhenShiSize(LPCWSTR szPath);

	/*
	文件_删除到回收站
	szPath:文件路径
	nTyp:1、不询问删除；2、不提示错误；4、不显示进度
	*/
	bool WenJian_DeleWenjianDaoHuishou(PCWSTR szPath,int nTyp);
	/*
	文件_取文件名字
	szPath：路径
	返回值：返回文件名字
	*/
	LPCWSTR  WenJian_QuWenjianName(LPCWSTR szPath);
	/*
	文件_是否被占用
	szPath：路径
	*/
	bool WenJian_WenJianIsZhanyong(LPCWSTR szPath);
	/*
	文件_是否存在
	szPath：路径
	*/
	bool WenJian_WenJianIsCunZai(LPCWSTR szPath);
	/*
	文件_是否是稀疏文件
	szPath：路径
	*/
	bool WenJian_WenJianIsXiShuFile(LPCWSTR szPath);
	/*
	文件_重启电脑后替换
	szPath:用于替换的文件路径
	szOrgPath:被替换目标文件路径
	bIs:是否删除源文件
	*/
	bool WenJian_ChongQiDiannaoTihuan(LPCWSTR szPath, LPCWSTR szOrgPath, bool bIs);

	/*
	文件_写出文件
	szPath:文件路径
	lpData：文件数据
	dwSize：写出大小
	*/
	bool WenJian_WriteFilePath(LPCWSTR szPath,LPVOID lpData,DWORD dwSize);
	/*
	文件_写配置项ini
	szPath：ini文件路径
	szName1：父项名称
	szName2：子项名称
	szData：要设置得数据
	*/
	bool WenJian_XiePeiZhiXiang(LPCWSTR szPath, LPCWSTR szName1, LPCWSTR szName2, IN LPCWSTR szData);
	/*
	文件_读配置项
	szPath：ini文件路径
	szName1：父项名称
	szName2：子项名称
	szBuf：如果子项没有就返回此参数设定得默认值
	szData:保存读取到得配置
	nSize:szData得大小
	*/
	bool WenJian_DuPeiZhiXiang(LPCWSTR szPath, LPCWSTR szName1, LPCWSTR szName2, LPCWSTR szBuf,OUT WCHAR* szData,int nSize);
	/*
	文件_初始化RAR解压
	返回值:成功返回true
	*/
	bool WenJian_RarInit();
	/*
	文件_RAR解压
	szPath1:欲解压得文件路径
	szPath2：欲解压到得目标路径
	rarFun：回调函数 详细描述请看回调定义 他返回当前解压文件得名称和状态码
	szPassWord：解压密码 默认为NULL
	返回值:成功返回true
	*/
	bool WenJian_RarJieYa(LPWSTR szPath1, LPWSTR szPath2, RARHUIDIAO rarFun=NULL, LPWSTR szPassWord=NULL);
private:
	std::wstring m_strFileName;
};