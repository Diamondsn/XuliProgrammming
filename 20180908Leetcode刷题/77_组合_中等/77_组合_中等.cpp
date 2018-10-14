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

//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//
//示例:
//输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//]

//vec表示一条路径
//n表示最大为几
//begin表示从哪个数开始
//num表示目前需要几个数
void dfs(vector<vector<int>>& res, vector<int>&vec, int n,int begin, int num) {
	if (num==0)
	{
		res.push_back(vec);
	 }
	else
	{
		for (int i = begin + 1; i <= n; ++i) {
			vec.push_back(i);
			dfs(res, vec, n, i, num - 1);
			vec.pop_back();
		}
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>>res;
	vector<int>vec;
	dfs(res, vec, n, 0, k);
	return res;
}

int main() {
	//test1
	vector<vector<int>>res = combine(4, 2);
	for (vector<int>temp : res) {
		for (int i : temp) {
			cout << i << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}