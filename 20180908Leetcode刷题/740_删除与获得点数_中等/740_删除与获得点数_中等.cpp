#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdint.h>
#include<map>
#include<algorithm>
using namespace std;

//给定一个整数数组 nums ，你可以对它进行一些操作。
//
//每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。
//
//开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
//
//示例 1:
//输入: nums = [3, 4, 2]
//输出: 6
//解释: 
//删除 4 来获得 4 个点数，因此 3 也被删除。
//之后，删除 2 来获得 2 个点数。总共获得 6 个点数。
//
//示例 2:
//输入: nums = [2, 2, 3, 3, 3, 4]
//输出: 9
//解释: 
//删除 3 来获得 3 个点数，接着要删除两个 2 和 4 。
//之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
//总共获得 9 个点数。
//
//注意:
//nums的长度最大为20000。
//每个整数nums[i]的大小都在[1, 10000]范围内。

int deleteAndEarn(vector<int>& nums) {
	if (nums.size() <= 0)return 0;
	map<int, int>mymap,dp;
	for (int m : nums){
		mymap[m]++;
	}
	dp[mymap.begin()->first] = (mymap.begin()->first)*(mymap.begin()->second);
	for (auto before = mymap.begin(), cur = ++mymap.begin(); cur != mymap.end(); ++before, ++cur){
		if (!mymap.count(cur->first - 1))
			dp[cur->first] = dp[before->first] + (cur->first)*(cur->second);
		else{
			auto temp = before;
			int a = dp[before->first];//不取当前值
			int b = (cur->first)*(cur->second) + (temp == mymap.begin() ? 0 : dp[(--temp)->first]);//取当前值
			dp[cur->first] = std::max(a, b);
		}
	}
	return dp.rbegin()->second;
}

void main() {
	//test1
	vector<int>nums = { 3, 4, 2 };
	int a = deleteAndEarn(nums);

	//test2
	nums = { 2, 2, 3, 3, 3, 4 };
	int b = deleteAndEarn(nums);
	cout << a << endl << b << endl;
	//test end
	system("pause");
}