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