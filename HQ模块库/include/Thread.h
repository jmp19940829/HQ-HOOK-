#pragma once
      
//�ṩ�̲߳�����
class PORTDLLCLASS hqThread
{
public:
	hqThread();
	virtual ~hqThread();
public:
	/*
	�����߳� (���Ƿ�װ��CreateThread)
	lpfun:�߳�ִ�е�ַ
	lpData:����Ĭ��NULL
	dwCreationFlags���������CREATE_SUSPENDED ���Թ���ʽ���� 0����ִ��
	��������:ʣ�µľ���鿴MSDN CreateThread
	����ֵ���ɹ������߳̾��
	*/
	HANDLE Thread(LPTHREAD_START_ROUTINE lpFun, LPVOID lpData = NULL, DWORD dwCreationFlags = 0, LPSECURITY_ATTRIBUTES lpThreadAttributes = 0, SIZE_T dwStackSize = 0, LPDWORD lpThreadId = NULL);
	/*
	ִ���߳�
	handle��Ҫִ�е��߳̾��
	*/
	bool Resume(HANDLE handle);
	/*
	�����߳�
	handle��Ҫִ�е��߳̾��
	*/
	bool Suspend(HANDLE handle);
	/*
	�����߳����ȼ�
	handle:�߳̾��
	nPriority:
	THREAD_PRIORITY_IDLE//��
	THREAD_PRIORITY_LOWEST//�ϵ����ȼ�
	THREAD_PRIORITY_BELOW_NORMAL//�����ȼ�
	THREAD_PRIORITY_NORMAL//��׼ ����������̴߳����Ǵ˱�׼
	THREAD_PRIORITY_ABOVE_NORMAL//���ڱ�׼
	THREAD_PRIORITY_HIGHEST//�ϸ߱�׼
	THREAD_PRIORITY_TIME_CRITICAL//ʵʱ
	*/
	bool SetPriority(HANDLE handle, int nPriority);
	/*
	��ȡ�߳����ȼ�
	handle:�߳̾��
	*/
	int GetPriority(HANDLE handle);
	/*
	�����߳��������Ǹ�CPU����
	handle:�߳̾��
	dwMaks���̵߳��׺������롣
	*/
	bool SetCpu(HANDLE handle, DWORD_PTR dwMaks);
	/*
	��ȡ��ǰ�����̵߳�Ψһ�̱߳�ʶ��(�߳�ID)��
	����ֵ���ɹ����ص�ǰ�����̵߳ı�ʶ��ID��
	*/
	DWORD GetCurrenThreadId();
	/*
	ȡ��ǰ�����߳̾����ֻҪ��ǰ�߳���Ҫʹ��һ���߳̾�����Ϳ���ʹ�����α���
	���������������߳��ж���Ч����
	�þ�����Ը��ƣ������ɼ̳С����ص���CloseHandle�������ر�������
	����ֵ�������߳�α���
	*/
	HANDLE GetCurrenThreadHandle();
	/*
	ʹ��ǰ�뱣֤�߳��Ѿ�������ϣ����߳���δ�жϽ�����STILLACTIVE(ֵΪ259)��
	����ֵ�������̷߳���ֵ
	*/
	DWORD GetThreadRetVal(HANDLE handle);
	/*
	��ȡ�߳�״̬
	����ֵ��0=�߳��ѽ���  1=�߳���������  -1=�߳̾����ʧЧ������
	*/
	DWORD GetState(HANDLE handle);
	/*
	�߳��¼��ȴ�
	handle:�߳̾��
	dwTime:Ը��ȴ��¼� (����) Ĭ��-1 һֱ�ȴ� ֱ���̷߳��ػ�ָ���¼�������
	����ֵ������0 ˵���ȴ����󱻴��� ����258 ˵���ȴ���ʱ����  ����-1 ˵�������Ч
	*/
	DWORD WaitForSing(HANDLE handle, DWORD dwTime = INFINITE);
	/*
	�߳��¼���ȴ�
	handle:�߳̾������
	nSize���߳̾����������
	dwTime:Ը��ȴ��¼� (����) Ĭ��-1 һֱ�ȴ� ֱ���̷߳��ػ�ָ���¼�������
	bIs��Ĭ��ΪTRUE �ȴ������̷߳��� ���ŷ��� FALSE ֻҪ����һ���̷߳��� �ͷ���
	����ֵ������0 ˵���ȴ����󱻴��� ����258 ˵���ȴ���ʱ����  ����-1 ˵�������Ч
	(���bIs������FALSE ��ô�����صĲ���258��-1 ��ô����ֵ���Ǿ��������±� �������������ĸ��̻߳��¼�������)
	*/

