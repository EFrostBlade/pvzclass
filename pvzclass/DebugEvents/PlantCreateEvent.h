#pragma once
#include "BaseEvent.h"

// ֲ�ﴴ���¼�
// �����������¼���ֲ��
// �޷���ֵ
class PlantCreateEvent : public BaseEvent<std::function<
	void(std::shared_ptr<PVZ::Plant>)>>
{
public:
	PlantCreateEvent();
	bool handle(DebugEventHandler handler);
};

PlantCreateEvent::PlantCreateEvent()
{
	address = 0x40D190;
}

bool PlantCreateEvent::handle(DebugEventHandler handler)
{
	if (handler.context.Eip != address) return false;
	auto plant = std::make_shared<PVZ::Plant>(handler.context.Eax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](plant);
	}
	afterHandle(handler);
	return true;
}
