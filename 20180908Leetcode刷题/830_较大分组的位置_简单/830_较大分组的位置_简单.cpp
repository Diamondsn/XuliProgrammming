#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//在一个由小写字母构成的字符串 S 中，包含由一些连续的相同字符所构成的分组。
//
//例如，在字符串 S = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。
//
//我们称所有包含大于或等于三个连续字符的分组为较大分组。找到每一个较大分组的起始和终止位置。
//
//最终结果按照字典顺序输出。
//
//示例 1:
//输入: "abbxxxxzzy"
//输出: [[3,6]]
//解释: "xxxx" 是一个起始于 3 且终止于 6 的较大分组。
//
//示例 2:
//输入: "abc"
//输出: []
//解释: "a","b" 和 "c" 均不是符合要求的较大分组。
//
//示例 3:
//输入: "abcdddeeeeaabbbcd"
//输出: [[3,5],[6,9],[12,14]]
//说明:  1 <= S.length <= 1000

vector<vector<int>> largeGroupPositions(string S) {
	vector<vector<int>>res;
	if (S.size() < 1)return res;
	vector<int>temp;
	int lowindex = 0, sum = 1;
	for (int i = 1; i < S.size(); ++i)
	{
		if (S[i] == S[lowindex])
			sum++;
		else {
			if (sum >= 3)
			{
				temp.push_back(lowindex);
				temp.push_back(i - 1);
				res.push_back(temp);
				temp.clear();
			}
			lowindex = i;
			sum = 1;
		}
	}
	if (sum >= 3)
	{
		temp.push_back(lowindex);
		temp.push_back(S.size()-1);
		res.push_back(temp);
	}
	return res;
}

int main() {
	//test1
	vector<vector<int>>res = largeGroupPositions("abbxxxxzzy");
	cout << "test1" << endl;
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << ",";
		cout << endl;
	}

	//test2
	res = largeGroupPositions("abc");
	cout << "test2" << endl;
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << ",";
		cout << endl;
	}
	
	//test3
	res = largeGroupPositions("abcdddeeeeaabbbcd");
	cout << "test3" << endl;
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << ",";
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}