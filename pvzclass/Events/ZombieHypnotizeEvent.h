#pragma once
#include "TemplateEvent.h"

// ��ʬ���Ȼ��¼�
// �����������¼��Ľ�ʬ
// �޷���ֵ
class ZombieHypnotizeEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ZombieHypnotizeEvent();
	void handle(CONTEXT& context) override;
};

ZombieHypnotizeEvent::ZombieHypnotizeEvent()
{
	address = 0x52FA60;
}

void ZombieHypnotizeEvent::handle(CONTEXT& context)
{
	auto zombie = std::make_shared<PVZ::Zombie>(context.Esi);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](zombie);
	}
}