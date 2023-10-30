#pragma once
#include "TemplateEvent.h"

// Coin�����¼�
// �����������¼���Coin
// �޷���ֵ
class CoinCreateEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Coin>)>>
{
public:
	CoinCreateEvent();
	void handle(CONTEXT& context) override;
};