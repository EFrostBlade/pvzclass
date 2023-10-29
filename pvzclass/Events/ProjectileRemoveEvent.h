#pragma once
#include "TemplateEvent.h"

// �ӵ���ʧ�¼�
// ��������ʧ���ӵ�
// �޷���ֵ
// �ӵ���ʧ��ԭ����ֶ��������н�ʬ�������Ļ�ȶ��ᴥ��
class ProjectileRemoveEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Projectile>)>>
{
public:
	ProjectileRemoveEvent();
	void handle(CONTEXT& context) override;
};

ProjectileRemoveEvent::ProjectileRemoveEvent()
{
	address = 0x46EB20;
}

#if defined(_WIN64)
void ProjectileRemoveEvent::handle(CONTEXT& context)
{
	auto projectile = std::make_shared<PVZ::Projectile>(context.Rax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](projectile);
	}
}
#else
void ProjectileRemoveEvent::handle(CONTEXT& context)
{
	auto projectile = std::make_shared<PVZ::Projectile>(context.Eax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](projectile);
	}
}
#endif