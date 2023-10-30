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