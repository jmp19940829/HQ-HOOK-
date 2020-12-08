#pragma once
#include "hongdingyi.h"
//屏幕分辨率信息
struct strPingMuFenBianlv
{
	int nSeShen;//色深
	int nWide;//宽
	int nHigh;//高
	int nHz;//刷新率hz
};
class PORTDLLCLASS XiTong
{
public:

	XiTong();
	virtual ~XiTong();

public:
	/*
	暂时转让控制权，以便让 Windows 操作系统有机会处理其它的如用户键盘或鼠标输入等事件。
	直到操作系统处理并发送完程序队列中的所有事件后，命令才会返回。
	*/
	void XiTong_ChuLiShiJian();
	/*
	获取系统空闲时间
	返回单位为毫秒
	*/
	int XiTong_GetKongXianshijian();
	/*
	系统_创建还原点
	描述：szData
	类型:nTyp
	APPCHENGXU_HUANYUAN_ANZHUANG 程序安装
	APPCHENGXU_HUANYUAN_XIEZAI 程序卸载
	DRIVER_HUANYUAN_ANZHUANG  驱动安装
	WINDOW_HUANYUAN 系统
	返回值：成功 返回系统还原ID 失败<0
	*/
	DWORD XiTong_CreateHuanyuanDian(LPWSTR szData, int nTyp);
	/*
	系统_删除还原点
	dwId：还原点ID
	*/
	bool XiTong_DeleteHuanyuanDian(DWORD dwId);
	/*
	盘符:szData
	检查指定的卷是否支持稀疏文件
	*/
	bool XiTong_CiPanIsXishuWenjian(LPWSTR szData);
	/*
	szNmae:环境变量名称 例："%TEMP%"
	读取环境变量
	返回值:成功返回所取得的值
	*/
	LPCWSTR XiTong_ReadHuanjingBianliang(LPWSTR szName);
	/*
	系统_关机
	*/
	bool XiTong_Guanji();
	/*
	系统_重启
	*/
	bool XiTong_ChongQi();
	/*
	系统_注销
	*/
	bool XiTong_ZhuXiao();
	/*
	系统_强制关机
	*/
	bool XiTong_GuanjiEx();
	/*
	系统_强制重启
	*/
	bool XiTong_ChongQiEx();
	/*
	系统_强制注销
	*/
	bool XiTong_ZhuXiaoEx();
	/*
	系统_提权
	*/
	bool XiTong_TiShengQuanXian();

	/*
	 bIs：是否允许休眠
	*/
	bool XiTong_XiuMianguanli(bool bIs);
	/*
		系统_恢复屏保
	*/
	bool XiTong_HuiFuPingBao();
	/*
	系统_禁用屏保
	*/
	bool XiTong_JinZhiPingBao();
	/*
	系统_进入待机状态
	*/
	bool XiTong_JinRuDaiji();
	/*
	系统_禁用DPI缩放
	*/
	bool XiTong_JinYongDPIsuofang();
	/*
	临时字体安装或卸载
	szNmae:字体路径
	bIs:true 安装 false 卸载
	*/
	DWORD XiTong_TempAnZhuangZiTi(LPWSTR szNmae,bool bIs);

	/*
	系统_判断有无摄像头
	返回值：返回摄像头数量
	*/
	int XiTong_IsYouWuSheXiangtou();
	/*
	系统_清空回收站
	*/
	bool XiTong_QingKongHuiShouZhan();
	/*
	判断是否为64位系统
	*/
	bool XiTong_IsWindows64();
	/*
	系统_取文本注册项
	nTyp:根目录 1、HKEY_CLASSES_ROOT|2、HKEY_CURRENT_USER|3、HKEY_LOCAL_MACHINE|4、HKEY_USERS|5、HKEY_CURRENT_CONFIG
	szPathName：全路径注册项
	szName:项名称
	*/
	LPCWSTR XiTong_GetTextZhuCeBiaoXiang(int nTyp, LPCWSTR szPathName, LPCWSTR szName);
	//系统_取数值注册项
	int XiTong_GetIntZhuCeBiaoXiang(int nTyp, LPCWSTR szPathName, LPCWSTR szName);
	/*
	系统_删除注册表项
	nTyp:根目录 1、HKEY_CLASSES_ROOT|2、HKEY_CURRENT_USER|3、HKEY_LOCAL_MACHINE|4、HKEY_USERS|5、HKEY_CURRENT_CONFIG
	szPathName：全路径注册项
	szName:项名称
	bIs：true删除路径下所有值 false 只删除指定路径下指定值
	*/
	bool XiTong_DeleteZhuCeXiang(int nTyp, LPCWSTR szPathName, LPCWSTR szName, bool bIs = true);
	/*
	获取IE浏览器的版本
	*/
	LPCWSTR XiTong_GetIEver();
	/*
	系统_注册表根目录取hKey
	*/
	DWORD XiTong_GetGenMuluKey(int nTyp);
	/*
	系统_获取系统错误信息文本
	*/
	LPCWSTR XiTong_GetErrorText(int nErrTyp);

