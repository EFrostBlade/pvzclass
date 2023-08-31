#pragma once
#include "BaseEvent.h"

// ���չؿ�����¼�
// �����������¼�ʱ�� Miscellaneous��X���꣬Y����
// ����ֵ�����º��Y����
// ����¼�֮��Y����ᴮ���޸�
class PuzzlePhaseCompleteEvent : public BaseEvent<std::function<
	int(SPT<PVZ::Miscellaneous>, int, int)>>
{
public:
	PuzzlePhaseCompleteEvent();
	bool handle(EventHandler handler);
};

PuzzlePhaseCompleteEvent::PuzzlePhaseCompleteEvent()
{
	address = 0x429980;
}

bool PuzzlePhaseCompleteEvent::handle(EventHandler handler)
{
	if (handler.context.Eip != address) return false;
	auto challenge = MKS<PVZ::Miscellaneous>(PVZ::Memory::ReadMemory<DWORD>(handler.context.Ecx + 4));
	int gridX = handler.context.Eax;
	int gridY = PVZ::Memory::ReadMemory<DWORD>(handler.context.Esp + 4);
	for (int i = 0; i < listeners.size(); i++)
	{
		gridY = listeners[i](challenge, gridX, gridY);
	}
	PVZ::Memory::WriteMemory<DWORD>(handler.context.Esp + 4, gridY);
	afterHandle(handler);
	return true;
}