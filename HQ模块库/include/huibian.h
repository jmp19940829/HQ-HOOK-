#pragma once
#include "hongdingyi.h"
class PORTDLLCLASS huibian :
	public MemOry
{
public:
	huibian();
	virtual ~huibian();
public:
	/*
	���ȡ�����
	����ֵ�����������
	*/
	DWORD asm_GetRandom();
};

