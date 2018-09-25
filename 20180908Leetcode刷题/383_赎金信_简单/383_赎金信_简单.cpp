#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

//题目描述提示帮助提交记录社区讨论阅读解答
//给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。
//
//(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)
//
//注意：
//
//你可以假设两个字符串均只含有小写字母。
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true

bool canConstruct(string ransomNote, string magazine) {
	if (ransomNote.size() < 1)
		return true;

	if (magazine.size() < 1)
		return false;

	map<char, int>mymap;
	for (int i = 0; i < magazine.size(); ++i)
	{
		if (mymap.find(magazine[i]) == mymap.end())
			mymap.insert(pair<char, int>(magazine[i], 1));
		else
			mymap[magazine[i]]++;
	}
	for (int i = 0; i < ransomNote.size();++i)
	{
		if (mymap.find(ransomNote[i]) == mymap.end())
			return false;
		else
		{
			mymap[ransomNote[i]]--;
			if (mymap[ransomNote[i]] < 0)
				return false;
		}
	}
	return true;
}

int main() {
	//test1
	bool a = canConstruct("a","b");

	//test2
	bool b = canConstruct("aa", "ab");

	//test3
	bool c = canConstruct("aa", "aab");

	cout << a << endl << b << endl<<c<<endl;
	//test end

	system("pause");
	return 0;
}