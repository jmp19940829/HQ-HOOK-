#pragma once
#include "hongdingyi.h"
typedef UINT_PTR        SOCKET;
// 1、服务端指针 2、客户端的socket 3、1客户端进入 2数据到达3客端断开连接
//4、封包地址，5、封包长度 6、该服务端目前连接的总数
typedef void(__stdcall * tcp_fun)(HANDLE Server, SOCKET so, int type, char* buf, int len, int count);
// 1、客户端 2、服务端socket 3、1客户端进入 2数据到达3客端断开连接
//4、封包地址，5、封包长度
typedef void(__stdcall* tcp_fun_client)(HANDLE Client, SOCKET so, int type, char* buf, int len);


class PORTDLLCLASS TCP_Client
{
public:
	TCP_Client();
	virtual ~TCP_Client();
public:
	/*
	初始化客户端
	funClient：tcp_fun_client  回调函数 用来接受服务器发来的数据
	返回值：成功返回0
	*/
	int InitiaClinet(tcp_fun_client funClient);
	/*
	连接服务器
	szIp：服务器IP
	Port：服务器端口
	bIs：是否配套模式 默认false
	返回值：返回服务器的连接句柄 失败返回0
	*/
	HANDLE CreateClient(char* szIp, short Port,bool bIs=false);
	/*
	向服务器发送数据
	so：服务端句柄
	buf:发送的内容
	len:发送多少字节
	返回值：成功返回true
	*/
	bool Send(HANDLE so, char* buf, int len);
	/*
	断开与服务端的连接
	so：服务器句柄
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
	初始化服务端
	funClient：tcp_fun_client  回调函数 用来接受客户端发来的数据
	返回值：成功返回0
	*/
	int InitiaServer(tcp_fun funServer);
	/*
	创建服务端
	szIp：服务器ip
	Port：服务器端口
	bIs：是否配套通用默认false
	*/
	bool CreateServer(char* szIp,short Port,bool bIs = false );
	/*
	断开与指定客户端连接
	so:客户端得SOCKET
	*/
	bool closeClinet(SOCKET so);
	/*
	获取客户端信息
	handle：客户端HANDLE
	so：客户端得SOCKET
	szIp：OUT 输出IP
	port：OUT输出端口
	*/
	bool GetClinetData(HANDLE handle ,SOCKET so,OUT char* szIp,OUT short* port);
	/*
	向客户端发送数据
	sso：客户端句柄
	so:客户端SOCKET
	buf:发送的内容
	len:发送多少字节
	返回值：成功返回true
	*/
	bool Send(HANDLE sso, SOCKET so, char* buf, int len);
	/*
	获取主机ip
	*/
	bool GetCurrenServerIp(OUT char* szIp);
};

