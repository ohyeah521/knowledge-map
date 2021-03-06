// isAllCharUnique.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 实现一个算法，确定一个字符串的所有字符是否全部不同。假使不允许使用额外的数据结构，又该如何处理？

#include "pch.h"
#include <iostream>
#include <algorithm>

const int MAX_ARRAY_LENGTH = 256;

bool validChars(const char *str, int length)
{	
	if (length > 256)
	{
		return false;
	}
	return true;
}

// 方案一：使用散列标记的方式。
bool isAllCharUnique_byHashMethod(const char *str, int length)
{
	if (!validChars(str, length))
	{
		return false;
	}

	static char letter_check_flags[MAX_ARRAY_LENGTH] = { 'n' };

	for (int i = 0; i < length; ++i)
	{
		int index = static_cast<int>(str[i]);
		if (letter_check_flags[str[i]] == 'y')
		{
			return false;
		}

		letter_check_flags[str[i]] = 'y';
	}
	return true;
}

// 方案二：暴力比较。
bool isAllCharUnique_byLoopCompare(const char *str, int length)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = i + 1; j < length; ++j)
		{
			if (str[i] == str[j])
			{
				return false;
			}
		}
	}
	
	return true;
}

// 方案三：借助排序。
bool isAllCharUnique_bySorting(char *str, int length)
{
	std::sort(str, str + length);

	char uniq_char = str[0];
	for (int i = 1; i < length; ++i)
	{
		if (uniq_char == str[i])
		{
			return false;
		}
		else
		{
			uniq_char = str[i];
		}
	}
	return true;
}

int main()
{
	char uniqChars[] = "abcdefg";
	std::cout << isAllCharUnique_byHashMethod(uniqChars, sizeof(uniqChars)) <<std::endl;
	std::cout << isAllCharUnique_byLoopCompare(uniqChars, sizeof(uniqChars)) << std::endl;
	std::cout << isAllCharUnique_bySorting(uniqChars, sizeof(uniqChars)) << std::endl;

	char repeatChars[] = "abcdefgg";
	std::cout << isAllCharUnique_byHashMethod(repeatChars, sizeof(repeatChars)) << std::endl;
	std::cout << isAllCharUnique_byLoopCompare(repeatChars, sizeof(repeatChars)) << std::endl;
	std::cout << isAllCharUnique_bySorting(repeatChars, sizeof(repeatChars)) << std::endl;

    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
