﻿#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。
//
//重复出现的子串要计算它们出现的次数。
//
//示例 1 :
//输入: "00110011"
//输出: 6
//解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
//请注意，一些重复出现的子串要计算它们出现的次数。
//
//另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
//
//示例 2 :
//输入: "10101"
//输出: 4
//解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
//
//注意：
//s.length 在1到50,000之间。
//s 只包含“0”或“1”字符。

int countBinarySubstrings(string s) {
	if (s.size() < 1)
		return 0;

	int res = 0;
	char m = s[0];
	int num1 = 1;
	int num2 = 0;
	bool flag = false;
	for (int i = 1; i < s.size(); ++i)
	{
		
		if (!flag && num1 != 0 && num2 != 0 && s[i] == m)
			flag = true;

	    if (!flag && s[i] == m)
				num1++;
		if(!flag && s[i]!=m)
			num2++;

		if (flag && s[i] == m)
		{
			res += num1 < num2 ? num1:num2;
			num1 = num2;
			num2 = 1;
			m = m == '0' ? '1':'0';
			flag = false;
		}
	}
	res += num1 < num2 ? num1 : num2;
	return res;
}

int main() {
	//test1
	int a = countBinarySubstrings("00110011");

	//test2
	int b = countBinarySubstrings("10101");
	cout << a << endl << b << endl;

	//test end

	system("pause");
	return 0;
}