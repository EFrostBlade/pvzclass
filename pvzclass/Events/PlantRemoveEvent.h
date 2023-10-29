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
	void handle(CONTEXT& context) override;
};

PlantRemoveEvent::PlantRemoveEvent()
{
	address = 0x4679B9;
}

#if defined(_WIN64)
void PlantRemoveEvent::handle(CONTEXT& context)
{
	auto plant = std::make_shared<PVZ::Plant>(context.Rbp);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](plant);
	}
}
#else
void PlantRemoveEvent::handle(CONTEXT& context)
{
	auto plant = std::make_shared<PVZ::Plant>(context.Ebp);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](plant);
	}
}
#endif