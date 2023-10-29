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
	void handle(CONTEXT& context) override;
};

ZombieBlastEvent::ZombieBlastEvent()
{
	address = 0x532B70;
}

#if defined(_WIN64)
void ZombieBlastEvent::handle(CONTEXT& context)
{
	auto zombie = std::make_shared<PVZ::Zombie>(context.Rcx);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](zombie);
	}
}
#else
void ZombieBlastEvent::handle(CONTEXT& context)
{
	auto zombie = std::make_shared<PVZ::Zombie>(context.Ecx);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](zombie);
	}
}
#endif