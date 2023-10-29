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