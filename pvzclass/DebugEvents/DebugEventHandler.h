#pragma once
#include "../PVZ.h"
#include "BaseEvent.h"
#include <vector>
#include <iostream>

class DebugEventHandler
{
private:
	void failLog(int line, const char* message);
	void getContext();
	void setContext();
	void continueDebug(int line);
	void waitDebugInfinity(int line);
	HANDLE getThread(int line);
	void closeThread(HANDLE hThread, int line);

public:
	DEBUG_EVENT debugEvent;
	CONTEXT context;

	// 开始调试PVZ进程，会有一小段卡顿
	void start();

	// 等待至多ms的时间，返回是否出现系统中断
	// ms至少为1，可以用-1代表无限等待
	// 如果返回值为true，需要调用handle()和resume()
	bool run(int ms);

	// 令PVZ单步执行一个命令，不需要调用这个函数
	void singleStep();

	// 恢复PVZ的运行，需要在handle()后调用
	void resume();
	
	// 停止调试PVZ进程
	void stop();
};

void DebugEventHandler::failLog(int line, const char* message)
{
	std::cout << "[ERROR] line " << line << ": " << message << "\n";
	system("pause");
	exit(-1);
}

void DebugEventHandler::getContext()
{
	context.ContextFlags = CONTEXT_ALL;
	HANDLE hThread = getThread(__LINE__);
	if (!GetThreadContext(hThread, &context))
	{
		failLog(__LINE__, "GetThreadContext failed!");
	}
	closeThread(hThread, __LINE__);
}

void DebugEventHandler::setContext()
{
	HANDLE hThread = getThread(__LINE__);
	if (!SetThreadContext(hThread, &context))
	{
		failLog(__LINE__, "SetThreadContext failed!");
	}
	closeThread(hThread, __LINE__);
}

void DebugEventHandler::continueDebug(int line)
{
	if (!ContinueDebugEvent(debugEvent.dwProcessId, debugEvent.dwThreadId, DBG_CONTINUE))
	{
		failLog(__LINE__, "ContinueDebugEvent failed!");
	}
}

void DebugEventHandler::waitDebugInfinity(int line)
{
	if (!WaitForDebugEvent(&debugEvent, -1))
	{
		failLog(__LINE__, "WaitForDebugEvent failed!");
	}
}

HANDLE DebugEventHandler::getThread(int line)
{
	HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, true, debugEvent.dwThreadId);
	if (hThread == 0)
	{
		failLog(__LINE__, "hThread is 0!");
	}
	return hThread;
}

void DebugEventHandler::closeThread(HANDLE hThread, int line)
{
	if (!CloseHandle(hThread))
	{
		failLog(__LINE__, "CloseHandle failed!");
	}
}

void DebugEventHandler::start()
{
	if (!DebugActiveProcess(PVZ::Memory::processId))
	{
		failLog(__LINE__, "DebugActiveProcess failed!");
	}
	waitDebugInfinity(__LINE__);
	continueDebug(__LINE__);
}

bool DebugEventHandler::run(int ms)
{
	if (!WaitForDebugEvent(&debugEvent, ms))
	{
		return false;
	}
	if (debugEvent.dwDebugEventCode != EXCEPTION_DEBUG_EVENT)
	{
		continueDebug(__LINE__);
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
	continueDebug(__LINE__);
	waitDebugInfinity(__LINE__);
}

void DebugEventHandler::resume()
{
	continueDebug(__LINE__);
}

void DebugEventHandler::stop()
{
	if (!DebugActiveProcessStop(PVZ::Memory::processId))
	{
		failLog(__LINE__, "DebugActiveProcessStop failed!");
	}
}