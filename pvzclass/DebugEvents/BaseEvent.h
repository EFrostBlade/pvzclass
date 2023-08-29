#pragma once
#include "../PVZ.h"
#include "DebugEventHandler.h"
#include <iostream>
#include <vector>
#include <functional>

template <class FunctionType> class BaseEvent
{
public:
	void start();
	void addListener(FunctionType listener);
	// ��������¼��������Ƿ��Ǹ��¼��������ж�
	virtual bool handle(DebugEventHandler handler) = 0;
	void end();
protected:
	DWORD address;
	BYTE raw;
	std::vector<FunctionType> listeners;
	void afterHandle(DebugEventHandler handler);
};

template<class FunctionType>
void BaseEvent<FunctionType>::addListener(FunctionType listener)
{
	listeners.push_back(listener);
}

template<class FunctionType>
void BaseEvent<FunctionType>::start()
{
	raw = PVZ::Memory::ReadMemory<BYTE>(address);
	PVZ::Memory::WriteMemory<BYTE>(address, 0xCC);
}

template<class FunctionType>
void BaseEvent<FunctionType>::afterHandle(DebugEventHandler handler)
{
	PVZ::Memory::WriteMemory<BYTE>(address, raw);
	handler.singleStep();
	PVZ::Memory::WriteMemory<BYTE>(address, 0xCC);
}

template<class FunctionType>
void BaseEvent<FunctionType>::end()
{
	PVZ::Memory::WriteMemory<BYTE>(address, raw);
}