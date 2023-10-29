#pragma once
#include "TemplateEvent.h"

// ��ʬ���Ȼ��¼�
// �����������¼��Ľ�ʬ
// �޷���ֵ
class ZombieHypnotizeEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ZombieHypnotizeEvent();
	void handle(CONTEXT& context) override;
};