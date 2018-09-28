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

//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。
//
//示例 1:
//输入: [1,3,5,6], 5
//输出: 2
//
//示例 2:
//输入: [1,3,5,6], 2
//输出: 1
//
//示例 3:
//输入: [1,3,5,6], 7
//输出: 4
//
//示例 4:
//输入: [1,3,5,6], 0
//输出: 0

int searchInsert(vector<int>& nums, int target) {
	if (nums.size() < 1)
		return 0;

	int i = 0,j=nums.size()-1;
	while (i <= j)
	{
		int mid = (i + j) / 2;
		if (nums[mid] == target)
			return mid;
		else if(nums[mid] > target)
			j = mid-1;
		else
			i = mid+1;
	}
	return i;
}

int main() {
	//test1
	vector<int>nums = { 1, 3, 5, 6 };
	int a = searchInsert(nums, 5);

	//test2
	int b = searchInsert(nums, 2);

	//test3
	int c = searchInsert(nums, 7);

	//test4
	int d = searchInsert(nums, 0);

	cout << a << endl << b << endl << c << endl << d << endl;
	//test end
	system("pause");
	return 0;
}
