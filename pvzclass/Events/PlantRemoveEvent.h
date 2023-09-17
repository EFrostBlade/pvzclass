#pragma once
#include "TemplateEvent.h"

// ֲ����ʧ�¼�
// �����������¼���ֲ��
// �޷���ֵ
// ֲ����ʧԭ����ֶ�����������������ʳ��һ����ֲ����Ч���Ͽ�ֲ�������ȶ��ᴥ��
class PlantRemoveEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Plant>)>>
{
public:
	PlantRemoveEvent();
	bool handle(EventHandler handler);
};

PlantRemoveEvent::PlantRemoveEvent()
{
	address = 0x4679B9;
}

bool PlantRemoveEvent::handle(EventHandler handler)
{
	if (handler.context.Eip != address) return false;
	auto plant = std::make_shared<PVZ::Plant>(handler.context.Ebp);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](plant);
	}
	afterHandle(handler);
	return true;
}