	DWORD WaitForMultip(HANDLE* phandle, int nSize, DWORD dwTime = INFINITE, BOOL bIs = TRUE);
	/*
	�ͷ��߳̾��
	handle:�ͷ��߳̾��
	*/
	void clear(HANDLE handle);

public:
	HANDLE m_hqHandle;//�߳̾��
};
//�ṩ�߳�ͬ��ԭ�Ӳ�����
class PORTDLLCLASS Atomic
{
public:
	Atomic();
	virtual~Atomic();
public:
	/*
	���ṩ�������ͱ�������:dwVal�����߳���ʹ�ÿɱ��⸳ֵ��ͻ��
	lpData:������ַ
	dwVal��ÿ�����Ӷ���
	����ֵ������û����ǰ����ֵ
	*/
	DWORD AtomicAdd(LPVOID lpData, DWORD dwVal);
	/*
	���ṩ�������ͱ���+1�����߳���ʹ�ÿɱ��⸳ֵ��ͻ��
	lpData:������ַ
	����ֵ������û����ǰ����ֵ
	*/
	DWORD AtomicAdd(LPVOID lpData);
	/*
	���ṩ�������ͱ�������:dwVal�����߳���ʹ�ÿɱ��⸳ֵ��ͻ��
	lpData:������ַ
	dwVal��ÿ�μ��ٶ���
	����ֵ������û����ǰ����ֵ
	*/
	DWORD AtomicSub(LPVOID lpData, DWORD dwVal);
	/*
	���ṩ�������ͱ���-1�����߳���ʹ�ÿɱ��⸳ֵ��ͻ��
	lpData:������ַ
	����ֵ������û����ǰ����ֵ
	*/
	DWORD AtomicSub(LPVOID lpData);
	/*
	ָ�븳ֵ
	lpObjNum��Ҫ��ֵ��ָ��
	lpData:Ҫ�滻��ָ��
	����ֵ������ԭ����ָ��
	*/
	LPVOID AtomicMovBaseAddess(LPVOID* lpObjNum, LPVOID lpData);
	/*
	��ֵ��ֵ
	lpObjNum��Ҫ��ֵ��������ַ
	dwValue��Ҫ��ֵ��ֵ
	����ֵ������ԭ������ֵ
	*/
	DWORD_PTR AtomicMovVal(LPVOID lpObjNum, DWORD_PTR dwValue);
};
//�ṩ�߳�ͬ���ٽ���������(�������������Ҫ��֤����ȷ���߳���ȫ������������ͷŵ�  ����ֱ��newȫ�� ��ȫ����)
class PORTDLLCLASS Paragraph
{
public:
	/*
	��ʼ���ٽ���
	*/
	Paragraph();
	/*
	��ʼ���ٽ�����������ת�� (�˷������Լ���CPU����Դ�˷�)
	dwSpinCount����ת��ѭ������ 0-0xFFFFFF �Ƽ�4000
	*/
	Paragraph(DWORD dwSpinCount);
	virtual ~Paragraph();
public:
	/*
	������ת��ѭ������
	dwSpinCount����ת��ѭ������ 0-0xFFFFFF �Ƽ�4000
	����ֵ��������ǰ��ѭ������
	*/
	DWORD SetCriticalSpinCount(DWORD dwSpinCount);

