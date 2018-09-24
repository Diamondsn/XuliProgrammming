#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。
//
//示例:
//输入:
//[1,2,3]
//
//输出:
//3
//
//解释:
//只需要3次移动（注意每次移动会增加两个元素的值）：
//[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

//此题为巧解，增加n-1个数相当于减小选定的那个数
//故此题答案相当于所有元素减去最小元素之后进行求和所得的值
int minMoves(vector<int>& nums) {
	int sum = 0,min=INT_MAX;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
		if (nums[i] < min)
			min = nums[i];
	}
	return sum - min*nums.size();
}

int main() {
	//test1
	vector<int>nums = { 1,2,3 };
	int a = minMoves(nums);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}