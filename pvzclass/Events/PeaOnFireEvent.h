#pragma once
#include "TemplateEvent.h"

// �㶹���������׮���Ż��¼�
// ������������Ϊ������㶹
// �޷���ֵ
class PeaOnFireEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Projectile>)>>
{
public:
	PeaOnFireEvent();
	void handle(CONTEXT& context) override;
};