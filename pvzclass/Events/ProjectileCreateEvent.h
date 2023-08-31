#pragma once
#include "BaseEvent.h"

// �ӵ������¼�
// ���������������ӵ�
// �޷���ֵ
class ProjectileCreateEvent : public BaseEvent<std::function<
	void(std::shared_ptr<PVZ::Projectile>)>>
{
public:
	ProjectileCreateEvent();
	bool handle(EventHandler handler);
};

ProjectileCreateEvent::ProjectileCreateEvent()
{
	address = 0x40D652;
}

bool ProjectileCreateEvent::handle(EventHandler handler)
{
	if (handler.context.Eip != address) return false;
	auto projectile = std::make_shared<PVZ::Projectile>(handler.context.Eax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](projectile);
	}
	afterHandle(handler);
	return true;
}
