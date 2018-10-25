#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//
//示例:
//输入: [1,2,3,4]
//输出: [24,12,8,6]
//说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//
//进阶：
//你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

vector<int> productExceptSelf(vector<int>& nums) {
	vector<int>res;
	res.push_back(1);
	for (int i = 1; i < nums.size(); ++i)
		res.push_back(res[i - 1] * nums[i - 1]);
	int m = 1;
	for (int i = nums.size() - 2; i >= 0; --i){
		m *= nums[i + 1];
		res[i] *= m;
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 1, 2, 3, 4 };
	vector<int>res = productExceptSelf(nums);
	for (int i : res)cout << i << endl;
	//test end

	system("pause");
	return 0;
}