#pragma once
#include "TemplateEvent.h"

// Coin��ʧ�¼�
// ��������ʧ��Coin
// �޷���ֵ
// Coin��ʧԭ��ࣺܶ���ռ���ʱ�䵽�˵ȶ���ʹ����ʧ
class CoinRemoveEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Coin>)>>
{
public:
	CoinRemoveEvent();
	void handle(CONTEXT& context) override;
};