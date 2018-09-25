#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
using namespace std;

//给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
//
//你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
//
//示例 1:
//输入: [1, 2, 2, 3, 1]
//输出: 2
//解释: 
//输入数组的度是2，因为元素1和2的出现频数最大，均为2.
//连续子数组里面拥有相同度的有如下所示:
//[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
//最短连续子数组[2, 2]的长度为2，所以返回2.
//
//示例 2:
//输入: [1,2,2,3,1,4,2]
//输出: 6
//
//注意:
//nums.length 在1到50,000区间范围内。
//nums[i] 是一个在0到49,999范围内的整数。

int findShortestSubArray(vector<int>& nums) {
	map<int, int>mymap;
	map<int, int>xiao;
	map<int, int>da;
	vector<int>num;
	int max=INT_MIN;
	int res = INT_MAX;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (mymap.find(nums[i]) == mymap.end())
		{
			mymap.insert(pair<int, int>(nums[i], 1));
			xiao.insert(pair<int, int>(nums[i], i));
		}
		else
		{
			mymap.find(nums[i])->second++;
			if (da.find(nums[i])==da.end())
			   da.insert(pair<int, int>(nums[i], i));
			else
			{
				da[nums[i]] = i;
			}
		}
	}
	for (auto it = mymap.begin(); it != mymap.end(); ++it)
	{
		if (it->second > max)
		{
			max = it->second;
			num.clear();
			num.push_back(it->first);
		}
		else if (it->second == max)
		{
			num.push_back(it->first);
		}
	}
	if (max == 1)
		return 1;
	for (int i = 0; i < num.size(); ++i)
	{
		int length = da[num[i]] - xiao[num[i]]+1;
		if (length < res)
			res = length;
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 1, 2, 2, 3, 1 };
	int a = findShortestSubArray(nums);

	//test2
	nums = { 1, 2, 2, 3, 1, 4, 2 };
	int b = findShortestSubArray(nums);

	cout << a << endl << b << endl;
	//test end
	system("pause");
	return 0;
}
