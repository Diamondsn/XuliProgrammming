#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
using namespace std;

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
//
//示例 1:
//输入: s = "anagram", t = "nagaram"
//输出: true
//
//示例 2:
//输入: s = "rat", t = "car"
//输出: false
//
//说明:
//你可以假设字符串只包含小写字母。
//
//进阶:
//如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

bool isAnagram(string s, string t) {
	if (s.size() != t.size())
		return false;

	unordered_map<char, int>hash;
	for (int i = 0; i < s.size(); ++i)
	{
		hash[s[i]]++;
	}
	for (int i = 0; i < t.size(); ++i)
	{
		hash[t[i]]--;
		if (hash[t[i]] < 0)
			return false;
	}
	return true;
}

int main() {
	//test1
	bool a = isAnagram("anagram","nagaram");
	cout << a << endl;

	//test2
	bool b = isAnagram("rat", "car");
	cout << b << endl;
	//test end

	system("pause");
	return 0;
}
