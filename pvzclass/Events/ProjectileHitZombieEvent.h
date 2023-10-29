#pragma once
#include "TemplateEvent.h"

// �ӵ����н�ʬ�¼�
// �������ӵ��뱻���еĽ�ʬ
// �޷���ֵ
class ProjectileHitZombieEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Projectile>, std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ProjectileHitZombieEvent();
	void handle(CONTEXT& context) override;
};