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