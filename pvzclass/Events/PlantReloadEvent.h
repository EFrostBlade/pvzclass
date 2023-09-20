#pragma once
#include "TemplateEvent.h"

// ֲ������װ���¼�
// �����������¼���ֲ���Ч����ʱ
// ����ֵ���޸ĺ�ĵ���ʱ
// ������֮�䴮���޸�
// ע��ֲ��ÿ��һ��ʱ�������װ���ʱ������ֽ�ʬ�����
// ��Ч����ʱĬ��Ϊ��Ч�����ȥһ��[0,14]�������
class PlantReloadEvent : public TemplateEvent<std::function<
	int(std::shared_ptr<PVZ::Plant>, int)>>
{
public:
	PlantReloadEvent();
	void handle(CONTEXT& context) override;
};

PlantReloadEvent::PlantReloadEvent()
{
	address = 0x45F8C4;
}

void PlantReloadEvent::handle(CONTEXT& context)
{
	auto plant = std::make_shared<PVZ::Plant>(context.Esi);
	int cd = context.Ecx;
	for (int i = 0; i < listeners.size(); i++)
	{
		cd = listeners[i](plant, cd);
	}
	context.Ecx = cd;
}
