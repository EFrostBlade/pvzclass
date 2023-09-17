#pragma once
#include "TemplateEvent.h"

// ��ʬ�����������¼�
// �����������¼��Ľ�ʬ
// �޷���ֵ
class ZombieButterEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ZombieButterEvent();
	void handle(CONTEXT& context) override;
};

ZombieButterEvent::ZombieButterEvent()
{
	address = 0x5326D0;
}

void ZombieButterEvent::handle(CONTEXT& context)
{
	auto zombie = std::make_shared<PVZ::Zombie>(context.Eax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](zombie);
	}
}