	/*
	�����ٽ��� ��ȡ����Ȩ
	*/
	void Lock();
	/*
	�뿪�ٽ��� ��������Ȩ
	*/
	void unLock();
	/*
	���Խ����ٽ��� �����ȡ������Ȩ ����TRUE ����false ����TRUE �������Ӧ��unLock()
	����ֵ������true ˵�����Խ��� ����flase˵�������Խ���
	*/
	bool TryEnter();
	/*
	�ͷ��ٽ��� ������Ҳ���� �����������������������
	*/
	void clear();
private:
	CRITICAL_SECTION m_Ritical;
};
//�ṩ�ں��¼�������
class PORTDLLCLASS Event
{
public:
	Event();
	/*
	��ʼ���������¼�
	bIsManual���Ƿ����ֶ������¼� TRUEΪ�ֶ����� ���ڵȴ��������̱߳�Ϊ�ɵ���״̬ FALSE �Զ�����ֻ��һ���ȴ���\
	�̱߳����������������ֽ��¼���Ϊδ����״̬��
	bIs���Ƿ��¼���ʼ��Ϊ����״̬ TRUE Ĭ��FALSEδ����״̬
	szName:ָ���¼��Ķ�������ƣ���һ����0�������ַ���ָ�롣���Ƶ��ַ���ʽ�޶���255֮�ڡ������ǶԴ�Сд���еġ�
	*/
	Event(BOOL bIsManual, BOOL bIs = FALSE, LPWSTR szName = NULL);
	virtual~Event();
public:
	/*
	�����¼�
	bIsManual���Ƿ����ֶ������¼� Ĭ��ΪTRUE �ֶ����� ���ڵȴ��ġ������̡߳���Ϊ�ɵ���״̬��FALSE �Զ�����ֻ�С�һ���ȴ�����\
	�̱߳����������������ֽ��¼���Ϊδ����״̬��
	bIs���Ƿ��¼���ʼ��Ϊ����״̬ TRUE Ĭ��FALSEδ����״̬
	szName:ָ���¼��Ķ�������ƣ���һ����0�������ַ���ָ�롣���Ƶ��ַ���ʽ�޶���255֮�ڡ������ǶԴ�Сд���еġ�
	����ֵ���ɹ������¼����
	*/
	HANDLE Create(BOOL bIsManual = TRUE, BOOL bIs = FALSE, LPWSTR szName = NULL);
	/*
	���¼����
	bIs���Ƿ��¼���ʼ��Ϊ����״̬ TRUE Ĭ��FALSEδ����״̬
	szName:ָ��Ҫ�򿪵��¼��Ķ�������ƣ���һ����0�������ַ���ָ�롣���Ƶ��ַ���ʽ�޶���255֮�ڡ������ǶԴ�Сд���е�
	����ֵ���ɹ������¼����
	*/
	HANDLE Open(BOOL bIs, LPWSTR szName);

