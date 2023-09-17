#pragma once
#include "TemplateEvent.h"

// ��ʬ�ҽ��¼�
// �����������¼��Ľ�ʬ
// �޷���ֵ
// ��ʬ�ܵ��ҽ��˺��ͻᴥ��
class ZombieBlastEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ZombieBlastEvent();
	bool handle(EventHandler handler);
};

ZombieBlastEvent::ZombieBlastEvent()
{
	address = 0x532B70;
}

bool ZombieBlastEvent::handle(EventHandler handler)
{
	if (handler.context.Eip != address) return false;
	auto zombie = std::make_shared<PVZ::Zombie>(handler.context.Ecx);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](zombie);
	}
	afterHandle(handler);
	return true;
}