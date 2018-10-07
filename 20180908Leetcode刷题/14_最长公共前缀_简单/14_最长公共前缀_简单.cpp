#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<math.h>
#include<algorithm>
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
	if (strs.size() == 0)return "";
	string res, temp;
	int shorestindex=0;
	for (int i = 1; i < strs.size(); ++i)
	{
		if (strs[i].size() < strs[shorestindex].size())
			shorestindex = i;
	}
	for (int i = 1; i <= strs[shorestindex].size(); ++i)
	{
		temp = strs[shorestindex].substr(0, i);
		for (int j = 0; j < strs.size(); ++j) {
			if (j == shorestindex)continue;
			if (strs[j].find(temp) != 0)
				return res;
		}
		res = temp;
	}
	return res;
}

void main() {
	//test1
	vector<string>strs = { "flowers","flow","flight" };
	string a = longestCommonPrefix(strs);

	//test2
	strs = { "dog","racecar","car" };
	string b = longestCommonPrefix(strs);

	cout << a << endl << b << endl;
	//test end
	system("pause");
}