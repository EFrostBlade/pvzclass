#pragma once
#include "TemplateEvent.h"

// ��ʬ�������¼�
// �����������¼��Ľ�ʬ
// �޷���ֵ
class ZombieFrozeEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ZombieFrozeEvent();
	void handle(CONTEXT& context) override;
};