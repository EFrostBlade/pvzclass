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

	void writeString(DWORD address, std::vector<String> strings);
}