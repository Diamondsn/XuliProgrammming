#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include<set>
using namespace std;

/*给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。

这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的
每个非空单词之间存在着双向连接的对应模式。

示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true

示例 2:
输入:pattern = "abba", str = "dog cat cat fish"
输出: false

示例 3:
输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false

示例 4:
输入: pattern = "abba", str = "dog dog dog dog"
输出: false

说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。   */ 

bool wordPattern(string pattern, string str) {
	if (pattern.size() < 1)return false;
	unordered_map<char, string>hash;
	vector<string>vec;
	while(str.size()>0){
		int j = str.find(" ");
		if (j >= 0)
		{
			vec.push_back(str.substr(0, j));
			str = str.substr(j + 1);
		}
		else {
			vec.push_back(str);
			str = "";
		}
	}
	if (pattern.size() != vec.size())return false;
	set<string>setvec(vec.begin(),vec.end());
	for (int i = 0; i < pattern.size(); ++i) {
		if (hash.find(pattern[i])==hash.end()) {
			hash.insert(pair<char, string>(pattern[i], vec[i]));
		}
		else {
			if (vec[i] != hash[pattern[i]])
				return false;
		}
	}
	if (hash.size() != setvec.size())return false;//需要一一对应关系
	return true;
}

int main() {
	//test1
	string pattern = "abba", str = "dog cat cat dog";
	bool a = wordPattern(pattern, str);

	//test2
	pattern = "abba"; str = "dog cat cat fish";
	bool b = wordPattern(pattern, str);

	//test3
	pattern = "aaaa"; str = "dog cat cat dog";
	bool c = wordPattern(pattern, str);

	//test4
	pattern = "abba"; str = "dog dog dog dog";
	bool d = wordPattern(pattern, str);
	cout << a << endl << b << endl << c << endl << d << endl;
	//test end

	system("pause");
	return 0;
}