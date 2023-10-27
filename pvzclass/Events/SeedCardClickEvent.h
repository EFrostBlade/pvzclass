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

#if defined(_WIN64)
void SeedCardClickEvent::handle(CONTEXT& context)
{
	auto seedcard = std::make_shared<PVZ::CardSlot::SeedCard>(context.Rax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](seedcard);
}
}
#else
void SeedCardClickEvent::handle(CONTEXT& context)
{
	auto seedcard = std::make_shared<PVZ::CardSlot::SeedCard>(context.Eax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](seedcard);
	}
}
#endif