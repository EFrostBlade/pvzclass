#pragma once
#include "TemplateEvent.h"

// ���ƶ���UI�¼�
// �޲����뷵��ֵ
// ����Draw.h���ʹ��
class DrawUITopEvent : public TemplateEvent<std::function<
	void(void)>>
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
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i]();
	}
}