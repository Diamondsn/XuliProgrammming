#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
using namespace std;

//给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
//
//示例 1:
//输入: [3,0,1]
//输出: 2
//
//示例 2:
//输入: [9,6,4,2,3,5,7,0,1]
//输出: 8
//
//说明:
//你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

int missingNumber(vector<int>& nums) {
	int sum = 0;
	int max = -1;
	bool ling = false;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 0)ling = true;
		sum += nums[i];
		if (max < nums[i])max = nums[i];
	}
	if (sum == max*(max + 1) / 2 && ling == true)
		return max + 1;

	return max*(max + 1) / 2 - sum;
}

int main() {
	//test1
	vector<int>num = {3,0,1 };
	int a = missingNumber(num);

	//test2
	num = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	int b = missingNumber(num);

	cout << a << endl << b << endl;//2,8
	//test end
	system("pause");
	return 0;
}
