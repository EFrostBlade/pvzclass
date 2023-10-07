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

SeedCardClickEvent::SeedCardClickEvent()
{
	address = 0x412236;
}

void SeedCardClickEvent::handle(CONTEXT& context)
{
	auto seedcard = std::make_shared<PVZ::CardSlot::SeedCard>(context.Eax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](seedcard);
	}
}