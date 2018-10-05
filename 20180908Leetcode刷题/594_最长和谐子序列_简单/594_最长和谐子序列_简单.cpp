#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include<set>
#include<map.>
using namespace std;

//和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
//
//现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
//
//示例 1:
//输入: [1,3,2,2,5,2,3,7]
//输出: 5
//原因: 最长的和谐数组是：[3,2,2,2,3].
//说明: 输入的数组长度最大不超过20,000.

int findLHS(vector<int>& nums) {
	if (nums.size() <= 1)return 0;
	map<int, int>hash;
	for (int i = 0; i < nums.size(); ++i)
	{
		auto it = hash.find(nums[i]);
		if (it == hash.end())
			hash.insert(map<int,int>::value_type(nums[i], 1));
		else
			it->second++;
	}
	int temp, max = INT_MIN;
	for (auto iter = hash.begin(); iter != hash.end(); ++iter)
	{
		auto it = hash.find(iter->first-1);
		if (it == hash.end())
			temp = 0;
		else
			temp = iter->second + it->second;

		if (temp > max)
			max = temp;
	}
	return max;
}

int main() {
	//test1
	vector<int>nums = { 1,3,2,2,5,2,3,7 };;
	int a = findLHS(nums);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}