﻿#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
using namespace std;

//给定一个长度为 n 的整数数组，你的任务是判断在最多改变 1 个元素的情况下，该数组能否变成一个非递减数列。
//
//我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，满足 array[i] <= array[i + 1]。
//
//示例 1:
//输入: [4,2,3]
//输出: True
//解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
//
//示例 2:
//输入: [4,2,1]
//输出: False
//解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
//说明:  n 的范围为 [1, 10,000]。

//统计逆序对的数量
bool checkPossibility(vector<int>& nums) {
	int res = 0;
	for (int i = 0; i < nums.size()-1; ++i){
		if (nums[i]>nums[i + 1])
			res++;
	}
	return res <= 1;
}

int main() {
	//test1
	vector<int>nums = { 4, 2, 3 };
	bool a = checkPossibility(nums);//true

	//test2
	nums = { 4, 2, 1 };
	bool b = checkPossibility(nums);//false
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}