#pragma once
#include "BaseEvent.h"

// ��������ʬ���˺����ͣ��˺���ֵ
// ���أ��µ��˺���ֵ
// ע������ listener ����ֵ�Ķ�Ϊ����
class ZombieHitEvent : public BaseEvent<std::function<
	int(std::shared_ptr<PVZ::Zombie>, DamageType::DamageType, int)>>
{
public:
	void start();
	void run();
	void end();
};
