#pragma once
      
//提供线程操作类
class PORTDLLCLASS hqThread
{
public:
	hqThread();
	virtual ~hqThread();
public:
	/*
	创建线程 (就是封装的CreateThread)
	lpfun:线程执行地址
	lpData:参数默认NULL
	dwCreationFlags：如果设置CREATE_SUSPENDED 是以挂起方式创建 0立即执行
	。。。。:剩下的具体查看MSDN CreateThread
	返回值：成功返回线程句柄
	*/
	HANDLE Thread(LPTHREAD_START_ROUTINE lpFun, LPVOID lpData = NULL, DWORD dwCreationFlags = 0, LPSECURITY_ATTRIBUTES lpThreadAttributes = 0, SIZE_T dwStackSize = 0, LPDWORD lpThreadId = NULL);
	/*
	执行线程
	handle：要执行的线程句柄
	*/
	bool Resume(HANDLE handle);
	/*
	挂起线程
	handle：要执行的线程句柄
	*/
	bool Suspend(HANDLE handle);
	/*
	设置线程优先级
	handle:线程句柄
	nPriority:
	THREAD_PRIORITY_IDLE//低
	THREAD_PRIORITY_LOWEST//较低优先级
	THREAD_PRIORITY_BELOW_NORMAL//低优先级
	THREAD_PRIORITY_NORMAL//标准 多数情况下线程创建是此标准
	THREAD_PRIORITY_ABOVE_NORMAL//高于标准
	THREAD_PRIORITY_HIGHEST//较高标准
	THREAD_PRIORITY_TIME_CRITICAL//实时
	*/
	bool SetPriority(HANDLE handle, int nPriority);
	/*
	获取线程优先级
	handle:线程句柄
	*/
	int GetPriority(HANDLE handle);
	/*
	设置线程运行在那个CPU上面
	handle:线程句柄
	dwMaks：线程的亲和力掩码。
	*/
	bool SetCpu(HANDLE handle, DWORD_PTR dwMaks);
	/*
	获取当前所在线程的唯一线程标识符(线程ID)。
	返回值：成功返回当前所在线程的标识符ID。
	*/
	DWORD GetCurrenThreadId();
	/*
	取当前所在线程句柄。只要当前线程需要使用一个线程句柄，就可以使用这个伪句柄
	（但在其他任务线程中都无效）。
	该句柄可以复制，但不可继承。不必调用CloseHandle函数来关闭这个句柄
	返回值：返回线程伪句柄
	*/
	HANDLE GetCurrenThreadHandle();
	/*
	使用前请保证线程已经运行完毕，如线程尚未中断将返回STILLACTIVE(值为259)。
	返回值：返回线程返回值
	*/
	DWORD GetThreadRetVal(HANDLE handle);
	/*
	获取线程状态
	返回值：0=线程已结束  1=线程正在运行  -1=线程句柄已失效或销毁
	*/
	DWORD GetState(HANDLE handle);
	/*
	线程事件等待
	handle:线程句柄
	dwTime:愿意等待事件 (毫秒) 默认-1 一直等待 直到线程返回或指定事件被处发
	返回值：返回0 说明等待对象被触发 返回258 说明等待超时返回  返回-1 说明句柄无效
	*/
	DWORD WaitForSing(HANDLE handle, DWORD dwTime = INFINITE);
	/*
	线程事件组等待
	handle:线程句柄数组
	nSize：线程句柄数组数量
	dwTime:愿意等待事件 (毫秒) 默认-1 一直等待 直到线程返回或指定事件被触发
	bIs：默认为TRUE 等待所有线程返回 他才返回 FALSE 只要其中一个线程返回 就返回
	返回值：返回0 说明等待对象被触发 返回258 说明等待超时返回  返回-1 说明句柄无效
	(如果bIs参数是FALSE 那么他返回的不是258或-1 那么返回值就是句柄数组的下标 用来告诉你是哪个线程或事件触发的)
	*/

