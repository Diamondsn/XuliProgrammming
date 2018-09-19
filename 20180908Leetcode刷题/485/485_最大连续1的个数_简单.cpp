#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个二进制数组， 计算其中最大连续1的个数。
//
//示例 1:
//输入: [1,1,0,1,1,1]
//输出: 3
//解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
//
//注意：
//输入的数组只包含 0 和1。
//输入数组的长度是正整数，且不超过 10,000。

int findMaxConsecutiveOnes(vector<int>& nums) {
	int max = 0;
	int low = -1;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (low == -1 && nums[i] == 1)
		{
			low = i;
		}
		if (low!=-1 && nums[i] == 0)
		{
			if (max < i - low)
				max = i - low;

			low = -1;
		}
	}
	if (low != -1)
	{
		if (max < nums.size() - low)
			max = nums.size() - low;
	}
	return max;
}

void main(){
	//test1
	vector<int>vec = { 1, 0, 1, 0, 1, 0 };
	int a = findMaxConsecutiveOnes(vec);
	cout << a << endl;
	//test end
	system("pause");
}
