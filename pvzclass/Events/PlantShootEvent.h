#pragma once
#include "TemplateEvent.h"

// ֲ������¼�
// �����������¼���ֲ��
// �޷���ֵ
class PlantShootEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Plant>)>>
{
public:
	PlantShootEvent();
	void handle(CONTEXT& context) override;
};