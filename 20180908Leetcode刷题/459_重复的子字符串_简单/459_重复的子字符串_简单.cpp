#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
//
//示例 1:
//输入: "abab"
//输出: True
//解释: 可由子字符串 "ab" 重复两次构成。
//
//示例 2:
//输入: "aba"
//输出: False
//
//示例 3:
//输入: "abcabcabcabc"
//输出: True
//
//解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)

bool repeatedSubstringPattern(string s) {
	if (s.size() <= 1)return false;
	if (s.substr(1).find(s[0])==-1 || s.substr(1).find(s[0])+1 > s.size() / 2)return false;
	for (int i = 1; i <= s.size() / 2;) {
		int pos = s.substr(i).find(s[0])+i;
		if (s.substr(i).find(s[0]) != -1&& pos<=s.size()/2) {
			string temp = s.substr(0, pos);
			int t = pos;
			while (t + pos <= s.size()) {
				string m = s.substr(t, pos);
				if (temp.compare(m) == 0) {
					if (t + pos == s.size())
						return true;
				}
				else {
					break;
				}
				t += pos;
			}
			i = pos + 1;
		}
		else
		{
			break;
		}
	}
	return false;
}

int main() {
	//test1
	bool a = repeatedSubstringPattern("ababba");

	//test2
	bool b = repeatedSubstringPattern("aba");

	//test3
	bool c = repeatedSubstringPattern("abcabcabcabc");
	cout << a << endl << b << endl << c << endl;
	//test end

	system("pause");
	return 0;
}