#pragma once
#include "TemplateEvent.h"

// �����еĿ�Ƭ������¼�
// ������SeedCard
// �޷���ֵ
class SeedCardClickEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::CardSlot::SeedCard>)>>
{
public:
	SeedCardClickEvent();
	void handle(CONTEXT& context) override;
};