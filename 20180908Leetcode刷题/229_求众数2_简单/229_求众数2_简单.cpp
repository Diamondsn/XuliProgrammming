#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<algorithm>
using namespace std;

//给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
//
//说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
//
//示例 1:
//输入: [3,2,3]
//输出: [3]
//
//示例 2:
//输入: [1,1,1,3,3,2,2,2]
//输出: [1,2]

//摩尔投票算法
vector<int> majorityElement(vector<int>& nums) {//结果最多两个数
	int num1;
	int num2;
	int count1 = 0;
	int count2 = 0;
	vector<int>result;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (count1 == 0)
		{
			num1 = nums[i];
			count1 = 1;
		}
		else if (num1 == nums[i])
		{
			count1++;
		}
		else if (count2 == 0)
		{
			num2 = nums[i];
			count2=1;
		}
		else if (num2 == nums[i])
		{
			count2++;
		}
		else
		{
			count1--;
			count2--;
			if (count1 == 0 && count2 > 0)
			{
				count1 = count2;
				num1 = num2;
				count2 = 0;
				num2 = 0;
			}
		}
	}
	if (count1 > 0)
	{
		count1 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == num1)
			{
				count1++;
			}
		}
	}
	if (count2 > 0)
	{
		count2 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == num2)
			{
				count2++;
			}
		}
	}
	
	if (count1 * 3 > nums.size())
		result.push_back(num1);
	if (count2 * 3 > nums.size())
		result.push_back(num2);

	return result;
}

void main() {
	//test 1
	vector<int>nums1 = { 3,2,3 };
	vector<int>nums2 = { 1,1,1,3,3,2,2,2 };
	vector<int> result1 = majorityElement(nums1);
	vector<int> result2 = majorityElement(nums2);
	cout << "test1" << endl;
	for (int i = 0; i < result1.size(); ++i)
	{
		cout << result1[i] << endl;//3
	}
	cout << "test2" << endl;
	for (int i = 0; i < result2.size(); ++i)
	{
		cout << result2[i] << endl;//1,2
	}
	//test end
	system("pause");
}
