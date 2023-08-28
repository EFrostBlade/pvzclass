#pragma once
#include "BaseEvent.h"

// ��������ʳ�Ľ�ʬָ�룬����ʳ��ֲ��ָ��
// �޷���ֵ
class ZombieEatEvent : public BaseEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>, std::shared_ptr<PVZ::Plant>)>>
{
public:
	void start();
	void run();
	void end();
};