	DWORD WaitForMultip(HANDLE* phandle, int nSize, DWORD dwTime = INFINITE, BOOL bIs = TRUE);
	/*
	释放线程句柄
	handle:释放线程句柄
	*/
	void clear(HANDLE handle);

public:
	HANDLE m_hqHandle;//线程句柄
};
//提供线程同步原子操作类
class PORTDLLCLASS Atomic
{
public:
	Atomic();
	virtual~Atomic();
public:
	/*
	对提供的整数型变量增加:dwVal。多线程中使用可避免赋值冲突。
	lpData:整数地址
	dwVal：每次增加多少
	返回值：返回没增加前的数值
	*/
	DWORD AtomicAdd(LPVOID lpData, DWORD dwVal);
	/*
	对提供的整数型变量+1。多线程中使用可避免赋值冲突。
	lpData:整数地址
	返回值：返回没增加前的数值
	*/
	DWORD AtomicAdd(LPVOID lpData);
	/*
	对提供的整数型变量减少:dwVal。多线程中使用可避免赋值冲突。
	lpData:整数地址
	dwVal：每次减少多少
	返回值：返回没减少前的数值
	*/
	DWORD AtomicSub(LPVOID lpData, DWORD dwVal);
	/*
	对提供的整数型变量-1。多线程中使用可避免赋值冲突。
	lpData:整数地址
	返回值：返回没减少前的数值
	*/
	DWORD AtomicSub(LPVOID lpData);
	/*
	指针赋值
	lpObjNum：要赋值的指针
	lpData:要替换的指针
	返回值：返回原来的指针
	*/
	LPVOID AtomicMovBaseAddess(LPVOID* lpObjNum, LPVOID lpData);
	/*
	数值赋值
	lpObjNum：要赋值的整数地址
	dwValue：要赋值的值
	返回值：返回原来的数值
	*/
	DWORD_PTR AtomicMovVal(LPVOID lpObjNum, DWORD_PTR dwValue);
};
//提供线程同步临界区操作类(此类的生命周期要保证是你确保线程完全结束的情况下释放掉  建议直接new全局 或全局类)
class PORTDLLCLASS Paragraph
{
public:
	/*
	初始化临界区
	*/
	Paragraph();
	/*
	初始化临界区并设置旋转锁 (此方法可以减少CPU的资源浪费)
	dwSpinCount：旋转锁循环次数 0-0xFFFFFF 推荐4000
	*/
	Paragraph(DWORD dwSpinCount);
	virtual ~Paragraph();
public:
	/*
	设置旋转锁循环次数
	dwSpinCount：旋转锁循环次数 0-0xFFFFFF 推荐4000
	返回值：返回先前的循环次数
	*/
	DWORD SetCriticalSpinCount(DWORD dwSpinCount);

	/*
	锁定临界区 获取控制权
	*/
	void Lock();
	/*
	离开临界区 放弃控制权
	*/
	void unLock();
	/*
	尝试进入临界区 如果获取到控制权 返回TRUE 反则false 返回TRUE 必须相对应有unLock()
	返回值：返回true 说明可以进入 返回flase说明不可以进入
	*/
	bool TryEnter();
	/*
	释放临界区 不调用也可以 类最后会调用析构函数来销毁
	*/
	void clear();
private:
	CRITICAL_SECTION m_Ritical;
};
//提供内核事件操作类
class PORTDLLCLASS Event
{
public:
	Event();
	/*
	初始化并创建事件
	bIsManual：是否是手动重置事件 TRUE为手动触发 正在等待的所有线程变为可调度状态 FALSE 自动触发只有一个等待的\
	线程被触发！（触发后又将事件变为未触发状态）
	bIs：是否将事件初始化为触发状态 TRUE 默认FALSE未触发状态
	szName:指定事件的对象的名称，是一个以0结束的字符串指针。名称的字符格式限定在255之内。名字是对大小写敏感的。
	*/
	Event(BOOL bIsManual, BOOL bIs = FALSE, LPWSTR szName = NULL);
	virtual~Event();
public:
	/*
	创建事件
	bIsManual：是否是手动重置事件 默认为TRUE 手动触发 正在等待的《所有线程》变为可调度状态。FALSE 自动触发只有《一个等待》的\
	线程被触发！（触发后又将事件变为未触发状态）
	bIs：是否将事件初始化为触发状态 TRUE 默认FALSE未触发状态
	szName:指定事件的对象的名称，是一个以0结束的字符串指针。名称的字符格式限定在255之内。名字是对大小写敏感的。
	返回值：成功返回事件句柄
	*/
	HANDLE Create(BOOL bIsManual = TRUE, BOOL bIs = FALSE, LPWSTR szName = NULL);
	/*
	打开事件句柄
	bIs：是否将事件初始化为触发状态 TRUE 默认FALSE未触发状态
	szName:指定要打开的事件的对象的名称，是一个以0结束的字符串指针。名称的字符格式限定在255之内。名字是对大小写敏感的
	返回值：成功返回事件句柄
	*/
	HANDLE Open(BOOL bIs, LPWSTR szName);

