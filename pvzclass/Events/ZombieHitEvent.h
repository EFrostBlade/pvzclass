#pragma once
#include "TemplateEvent.h"

// ��ʬ�����¼�
// �����������¼��Ľ�ʬ���˺����ͣ��˺���ֵ
// ����ֵ�����º���˺�ֵ
// ����¼�֮���˺��ᴮ���޸ģ���������˺�20
// ��һ��������������40���ڶ����¼����������˺���ֵ����40
// �粻�������޸ģ���ʬ�����ܵ�40���˺�
class ZombieHitEvent : public TemplateEvent<std::function<
	int(std::shared_ptr<PVZ::Zombie>, DamageType::DamageType, int)>>
{
public:
	ZombieHitEvent();
	void handle(CONTEXT& context) override;
};