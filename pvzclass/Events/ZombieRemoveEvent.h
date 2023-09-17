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
	bool handle(EventHandler handler);
};

ZombieRemoveEvent::ZombieRemoveEvent()
{
	address = 0x530510;
}

bool ZombieRemoveEvent::handle(EventHandler handler)
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