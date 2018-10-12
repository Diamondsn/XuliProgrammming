#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
using namespace std;

//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
//说明：解集不能包含重复的子集。
//
//示例:
//输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>>res,sub;
	vector<int>temp;
	res.push_back(temp);
	if (nums.size() == 0)
		return res;
	if (nums.size() == 1)
	{
		temp.push_back(nums[0]);
		res.push_back(temp);
		return res;
	}
	
	vector<int>copy = nums;
	copy.erase(copy.begin());
	sub = subsets(copy);
	for (int i = 0; i < sub.size(); ++i) {
		temp = sub[i];
		temp.insert(temp.begin(), nums[0]);
		res.push_back(temp);
		if (sub[i].size() > 0)
			res.push_back(sub[i]);
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 1,2,3 };
	vector<vector<int>>res=subsets(nums);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}