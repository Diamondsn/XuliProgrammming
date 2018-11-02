#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;

//给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
//说明：解集不能包含重复的子集。
//
//示例:
//输入: [1,2,2]
//输出:
//[
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
//]

void dfs(set<vector<int>>& myset, vector<int>&vec, vector<int>&nums, int target){
	if (target == nums.size())
		myset.insert(vec);
	else
	{
		vec.push_back(nums[target]);
		dfs(myset, vec, nums, target + 1);
		vec.pop_back();
		dfs(myset, vec, nums, target + 1);
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>>res;
	set<vector<int>>myset;
	vector<int>vec;
	sort(nums.begin(), nums.end());
	dfs(myset, vec, nums, 0);
	res.assign(myset.begin(), myset.end());
	return res;
}

int main() {
	//test1
	vector<int>nums = { 1, 2, 2 };
	vector<vector<int>>res = subsetsWithDup(nums);
	for (vector<int>vec : res){
		for (int i : vec)
			cout << i << ",";
		cout << endl;
	}

	//test2
	nums = { 4, 4, 4, 1, 4 };
	res = subsetsWithDup(nums);
	cout << "test2" << endl;
	for (vector<int>vec : res){
		for (int i : vec)
			cout << i << ",";
		cout << endl;
	}
	//test end
	system("pause");
	return 0;
}