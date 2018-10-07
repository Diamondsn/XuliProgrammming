#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

//给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
//
//示例 1:
//输入: [3, 2, 1]
//输出: 1
//解释: 第三大的数是 1.
//
//示例 2:
//输入: [1, 2]
//输出: 2
//解释: 第三大的数不存在, 所以返回最大的数 2 .
//
//示例 3:
//输入: [2, 2, 3, 1]
//输出: 1
//解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
//存在两个值为2的数，它们都排第二。

//注意以下算法不能区分[1,2,-2147483648]第三大的数本来就是INT_MIN;
//一种改进是使用long 的最小值 LONG_MIN
//int thirdMax(vector<int>& nums) {
//哨兵值应初始化为long first=LONG_MIN,second=LONG_MIN,third=LONG_MIN;
//	int first = INT_MIN, second = INT_MIN, third = INT_MIN;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		if (nums[i] == first || nums[i] == second || nums[i] == third)
//			continue;
//		if (nums[i] > first)
//		{
//			third = second;
//			second = first;
//			first = nums[i];
//		}
//		else if (nums[i] > second)
//		{
//			third = second;
//			second = nums[i];
//		}
//		else if (nums[i] > third)
//		{
//			third = nums[i];
//		}
//	}
//	return third == INT_MIN ? first: third;
//}

int thirdMax(vector<int>& nums) {
	vector<int>max;
	bool flag = true;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < max.size(); ++j) {
			if (max[j] == nums[i])flag = false;
		}
		if (!flag)
		{
			flag = true;
			continue;
		}
		if (max.size() < 1)
		{
			max.push_back(nums[i]);
			continue;
		}
		if (max.size() == 1) {
			if (nums[i] > max[0])
				max.insert(max.begin(), nums[i]);
			else
				max.push_back(nums[i]);
		}
		else if (max.size() == 2) {
			if (nums[i] > max[0])
				max.insert(max.begin(), nums[i]);
			else if (nums[i] > max[1])
				max.insert(max.begin() + 1, nums[i]);
			else
				max.push_back(nums[i]);
		}
		else if (max.size() == 3)
		{
			if (nums[i] > max[0])
			{
				max.insert(max.begin(), nums[i]);
				max.erase(max.end()-1);
			}
			else if (nums[i] > max[1])
			{
				max.insert(max.begin() + 1, nums[i]);
				max.erase(max.end()-1);
			}
			else if (nums[i] > max[2])
			{
				max[2] = nums[i];
			}
		}
	}
	return max.size() != 3 ? max[0] : max[2];
}

void main() {
	//test1
	vector<int>nums = { 1,2,2,5,3,5 };
	int a = thirdMax(nums);

	//test2
	nums = { 1,2 };
	int b = thirdMax(nums);

	//test3
	nums = { 2,2,3,1 };
	int c = thirdMax(nums);

	//test4
	nums = { 1,2,INT_MIN };
	int d = thirdMax(nums);

	cout << a << endl << b << endl << c << endl<<d<<endl;
	//test end
	system("pause");
}