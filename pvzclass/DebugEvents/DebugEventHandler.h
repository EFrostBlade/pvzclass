#pragma once
#include "../PVZ.h"
#include "BaseEvent.h"
#include <vector>

class DebugEventHandler
{
private:
	void getContext();
	void setContext();

public:
	DEBUG_EVENT debugEvent;
	CONTEXT context;

	// ��ʼ����PVZ���̣�����һС�ο���
	void start();

	// �ȴ�����ms��ʱ�䣬�����Ƿ����ϵͳ�ж�
	// ms����Ϊ1��������-1�������޵ȴ�
	// �������ֵΪtrue����Ҫ����handle()��resume()
	bool run(int ms);

	// ��PVZ����ִ��һ���������Ҫ�����������
	void singleStep();

	// �ָ�PVZ�����У���Ҫ��handle()�����
	void resume();
	
	// ֹͣ����PVZ����
	void stop();
};

void DebugEventHandler::getContext()
{
	context.ContextFlags = CONTEXT_ALL;
	HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, true, debugEvent.dwThreadId);
	GetThreadContext(hThread, &context);
	CloseHandle(hThread);
}

void DebugEventHandler::setContext()
{
	HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, true, debugEvent.dwThreadId);
	SetThreadContext(hThread, &context);
	CloseHandle(hThread);
}

void DebugEventHandler::start()
{
	DebugActiveProcess(PVZ::Memory::processId);
	WaitForDebugEvent(&debugEvent, -1);
	ContinueDebugEvent(debugEvent.dwProcessId, debugEvent.dwThreadId, DBG_CONTINUE);
}

bool DebugEventHandler::run(int ms)
{
	WaitForDebugEvent(&debugEvent, ms);
	if (debugEvent.dwDebugEventCode != EXCEPTION_DEBUG_EVENT)
	{
		ContinueDebugEvent(debugEvent.dwProcessId, debugEvent.dwThreadId, DBG_CONTINUE);
		return false;
	}
	getContext();
	context.Eip--;
	return true;
}

void DebugEventHandler::singleStep()
{
	context.EFlags |= 0x100;
	setContext();
	ContinueDebugEvent(debugEvent.dwProcessId, debugEvent.dwThreadId, DBG_CONTINUE);
	WaitForDebugEvent(&debugEvent, -1);
}

void DebugEventHandler::resume()
{
	ContinueDebugEvent(debugEvent.dwProcessId, debugEvent.dwThreadId, DBG_CONTINUE);
}

void DebugEventHandler::stop()
{
	DebugActiveProcessStop(PVZ::Memory::processId);
}