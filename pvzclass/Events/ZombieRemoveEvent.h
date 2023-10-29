#pragma once
#include "TemplateEvent.h"

// ��ʬ���Ƴ��¼�
// �����������¼��Ľ�ʬ
// �޷���ֵ
// ��ʬ���Ƴ���ԭ����ֶ�������ʹ�ǹؿ���ʬԤ������Ľ�ʬ���Ƴ�Ҳ�ᴥ�����¼�
class ZombieRemoveEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ZombieRemoveEvent();
	void handle(CONTEXT& context) override;
};

ZombieRemoveEvent::ZombieRemoveEvent()
{
	address = 0x530510;
}

#if defined(_WIN64)
void ZombieRemoveEvent::handle(CONTEXT& context)
{
	auto zombie = std::make_shared<PVZ::Zombie>(context.Rcx);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](zombie);
	}
}
#else
void ZombieRemoveEvent::handle(CONTEXT& context)
{
	auto zombie = std::make_shared<PVZ::Zombie>(context.Ecx);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](zombie);
	}
}
#endif