	/*
	系统_取计算机名
	*/
	LPCWSTR XiTong_GetWindowsName();
	/*
	系统_取屏幕分辨率信息
	*/
	strPingMuFenBianlv& XiTong_GetPingMuFenBianlv(int nIndex=0);
	/*
	系统_取日期格式
	*/
	LPCWSTR XiTong_GetRiQiGeshi();
	/*
	系统_取时间格式
	*/
	LPCWSTR XiTong_GetTimeGeshi();
	/*
	系统_取时区
	*/
	LPCWSTR XiTong_GetShiQu();
	/*
	系统_取网络连接状态
	*/
	bool XiTong_IsWangluoZhuangtai();
	/*
	系统_取网络主机名
	*/
	LPCWSTR XiTong_GetWangluoZhujiName();
	/*
	系统_取系统DPI
	*/
	int XiTong_GetWindowDPI();
	/*
		系统_取消电源管理
		避免睡眠、待机
	*/
	bool XiTong_QuXiaoDianYuanGuanli();

	/*
	系统_恢复电源管理
	
	*/
	bool XiTong_HuiFuDianYuanGuanli();
	/*
	系统_取用户名
	*/
	LPCWSTR XiTong_GetUserName();

	/*
	系统_是否为管理员
	判断当前程序是否在管理员模式下运行
	*/
	bool XiTong_IsAdminRun();
	/*
	系统_是否为默认字体
	*/
	bool XiTong_IsMoRenZiTi();
	/*
	系统_刷新
	立即刷新系统，让注册表新的设置立即生效。
	*/
	void XiTong_ShuXin();
	/*
	系统_写数值注册项
	nVal：根目录 
	1、HKEY_CLASSES_ROOT
	2、HKEY_CURRENT_USER
	3、HKEY_LOCAL_MACHINE
	4、HKEY_USERS
	5、HKEY_CURRENT_CONFIG
	szPath：全路径
	nTyp:注册表类型
	0、REG_NONE
	1、REG_SZ
	2、REG_EXPAND_SZ
	3、REG_BINARY
	4、REG_DWORD
	5、REG_DWORD_BIG_ENDIAN
	6、REG_LINK
	7、REG_MULTI_SZ
	8、REG_RESOURCE_LIST
	9、REG_FULL_RESOURCE_DESCRIPTOR
	10、REG_RESOURCE_REQUIREMENTS_LIST
	11、REG_QWORD
	szName:项名称
	dwVal:欲写入得值
	*/
	bool XiTong_WriteIntReg(int nVal, LPCWSTR szPath, int nTyp,LPCWSTR szName,DWORD dwVal);
	/*
	系统_写文本注册项
	具体参数参考 写数值注册项 （上面就是）
	*/
	bool XiTong_WriteTextReg(int nVal, LPCWSTR szPath, int nTyp, LPCWSTR szName, LPCWSTR szVal);
	/*
	系统_置桌面背景 设置桌面壁纸
	szName:图片路径
	nTyp:拉伸方式  0、平铺1、居中2、拉伸3、适应4、填充5、跨区
	*/
	bool XiTong_SetWindowBiZhi(LPCWSTR szPath, int nTyp);
	/*
	系统_重启资源管理器
	*/
	bool XiTong_ChongQiZiyuanguanLiqi();
	/*
	系统_主板发声
	*/
	void XiTong_ZhuBanFasheng(DWORD dwPinLv, DWORD dwMs);
	/*
	系统_修改主页地址
	szBase:网页地址
	*/
	bool XiTong_XiuGaiZhuye(LPCWSTR szBase);
	/*
	系统_获取主页地址
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



