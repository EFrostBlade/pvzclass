#pragma once
#include "PVZ.h"
#include <vector>
#include <algorithm>

namespace Draw
{
	// ��(x,y)չʾ��ָ��size��rgb���ַ������ַ����Ϊ100
	struct String
	{
		int x, y, size, red, green, blue;
		char s[100];
	};

	extern DWORD pointerAddress;
	extern DWORD imageFontAddress;
	extern DWORD colorAddress;
	extern DWORD tempAddress;
	extern DWORD codeAddress;
	extern DWORD dataAddress;

	// ����Ļ�ϻ��������ַ���
	// ��Ҫ��DrawUITopEvent���ʹ��
	void writeString(std::vector<String> strings);
	
	// һ��page���Դ�����8��String�ṹ��
	// ������Լ���ʵ����Ҫ�����㹻���Ľṹ��
	void init(int pages);
}