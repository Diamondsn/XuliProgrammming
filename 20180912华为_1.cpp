#include "stdafx.h"
#include <map>
#include <list>
#include <string>
#include <map>
#include<iostream>
using namespace std;
void function(string str)
{
	char s[256] = { 0 };
	int flag = 1;
	for (size_t i = 0; i < str.size(); ++i)
	{
		s[str[i]]++;
	}
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (s[str[str.size()-1-i]] == 1)
		{
			cout << str[str.size() - 1 - i] << endl;
			flag = 0;
			break;
		}
	}
	if (flag)
		cout << "-1" << endl;
}

int main()
{
	function("BACCAAHEFGHFF");
	system("pause");
    return 0;
}
