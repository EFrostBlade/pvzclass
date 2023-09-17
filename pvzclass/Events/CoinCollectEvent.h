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
	bool handle(EventHandler handler);
};

CoinCollectEvent::CoinCollectEvent()
{
	address = 0x432060;
}

bool CoinCollectEvent::handle(EventHandler handler)
{
	if (handler.context.Eip != address) return false;
	auto coin = std::make_shared<PVZ::Coin>(handler.context.Ecx);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](coin);
	}
	afterHandle(handler);
	return true;
}
