#pragma once
#include "TemplateEvent.h"

// ��ʬ�������¼�
// �����������¼��Ľ�ʬ
// �޷���ֵ
class ZombieDecelerateEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ZombieDecelerateEvent();
	void handle(CONTEXT& context) override;
};