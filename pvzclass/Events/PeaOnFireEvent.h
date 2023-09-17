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

PeaOnFireEvent::PeaOnFireEvent()
{
	address = 0x46ECB0;
}

void PeaOnFireEvent::handle(CONTEXT& context)
{
	auto projectile = std::make_shared<PVZ::Projectile>(context.Ecx);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](projectile);
	}
}
