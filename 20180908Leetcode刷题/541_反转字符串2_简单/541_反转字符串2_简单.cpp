#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
using namespace std;
#pragma warning(error:4996)
//给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。
//
//示例:
//输入: s = "abcdefg", k = 2
//输出: "bacdfeg"
//
//要求:
//该字符串只包含小写的英文字母。
//给定字符串的长度和 k 在[1, 10000]范围内。

string reverseStr(string s, int k) {
	string res;
	bool flag = true;//翻转
	string temp;
	while (s.size())
	{
		if(s.size() < k)
		{
			if (flag)
				reverse(s.begin(), s.end());
			temp = s;
			s = "";
		}
		else
		{
			temp = s.substr(0, k);
			if (flag)
			{
				reverse(temp.begin(), temp.end());
			}
			s = s.substr(k);
		}
		flag = !flag;
		res += temp;
	}
	return res;
}

int main() {
	//test1
	string res = reverseStr("abcdefg",2);
	cout << res << endl;
	//test end
	system("pause");
	return 0;
}
