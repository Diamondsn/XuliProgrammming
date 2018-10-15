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

//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的数字可以无限制重复被选取。
//
//说明：
//所有数字（包括 target）都是正整数。
//解集不能包含重复的组合。 
//
//示例 1:
//输入: candidates = [2,3,6,7], target = 7,
//所求解集为:
//[
//  [7],
//  [2,2,3]
//]
//
//示例 2:
//输入: candidates = [2,3,5], target = 8,
//所求解集为:
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//]

//res最后结果
//vec一条路径
//candidates查找的目录
//begin开始寻找的索引
//target还需要找的总和
void dfs(vector<vector<int>>& res, vector<int>& vec, vector<int>& candidates,int begin, int target){
	if (target == 0){
		res.push_back(vec);
	}
	else{
		for (int i = begin; i < candidates.size(); ++i){
			if (candidates[i] <= target){
				vec.push_back(candidates[i]);
				dfs(res, vec, candidates, i, target - candidates[i]);
				vec.pop_back();
			}
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>>res;
	vector<int>vec;
	dfs(res, vec, candidates, 0,target);
	return res;
}

int main() {
	//test1
	vector<int>candidates = { 2, 3, 6, 7 };
	vector<vector<int>>res = combinationSum(candidates, 7);
	for (vector<int>vec : res){
		for (int temp : vec){
			cout << temp << ",";
		}
		cout << endl;
	}

	//test2
	cout << endl << "test2" << endl;
	candidates = { 2, 3, 5 };
	res = combinationSum(candidates, 8);
	for (vector<int>vec : res){
		for (int temp : vec){
			cout << temp << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}