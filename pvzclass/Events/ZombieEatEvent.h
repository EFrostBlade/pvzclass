#pragma once
#include "TemplateEvent.h"

// ��ʬ��ʳֲ���¼�
// �����������¼��Ľ�ʬ��ֲ��
// �޷���ֵ
class ZombieEatEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>, std::shared_ptr<PVZ::Plant>)>>
{
public:
	ZombieEatEvent();
	void handle(CONTEXT& context) override;
};

ZombieEatEvent::ZombieEatEvent()
{
	address = 0x52F689;
}

void ZombieEatEvent::handle(CONTEXT& context)
{
	auto zombie = std::make_shared<PVZ::Zombie>(context.Edi);
	auto plant = std::make_shared<PVZ::Plant>(context.Ecx);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](zombie, plant);
	}
}