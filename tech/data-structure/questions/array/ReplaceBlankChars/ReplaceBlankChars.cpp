// ReplaceBlankChars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

// Solution 1: Use new string to store the replaced string.
std::string replaceBlankChars_byNewString(std::string &str)
{
	std::string res;
	std::string targetReplaceString("%20");	

	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it == ' ')
		{
			res += targetReplaceString;			
		}
		else
		{
			res.push_back(*it);
		}
	}

	return res;
}

// Solution 2: replace internally, need restrict conditions.
void replaceBlankChars_byInternalChange(char *str, int length, int capacity)
{
	int blankCount = 0;
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
		{
			++blankCount;
		}					
	}

	int replacedStringLength = length + 2 * blankCount;
	if (replacedStringLength > capacity)
	{
		return;
	}

	for (int i = replacedStringLength - 1, j = length - 1; (i >= 0) && (j >= 0); --j)
	{
		if (str[j] == ' ')
		{
			str[i--] = '0';
			str[i--] = '2';
			str[i--] = '%';
		}
		else
		{
			str[i--] = str[j];
		}
	}
	str[replacedStringLength] = '\0';
}


int main()
{
	std::string test("Mr John Smith");	
	
	std::cout << replaceBlankChars_byNewString(test) << std::endl;
	
	char test1[100];
	memcpy(test1, test.c_str(), test.length() + 1);
	replaceBlankChars_byInternalChange(test1, test.length(), 100);
	std::cout << test1 << std::endl;
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
