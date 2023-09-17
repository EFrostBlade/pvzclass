#pragma once
#include "TemplateEvent.h"

// ���չؿ�����¼�
// �����������¼�ʱ�� Miscellaneous��X���꣬Y����
// ����ֵ�����º��Y����
// ����¼�֮��Y����ᴮ���޸�
class PuzzlePhaseCompleteEvent : public TemplateEvent<std::function<
	int(SPT<PVZ::Miscellaneous>, int, int)>>
{
public:
	PuzzlePhaseCompleteEvent();
	void handle(CONTEXT& context) override;
};

PuzzlePhaseCompleteEvent::PuzzlePhaseCompleteEvent()
{
	address = 0x429980;
}

void PuzzlePhaseCompleteEvent::handle(CONTEXT& context)
{
	auto challenge = MKS<PVZ::Miscellaneous>(PVZ::Memory::ReadMemory<DWORD>(context.Ecx + 4));
	int gridX = context.Eax;
	int gridY = PVZ::Memory::ReadMemory<DWORD>(context.Esp + 4);
	for (int i = 0; i < listeners.size(); i++)
	{
		gridY = listeners[i](challenge, gridX, gridY);
	}
	PVZ::Memory::WriteMemory<DWORD>(context.Esp + 4, gridY);
}