#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//
//示例 1:
//输入: [1,2,3]
//输出: 6
//
//示例 2:
//输入: [1,2,3,4]
//输出: 24
//
//注意:
//给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
//输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。

//此方法时间复杂度过大，超出时间复杂度;
//int maximumProduct(vector<int>& nums) {
//	int max = INT_MIN,temp=0;
//	for(int i=0;i<nums.size();++i)
//		for(int j=i+1;j<nums.size();++j)
//			for (int k = j + 1; k < nums.size(); ++k) {
//				temp = nums[i] * nums[j] * nums[k];
//				if (temp > max)
//					max = temp;
//			}
//	return max;
//}

int maximumProduct(vector<int>& nums) {
	int fu1=INT_MAX, fu2=INT_MAX, fu3=INT_MAX, zheng1=INT_MIN, zheng2 = INT_MIN, zheng3 = INT_MIN,max=INT_MIN;
	bool flag = false;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] < 0) {
			if (nums[i] < fu1) {
				fu3 = fu2;
				fu2 = fu1;
				fu1 = nums[i];
			}
			else if (nums[i] < fu2) {
				fu3 = fu2;
				fu2 = nums[i];
			}
			else if (nums[i] < fu3)
			{
				fu3 = nums[i];
			}
		}
		else if (nums[i] > 0) {
			if (nums[i] > zheng1) {
				zheng3 = zheng2;
				zheng2 = zheng1;
				zheng1 = nums[i];
			}
			else if (nums[i] > zheng2)
			{
				zheng3 = zheng2;
				zheng2 = nums[i];
			}
			else if (nums[i] > zheng3) {
				zheng3 = nums[i];
			}
		}
		else{
			flag = true;
		}
	}
	vector<int>shu = { fu1,fu2,fu3,zheng1,zheng2,zheng3 };
	if (flag)
	{
		shu.push_back(0);
		max = 0;
	}
	for (int i = 0; i < shu.size(); ++i)
	{
		if (shu[i] == INT_MIN || shu[i] == INT_MAX)
			continue;
		for (int j = i + 1; j < shu.size(); ++j)
		{
			if (shu[j] == INT_MIN || shu[j] == INT_MAX)
				continue;
			for (int k = j + 1; k < shu.size(); ++k)
			{
				if (shu[k] == INT_MIN || shu[k] == INT_MAX)
					continue;
				if (shu[i] * shu[j] * shu[k] > max)
					max = shu[i] * shu[j] * shu[k];
			}
		}
	}
	return max;
}

int main() {
	//test1
	vector<int>nums = { 1,2,3 };
	int a = maximumProduct(nums);

	//test2
	nums = { 1,2,3,4 };
	int b = maximumProduct(nums);
	
	//test3
	nums = { -1,-2,-3 };
	int c = maximumProduct(nums);
	cout << a << endl << b << endl<<c<<endl;
	//test end

	system("pause");
	return 0;
}