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

//给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
//
//在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
//
//注意:
//假设字符串的长度不会超过 1010。
//
//示例 1:
//输入:
//"abccccdd"
//输出:
//7
//
//解释:
//我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

int longestPalindrome(string s) {
	int res = 0;
	map<char, int>mymap;
	bool flag = false;
	for (int i = 0; i < s.size(); ++i)
	{
		if (mymap.find(s[i]) == mymap.end())
			mymap.insert(pair<char, int>(s[i], 1));
		else
		{
			mymap[s[i]]++;
		}
	}
	for (auto it = mymap.begin(); it != mymap.end(); ++it)
	{
		if (it->second % 2 == 0)
			res += it->second;
		else
		{
			flag = true;
			res += (it->second - 1);
		}
	}
	if (flag == true)
		return res + 1;
	else
		return res;
}

int main() {
	//test1
	int a = longestPalindrome("abccccdd");

	cout << a << endl;
	//test end
	system("pause");
	return 0;
}
