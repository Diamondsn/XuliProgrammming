#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
using namespace std;

//给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
//
//你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
//
//示例:
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]

vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int>hash;//第一个值是后续需要查找的值，第二个是之前的索引
	vector<int>res;
	for (int i = 0; i < nums.size(); ++i){
		auto iter = hash.find(nums[i]);
		if (iter != hash.end())
		{
			res.push_back(iter->second);
			res.push_back(i);
			return res;
		}
		else
			hash.insert(pair<int, int>(target - nums[i], i));
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int>res = twoSum(nums, target);
	for (int t : res)
		cout << t << ",";
	//test end

	system("pause");
	return 0;
}