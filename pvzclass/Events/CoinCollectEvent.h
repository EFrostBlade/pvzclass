#pragma once
#include "TemplateEvent.h"

// Coin�ռ��¼�
// �����������¼���Coin
// �޷���ֵ
class CoinCollectEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Coin>)>>
{
public:
	CoinCollectEvent();
	void handle(CONTEXT& context) override;
};

CoinCollectEvent::CoinCollectEvent()
{
	address = 0x432060;
}

void CoinCollectEvent::handle(CONTEXT& context)
{
	auto coin = std::make_shared<PVZ::Coin>(context.Ecx);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](coin);
	}
}