	/*
	��ȡ�¼����
	*/
	HANDLE GetHandle();
	/*
	����Ϊ�����¼�
	handle:�¼����
	*/
	BOOL Touch(HANDLE handle);
	/*
	����Ϊ�����¼�
	*/
	BOOL Touch();
	/*
	����Ϊδ����
	handle:�¼����
	*/
	BOOL Reset(HANDLE handle);
	/*
	����Ϊδ����
	*/
	BOOL Reset();
	/*
	�ȴ�������/ӵ�����Event�¼�����
	handle��ָ���¼����
	dwTime: ��ʱʱ�䵥λ:���룬 Ĭ��Ϊ -1 ���޵ȴ���
	����ֵ���ɹ������棬ʧ��/��ʱ/�����Ч���ؼ١�
	*/
	BOOL  Waiting(HANDLE handle, DWORD dwTime = INFINITE);
	/*
	��ǰ���¼��ȴ�����
	dwTime: ��ʱʱ�䵥λ:���룬 Ĭ��Ϊ -1 ���޵ȴ���
	����ֵ���ɹ������棬ʧ��/��ʱ/�����Ч���ؼ١�
	*/
	BOOL  Waiting(DWORD dwTime = INFINITE);
	/*
	�ͷ��¼����
	handle:�¼����
	*/
	void clear(HANDLE handle);
	Event& operator[](int Index);
private:
	HANDLE m_hEvent;
};
//�ṩ�ں˶�ʱ��������
class PORTDLLCLASS Calculagraph
{
public:
	Calculagraph();
	virtual~Calculagraph();
public:
	/*
	�����ɵȴ���ʱ������
	bIsManual���Ƿ����ֶ������¼� TRUEΪ�ֶ����� ���ڵȴ��������̱߳�Ϊ�ɵ���״̬ FALSE �Զ�����ֻ��һ���ȴ���\
	�̱߳����������������ֽ��¼���Ϊδ����״̬��
	szName:ָ���¼��Ķ�������ƣ���һ����0�������ַ���ָ�롣���Ƶ��ַ���ʽ�޶���255֮�ڡ������ǶԴ�Сд���еġ�
	����ֵ�����ؼ�ʱ�����
	*/
	HANDLE Create(BOOL bIsManual = FALSE, LPWSTR szName = NULL);
	/*
	��һ���ɵȴ���ʱ������
	bIsManual���Ƿ����ֶ������¼� TRUEΪ�ֶ����� ���ڵȴ��������̱߳�Ϊ�ɵ���״̬ FALSE �Զ�����ֻ��һ���ȴ���\
	�̱߳����������������ֽ��¼���Ϊδ����״̬��
	szName:ָ���¼��Ķ�������ƣ���һ����0�������ַ���ָ�롣���Ƶ��ַ���ʽ�޶���255֮�ڡ������ǶԴ�Сд���еġ�
	����ֵ�����ؼ�ʱ�����
	*/
	HANDLE Open(BOOL bIsManual, LPWSTR szName);
	/*
	������ʱ��
	handle��Ҫ������ʱ���ľ��
	syTime:������ʱ����ʱ�� ϵͳ����ʱ��Ϊ׼
	lInterval��������Ĵ�����Ƶ�ʼ��(����Ϊ��λ) ���Ϊ0 ����ֻ����һ��
	pApc��apc�ص�����
	pvArg������Ĳ���
	bIs:ͨ���������ΪĬ�ϲ���false ���ΪTRUE ��ʱ�������� ��ôϵͳ��ʹ������������ģʽ������һ���ȴ��е��߳�
	����ֵ���ɹ�����TRUE����false
	*/
	BOOL SetWaitTimer(HANDLE handle, SYSTEMTIME syTime, LONG lInterval, PTIMERAPCROUTINE pApc = NULL, PVOID pvArg = NULL, BOOL bIs = FALSE);

	/*
	������ʱ��
	handle��Ҫ������ʱ���ľ��
	nTimeNum:�������óɹ�����ٺ���󴥷�
	lInterval��������Ĵ�����Ƶ�ʼ��(����Ϊ��λ)
	pApc��apc�ص�����
	pvArg������Ĳ���
	bIs:ͨ���������ΪĬ�ϲ���false ���ΪTRUE ��ʱ�������� ��ôϵͳ��ʹ������������ģʽ������һ���ȴ��е��߳�
	����ֵ���ɹ�����TRUE����false
	*/
	BOOL SetWaitTimer(HANDLE handle, int nTimeNum, LONG lInterval, PTIMERAPCROUTINE pApc = NULL, PVOID pvArg = NULL, BOOL bIs = FALSE);
	/*
	�ȴ�һ����ʱ������
	handle����ʱ���ľ��
	dwTime:dwTime: ��ʱʱ�䵥λ:���룬 Ĭ��Ϊ -1 ���޵ȴ���
	����ֵ���ɹ������棬ʧ��/��ʱ/�����Ч���ؼ١�
	*/
	BOOL WaitTime(HANDLE handle, DWORD dwTime = INFINITE);

