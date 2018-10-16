#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
using namespace std;

//给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
//
//找到所有出现两次的元素。
//
//你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
//
//示例：
//输入:
//[4,3,2,7,8,2,3,1]
//
//输出:
//[2,3]

//初解不正确，因为没有出现的位和出现两次的位的结果是一样的，不能再操作以后再统计
//应该在操作的过程中进行统计
//如果一个数已经取了复数，后又轮训到，则索引位位结果答案
//vector<int> findDuplicates(vector<int>& nums) {
//	for (int i = 0; i < nums.size(); ++i){
//	nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
//	}
//	vector<int>res;
//	for (int i=0; i < nums.size(); ++i){
//	if (nums[i]>0)res.push_back(i + 1);
//	}
//	return res;
//}

vector<int> findDuplicates(vector<int>& nums) {
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i){
		if (nums[abs(nums[i]) - 1] < 0)res.push_back(abs(nums[i]));
		nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int>res = findDuplicates(nums);
	for (int temp : res){
		cout << temp << endl;
	}
	//test end

	system("pause");
	return 0;
}