	/*
	获取事件句柄
	*/
	HANDLE GetHandle();
	/*
	设置为触发事件
	handle:事件句柄
	*/
	BOOL Touch(HANDLE handle);
	/*
	设置为触发事件
	*/
	BOOL Touch();
	/*
	设置为未触发
	handle:事件句柄
	*/
	BOOL Reset(HANDLE handle);
	/*
	设置为未触发
	*/
	BOOL Reset();
	/*
	等待并进入/拥有这个Event事件对象。
	handle：指定事件句柄
	dwTime: 超时时间单位:毫秒， 默认为 -1 无限等待。
	返回值：成功返回真，失败/超时/句柄无效返回假。
	*/
	BOOL  Waiting(HANDLE handle, DWORD dwTime = INFINITE);
	/*
	当前类事件等待进入
	dwTime: 超时时间单位:毫秒， 默认为 -1 无限等待。
	返回值：成功返回真，失败/超时/句柄无效返回假。
	*/
	BOOL  Waiting(DWORD dwTime = INFINITE);
	/*
	释放事件句柄
	handle:事件句柄
	*/
	void clear(HANDLE handle);
	Event& operator[](int Index);
private:
	HANDLE m_hEvent;
};
//提供内核定时器操作类
class PORTDLLCLASS Calculagraph
{
public:
	Calculagraph();
	virtual~Calculagraph();
public:
	/*
	创建可等待计时器对象
	bIsManual：是否是手动重置事件 TRUE为手动触发 正在等待的所有线程变为可调度状态 FALSE 自动触发只有一个等待的\
	线程被触发！（触发后又将事件变为未触发状态）
	szName:指定事件的对象的名称，是一个以0结束的字符串指针。名称的字符格式限定在255之内。名字是对大小写敏感的。
	返回值：返回计时器句柄
	*/
	HANDLE Create(BOOL bIsManual = FALSE, LPWSTR szName = NULL);
	/*
	打开一个可等待计时器对象
	bIsManual：是否是手动重置事件 TRUE为手动触发 正在等待的所有线程变为可调度状态 FALSE 自动触发只有一个等待的\
	线程被触发！（触发后又将事件变为未触发状态）
	szName:指定事件的对象的名称，是一个以0结束的字符串指针。名称的字符格式限定在255之内。名字是对大小写敏感的。
	返回值：返回计时器句柄
	*/
	HANDLE Open(BOOL bIsManual, LPWSTR szName);
	/*
	触发计时器
	handle：要触发计时器的句柄
	syTime:触发计时器的时间 系统本地时间为准
	lInterval：触发后的触发，频率间隔(毫秒为单位) 如果为0 代表只触发一次
	pApc：apc回调函数
	pvArg：传入的参数
	bIs:通常这个参数为默认参数false 如果为TRUE 计时器被触发 那么系统会使机器结束挂起模式并唤醒一个等待中的线程
	返回值：成功返回TRUE否则false
	*/
	BOOL SetWaitTimer(HANDLE handle, SYSTEMTIME syTime, LONG lInterval, PTIMERAPCROUTINE pApc = NULL, PVOID pvArg = NULL, BOOL bIs = FALSE);