	/*
	ɱ��һ���ں˼�ʱ��
	handle:Ҫɱ���ļ�ʱ�����
	����ֵ���ɹ�����TRUE ����FALSE
	*/
	BOOL KillWatuTime(HANDLE handle);

public:
	HANDLE m_Handle;
};
//�ṩ�ź���������
class PORTDLLCLASS Senaphore
{
public:
	Senaphore();
	/*
	��ʼ���������ź���
	dwInitVal:��ʼ�ź���
	dwMax������ź��� Ĭ��1
	szName���ź�����ʶ������Ĭ��NULL
	*/
	Senaphore(DWORD dwInitVal, DWORD dwMax = 1, LPWSTR szName = NULL);
	~Senaphore();
public:
	/*
	�����ź���
	dwInitVal:��ʼ�ź��� Ĭ��0
	dwMax������ź��� Ĭ��1
	szName���ź�����ʶ������Ĭ��NULL
	����ֵ���ɹ�����TRUE
	*/
	BOOL Create(DWORD dwInitVal = 0, DWORD dwMax = 1, LPWSTR szName = NULL);
	/*
	���ź���
	szName���ź�����ʶ��
	����ֵ���ɹ�����TRUE
	*/
	BOOL Open(LPWSTR szName);
	/*
	�������ڲ��ź������
	handle:Ҫ���õ��ź������
	*/
	VOID SetSenaphoreHandle(HANDLE handle);
	/*
	�����ź���
	dwAddVal��Ҫ���Ӷ����ź��� Ĭ������1
	dwRetOriVal����������ǰ���ź������� Ĭ��NULL
	����ֵ���ɹ�����TRUE ����FALSE
	*/
	BOOL AddSemap(DWORD dwAddVal = 1, LONG* dwRetOriVal = NULL);
	/*
	�ȴ��ź��� ������1�ź���
	dwTime���ȴ�ʱ�� �����룩
	����ֵ������TREU ˵���ȴ��ɹ� ���� ������ִ��ʧ�� �� �ȴ���ʱ
	*/
	BOOL SubSemap(DWORD dwTime = INFINITE);
	/*
	��ȡ�ź������
	����ֵ�������ź������
	*/
	HANDLE GetSenapHandle();
	/*
	�ͷ��ź������
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
	��ʼ��������������
	bIs:
	szName:һ���ַ�����ʶ��
	*/
	Mutex(BOOL bIs, LPWSTR szName=NULL);
	Mutex();
	~Mutex();
public:
	/*
	����������
	bIs:ͨ��ΪFALSE Ĭ��ҲΪFALSE ˵�����ⲻ���κ��߳�ӵ�У�TRUEδ����״̬
	szName:һ���ַ�����ʶ��
	����ֵ���ɹ�����TRUE 
	*/
	BOOL Create(BOOL bIs=FALSE, LPWSTR szName=NULL);
	/*
	�򿪻�����
	bIs:ͨ��ΪFALSE Ĭ��ҲΪFALSE ˵�����ⲻ���κ��߳�ӵ�У�TRUEδ����״̬
	szName:һ���ַ�����ʶ��
	����ֵ���ɹ�����TRUE
	*/
	BOOL Open(BOOL bIs, LPWSTR szName);
	/*
	��ȡ���������
	����ֵ���ɹ����ػ��������
	*/
	HANDLE GetMutexHandle();
	/*
	���û���������
	handle:Ҫ���õû��������
	*/
	VOID SetMuteHandle(HANDLE handle);
	/*
	�뿪����
	*/
	BOOL Leave();
	/*
	���뻥��
	*/
	BOOL Enter(DWORD dwTime=INFINITE);
	/*
	�ͷŻ�������� 
	*/
	void clear();
	Mutex& operator[](int Index);
private:
	HANDLE m_Mutex;
};


