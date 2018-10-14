#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;

//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
//
//说明：
//所有数字都是正整数。
//解集不能包含重复的组合。 
//
//示例 1:
//输入: k = 3, n = 7
//输出: [[1,2,4]]
//
//示例 2:
//输入: k = 3, n = 9
//输出: [[1,2,6], [1,3,5], [2,3,4]]

//k表示所需数的个数
//begin表示从begin开始寻找
//n表示总和
vector<vector<int>>core(int k, int begin, int n) {
	vector<vector<int>>res, sub;
	if (k == 1 && begin <= n &&n <= 9) {
		vector<int>temp;
		temp.push_back(n);
		res.push_back(temp);
		return res;
	}
	else if (k <= 0 || begin > n)
		return res;
	for (int i = begin; i <= 10 - k; ++i) {
		sub = core(k - 1, i + 1, n -i);
		for (int j = 0; j < sub.size(); ++j) {
			sub[j].insert(sub[j].begin(), i);
			res.push_back(sub[j]);
		}
	}
	return res;
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>>res,sub;
	if (k == 1 && 1 <= n &&n<=9) {
		vector<int>temp;
		temp.push_back(n);
		res.push_back(temp);
		return res;
	}
	for (int i = 1; i <= 10 - k; ++i) {
		sub = core(k - 1, i + 1, n - i);
		for (int j = 0; j < sub.size(); ++j) {
			sub[j].insert(sub[j].begin(), i);
			res.push_back(sub[j]);
		}
	}
	return res;
}

int main() {
	//test1
	vector<vector<int>>res = combinationSum3(3, 7);
	for (vector<int>m : res)
	{
		{
			for (int n : m)
				cout << n << ",";
		}
		cout << endl;
	}

	//test2
	cout << "test2" << endl;
	res = combinationSum3(3, 9);
	for (vector<int>m : res)
	{
		{
			for (int n : m)
				cout << n << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}