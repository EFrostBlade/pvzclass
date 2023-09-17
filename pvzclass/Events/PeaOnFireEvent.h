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
	bool handle(EventHandler handler);
};

PeaOnFireEvent::PeaOnFireEvent()
{
	address = 0x46ECB0;
}

bool PeaOnFireEvent::handle(EventHandler handler)
{
	if (handler.context.Eip != address) return false;
	auto projectile = std::make_shared<PVZ::Projectile>(handler.context.Ecx);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](projectile);
	}
	afterHandle(handler);
	return true;
}
