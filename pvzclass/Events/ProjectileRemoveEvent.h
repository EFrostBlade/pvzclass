#pragma once
#include "BaseEvent.h"

// �ӵ���ʧ�¼�
// ��������ʧ���ӵ�
// �޷���ֵ
// �ӵ���ʧ��ԭ����ֶ��������н�ʬ�������Ļ�ȶ��ᴥ��
class ProjectileRemoveEvent : public BaseEvent<std::function<
	void(std::shared_ptr<PVZ::Projectile>)>>
{
public:
	ProjectileRemoveEvent();
	bool handle(EventHandler handler);
};

ProjectileRemoveEvent::ProjectileRemoveEvent()
{
	address = 0x46EB20;
}

bool ProjectileRemoveEvent::handle(EventHandler handler)
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
