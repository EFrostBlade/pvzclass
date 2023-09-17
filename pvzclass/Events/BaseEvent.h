#pragma once
#include "../PVZ.h"
#include <iostream>
#include <vector>

class BaseEvent
{
public:
	DWORD address;
	BYTE raw;
	// ��ʼ��������¼�������Ҫ�û�����
	void start();
	// �����¼�������Ҫ�û�����
	virtual void handle(CONTEXT& context);
	// �����¼�������Ҫ�û�����
	void end();
	BaseEvent();
};

BaseEvent::BaseEvent()
{
	address = 0;
	raw = 0;
}

void BaseEvent::start()
{
	raw = PVZ::Memory::ReadMemory<BYTE>(address);
	PVZ::Memory::WriteMemory<BYTE>(address, 0xCC);
}

void BaseEvent::end()
{
	PVZ::Memory::WriteMemory<BYTE>(address, raw);
}

void BaseEvent::handle(CONTEXT& context)
{
	std::cout << "������BaseEvent��handle()���ⲻӦ�÷�����\n";
}