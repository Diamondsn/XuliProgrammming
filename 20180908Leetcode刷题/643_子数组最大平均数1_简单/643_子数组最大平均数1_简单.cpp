#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

//给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
//
//示例 1:
//输入: [1,12,-5,-6,50,3], k = 4
//输出: 12.75
//解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
// 
//注意:
//1 <= k <= n <= 30,000。
//所给数据范围 [-10,000，10,000]。

double findMaxAverage(vector<int>& nums, int k) {
	int res = 0,temp=0;
	for (int i = 0; i + k <= nums.size(); ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j < k; ++j)temp += nums[j];
			res = temp;
		}
		else {
			temp = temp - nums[i - 1] + nums[i + k - 1];
			if (temp > res)res = temp;
		}
	}
	return (double)res/(double)k;
}

int main() {
	//test1
	vector<int>nums = { 1,12,-5,-6,50,3 };
	double a = findMaxAverage(nums,4);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}