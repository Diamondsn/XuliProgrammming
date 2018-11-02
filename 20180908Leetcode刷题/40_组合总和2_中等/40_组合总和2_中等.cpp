#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的每个数字在每个组合中只能使用一次。
//
//说明：
//所有数字（包括目标数）都是正整数。
//解集不能包含重复的组合。 
//
//示例 1:
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
//
//示例 2:
//输入: candidates = [2,5,2,1,2], target = 5,
//所求解集为:
//[
//  [1,2,2],
//  [5]
//]

//初解:使用set代替去重策略，增加了时间和空间开销
//void dfs(set<vector<int>>& myset, vector<int>&path, vector<int>&candidates, int target, int suoyin){
//	if (target < 0||suoyin>candidates.size())return;
//	
//	if (target == 0){
//		myset.insert(path);
//	}
//	else{
//		for (int i = suoyin; i < candidates.size(); ++i){
//			path.push_back(candidates[i]);
//			dfs(myset, path, candidates, target - candidates[i], i + 1);
//			path.pop_back();
//		}
//	}
//}
//
//vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//	vector<vector<int>>res;
//	vector<int>path;
//	set<vector<int>>myset;
//	sort(candidates.begin(), candidates.end());
//	dfs(myset, path, candidates, target, 0);
//	res.assign(myset.begin(), myset.end());
//	return res;
//}

void dfs(vector<vector<int>>& res, vector<int>&path, vector<int>&candidates, int target, int suoyin){
	if (target < 0 || suoyin>candidates.size())return;

	if (target == 0){
		res.push_back(path);
	}
	else{
		for (int i = suoyin; i < candidates.size(); ++i){
			//以下去重，注意suoyin即使和之前的candidates[suoyin-1]相同也可添加
			if (i != 0 && candidates[i] == candidates[i - 1]&&i>suoyin)continue;

			path.push_back(candidates[i]);
			dfs(res, path, candidates, target - candidates[i], i + 1);
			path.pop_back();
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>>res;
	vector<int>path;
	sort(candidates.begin(), candidates.end());
	dfs(res, path, candidates, target, 0);
	return res;
}

int main() {
	//test1
	vector<int>candidates = { 10, 1, 2, 7, 6, 1, 5 };
	vector<vector<int>>res = combinationSum2(candidates, 8);
	for (vector<int>vec : res)
	{
		for (int m : vec)
			cout << m << ",";
		cout << endl;
	}

	//test2
	cout << "test2" << endl;
	candidates = { 2, 5, 2, 1, 2 };
	res = combinationSum2(candidates, 5);
	for (vector<int>vec : res){
		for (int m : vec)
			cout << m << ",";
		cout << endl;
	}
	//test end
	system("pause");
	return 0;
}