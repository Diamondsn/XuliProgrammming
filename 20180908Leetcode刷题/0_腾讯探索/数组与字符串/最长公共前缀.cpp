#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
using namespace std;

//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。
//
//示例 1:
//输入: ["flower","flow","flight"]
//输出: "fl"
//
//示例 2:
//输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
//
//说明:
//所有输入只包含小写字母 a-z 。

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() <= 0)return "";
	bool find = false;
	int i = 0;
	for (;i<strs[0].size(); ++i){
		char c = strs[0][i];
		for (int j = 1; j < strs.size(); ++j){
			if (i == strs[j].size() || strs[j][i]!=c)
				find = true;
		}
		if (find)break;
	}
	return strs[0].substr(0, i);
}

int main() {
	//test1
	vector<string>strs = { "flowers","flow","flight"};
	string a = longestCommonPrefix(strs);

	//test2
	strs = { "dog", "racecar", "car" };
	string b = longestCommonPrefix(strs);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}