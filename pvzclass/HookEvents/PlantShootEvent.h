#pragma once
#include "BaseEvent.h"

// ������ֲ��ָ�룬�ӵ�ָ��
// �޷���ֵ
// ע�����ҵ��ӵ�ָ�벻׼
class PlantShootEvent : public BaseEvent<std::function<
	void(std::shared_ptr<PVZ::Plant>, std::shared_ptr<PVZ::Projectile>)>>
{
public:
	void start();
	void run();
	void end();
};

