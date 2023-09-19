#pragma once
#include "TemplateEvent.h"

// ���ƶ���UI�¼�
// ������Graphicָ��
// �޷���ֵ
class DrawUITopEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Graphics>)>>
{
public:
	DrawUITopEvent();
	void handle(CONTEXT& context) override;
};

DrawUITopEvent::DrawUITopEvent()
{
	address = 0x4172F6;
}

void DrawUITopEvent::handle(CONTEXT& context)
{
	auto graphics = std::make_shared<PVZ::Graphics>(context.Eax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](graphics);
	}
}