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