#pragma once
#include "TemplateEvent.h"

// ��ʬ���Ƴ��¼�
// �����������¼��Ľ�ʬ
// �޷���ֵ
// ��ʬ���Ƴ���ԭ����ֶ�������ʹ�ǹؿ���ʬԤ������Ľ�ʬ���Ƴ�Ҳ�ᴥ�����¼�
class ZombieRemoveEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ZombieRemoveEvent();
	void handle(CONTEXT& context) override;
};