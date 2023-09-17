#pragma once
#include "TemplateEvent.h"

// �ӵ������¼�
// ���������������ӵ�
// �޷���ֵ
class ProjectileCreateEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Projectile>)>>
{
public:
	ProjectileCreateEvent();
	void handle(CONTEXT& context) override;
};

ProjectileCreateEvent::ProjectileCreateEvent()
{
	address = 0x40D652;
}

void ProjectileCreateEvent::handle(CONTEXT& context)
{
	auto projectile = std::make_shared<PVZ::Projectile>(context.Eax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](projectile);
	}
}
