#pragma once
#include "hongdingyi.h"
class PORTDLLCLASS XiTongFuWu :public XiTong
{
public:
	XiTongFuWu();
	virtual ~XiTongFuWu();

public:
	/*
	安装服务 创建一个系统服务项
	szSerName:服务名称 "系统服务数据库中ID名称,不能为中文"
	szShowName：显示名称
	szPath：执行文件
	szText:服务描述 可NULL
	bIs：允许桌面交互 默认false
	nServTyp:服务类型 默认16  1、内核驱动 2、文件系统驱动 16、进程 32、其它服务
	nQiTyp：启动类型 默认3    2、自动 3、手动 4、禁用
	szYicunGuanxi：依存关系 默认无 
	szUser:登录用户 默认无
	szPass:登录密码 默认无
	返回值：成功返回true 失败返回 false
	*/
	bool FuWu_AnZhuangFuwu(LPCWSTR szSerName, LPCTSTR szShowName, LPCWSTR szPath, LPCWSTR szText = L"", bool bIs=false, int nServTyp=16, int nQiTyp=3, LPCWSTR szYicunGuanxi = L"", LPCWSTR szUser =L"", LPCWSTR szPass = L"");
	/*
	置服务描述 修改指定系统服务描述
	szName:服务器名称
	szText:新的服务器描述
	返回值;成功返回true 否则false
	*/
	bool FuWu_SetMiaoshu(LPCWSTR szName, LPCWSTR szText);
	/*
	恢复服务
	恢复被暂停的系统服务
	szName:服务名
	返回值;成功返回true 否则false
	*/
	bool FuWu_HuiFu(LPCWSTR szName);
	/*
	开始服务
	开启一个系统服务
	szName:服务名
	返回值;成功返回true 否则false
	*/
	virtual  bool FuWu_KaiQiFuwu(LPCWSTR szName);
	/*
	取服务类型
	szName:服务名
	1、设备驱动
	2、文件系统驱动
	16、进程
	32、自己进程或其它服务
	256、交互服务
	*/
	int FuWu_QuFuWuleixing(LPCWSTR szName);
	/*
	取服务描述
	szName:服务名
	返回值：成功返回服务描述文本
	*/
	LPCWSTR FuWu_QuFuwuMiaoshu(LPCWSTR szName);
	/*
	取服务名称
	szName:显示名称
	返回值：成功返回服务描述文本
	*/
	LPCWSTR FuWu_QuFuwuName(LPCWSTR szName);
	/*
	取服务状态
	szName:服务名
	返回值：返回状态
	1、已停止 2、开始 3、停止 4、正在运行 5、继续挂起 6、暂停挂起 7、暂停
	*/
	int FuWu_QuFuwuZhuangTai(LPCWSTR szName);
	/*
	取显示名称 根据系统服务数据库名称获取显示名称
	szName:服务名
	返回值：返回服务显示名称
	*/
	LPCWSTR FuWu_QuXianShiName(LPCWSTR szName);
	/*
	服务是否存在
	szName:服务名
	*/
	bool FuWu_IsServer(LPCWSTR szName);
	/*
	停止服务 停止一个存在运行的系统服务
	szName:服务名
	*/
	bool FuWu_TingZhi(LPCWSTR szName);
	/*
	卸载服务 如果服务正在运动会先停止服务然后再删除
	szName:服务名
	*/
	bool FuWu_XieZai(LPCWSTR szName);
	/*
	暂停服务 暂停一个存在运行的系统服务
	szName:服务名
	*/
	bool FuWu_ZanTingStop(LPCWSTR szName);
private:
	std::wstring m_strDescription;
	std::wstring m_strServerName;
};

