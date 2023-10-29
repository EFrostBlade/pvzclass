#pragma once
#include "TemplateEvent.h"

// ��ʬ��ʳֲ���¼�
// �����������¼��Ľ�ʬ��ֲ��
// �޷���ֵ
class ZombieEatEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>, std::shared_ptr<PVZ::Plant>)>>
{
public:
	ZombieEatEvent();
	void handle(CONTEXT& context) override;
};