	/*
	触发计时器
	handle：要触发计时器的句柄
	nTimeNum:函数调用成功后多少毫秒后触发
	lInterval：触发后的触发，频率间隔(毫秒为单位)
	pApc：apc回调函数
	pvArg：传入的参数
	bIs:通常这个参数为默认参数false 如果为TRUE 计时器被触发 那么系统会使机器结束挂起模式并唤醒一个等待中的线程
	返回值：成功返回TRUE否则false
	*/
	BOOL SetWaitTimer(HANDLE handle, int nTimeNum, LONG lInterval, PTIMERAPCROUTINE pApc = NULL, PVOID pvArg = NULL, BOOL bIs = FALSE);
	/*
	等待一个计时器触发
	handle：计时器的句柄
	dwTime:dwTime: 超时时间单位:毫秒， 默认为 -1 无限等待。
	返回值：成功返回真，失败/超时/句柄无效返回假。
	*/
	BOOL WaitTime(HANDLE handle, DWORD dwTime = INFINITE);

	/*
	杀死一个内核计时器
	handle:要杀死的计时器句柄
	返回值：成功返回TRUE 否则FALSE
	*/
	BOOL KillWatuTime(HANDLE handle);

public:
	HANDLE m_Handle;
};
//提供信号量操作类
class PORTDLLCLASS Senaphore
{
public:
	Senaphore();
	/*
	初始化并创建信号量
	dwInitVal:初始信号量
	dwMax：最大信号量 默认1
	szName：信号量标识符名称默认NULL
	*/
	Senaphore(DWORD dwInitVal, DWORD dwMax = 1, LPWSTR szName = NULL);
	~Senaphore();
public:
	/*
	创建信号量
	dwInitVal:初始信号量 默认0
	dwMax：最大信号量 默认1
	szName：信号量标识符名称默认NULL
	返回值：成功返回TRUE
	*/
	BOOL Create(DWORD dwInitVal = 0, DWORD dwMax = 1, LPWSTR szName = NULL);
	/*
	打开信号量
	szName：信号量标识符
	返回值：成功返回TRUE
	*/
	BOOL Open(LPWSTR szName);
	/*
	设置类内部信号量句柄
	handle:要设置的信号量句柄
	*/
	VOID SetSenaphoreHandle(HANDLE handle);
	/*
	增加信号量
	dwAddVal：要增加多少信号量 默认增加1
	dwRetOriVal：返回增加前的信号量数量 默认NULL
	返回值：成功返回TRUE 否则FALSE
	*/
	BOOL AddSemap(DWORD dwAddVal = 1, LONG* dwRetOriVal = NULL);
	/*
	等待信号量 并减少1信号量
	dwTime：等待时间 （毫秒）
	返回值：返回TREU 说明等待成功 否则 可能是执行失败 或 等待超时
	*/
	BOOL SubSemap(DWORD dwTime = INFINITE);
	/*
	获取信号量句柄
	返回值：返回信号量句柄
	*/
	HANDLE GetSenapHandle();
	/*
	释放信号量句柄
	*/
	void clear();
	Senaphore& operator[](int Index);
private:
	HANDLE m_SenapHandle;

};

class Mutex
{
public:
	/*
	初始化并创建互斥量
	bIs:
	szName:一个字符串标识符
	*/
	Mutex(BOOL bIs, LPWSTR szName=NULL);
	Mutex();
	~Mutex();
public:
	/*
	创建互斥量
	bIs:通常为FALSE 默认也为FALSE 说明互斥不被任何线程拥有！TRUE未触发状态
	szName:一个字符串标识符
	返回值：成功返回TRUE 
	*/
	BOOL Create(BOOL bIs=FALSE, LPWSTR szName=NULL);
	/*
	打开互斥量
	bIs:通常为FALSE 默认也为FALSE 说明互斥不被任何线程拥有！TRUE未触发状态
	szName:一个字符串标识符
	返回值：成功返回TRUE
	*/
	BOOL Open(BOOL bIs, LPWSTR szName);
	/*
	获取互斥量句柄
	返回值：成功返回互斥量句柄
	*/
	HANDLE GetMutexHandle();
	/*
	设置互斥量类句柄
	handle:要设置得互斥量句柄
	*/
	VOID SetMuteHandle(HANDLE handle);
	/*
	离开互斥
	*/
	BOOL Leave();
	/*
	进入互斥
	*/
	BOOL Enter(DWORD dwTime=INFINITE);
	/*
	释放互斥量句柄 
	*/
	void clear();
	Mutex& operator[](int Index);
private:
	HANDLE m_Mutex;
};


