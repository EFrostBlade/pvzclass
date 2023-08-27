#pragma once
#include "BaseEvent.h"

extern BYTE hook_700010[62];
extern BYTE hook_5317C0[7];
extern BYTE hook_5317C0_raw[7];

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
