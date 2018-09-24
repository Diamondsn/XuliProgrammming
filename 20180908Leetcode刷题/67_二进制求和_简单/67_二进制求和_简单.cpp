#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
using namespace std;

//给定两个二进制字符串，返回他们的和（用二进制表示）。
//
//输入为非空字符串且只包含数字 1 和 0。
//
//示例 1:
//输入: a = "11", b = "1"
//输出: "100"
//
//示例 2:
//输入: a = "1010", b = "1011"
//输出: "10101"

char stradd(char a, char b,char c, char &jinwei)
{
	jinwei = '0';
	int time0 = 0, time1 = 0;
	if (a == '0')
		time0++;
	else
		time1++;
	if (b == '0')
		time0++;
	else
		time1++;
	if (c == '0')
		time0++;
	else
		time1++;
	if (time0 == 0)
	{
		jinwei = '1';
		return '1';
	}
	if (time0 == 1)
	{
		jinwei = '1';
		return '0';
	}
	else if (time0 == 2)
	{
		return '1';
	}
	else if (time0 == 3)
	{
		return '0';
	}
}
string addBinary(string a, string b) {
	string longstr, shortstr;
	if (a.size() > b.size())
	{
		longstr = a;
		shortstr = b;
	}
	else
	{
		longstr = b;
		shortstr = a;
	}
	while (shortstr.size() < longstr.size())
		shortstr = '0' + shortstr;
	string res;
	char jinwei='0';
	for (int i = longstr.size()-1; i>=0; --i)
	{
		char num = stradd(longstr[i], shortstr[i], jinwei,jinwei);
		res = num + res;
	}
	if (jinwei == '1')
	    res = jinwei + res;
	return res;
}

int main() {
	//test1
	string res = addBinary("11", "1");

	//test2
	string res1 = addBinary("1010","1011");

	//test3
	string res2 = addBinary("0", "0");
	cout << res << endl << res1 << endl<<res2<<endl;
	//test end
	system("pause");
	return 0;
}
