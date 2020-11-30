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
	汇编取随机数
	返回值：返回随机数
	*/
	DWORD asm_GetRandom();
};

