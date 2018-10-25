#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
//例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

//采用三数和的思路，固定第一个值，用双指针轮询后面两个数
int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() < 3)return 0;
	sort(nums.begin(), nums.end());
	int chaju = abs(nums[0] + nums[1] + nums[2] - target),ressum=nums[0]+nums[1]+nums[2],sum;
	for (int i = 0; i < nums.size() - 2; ++i){
		int left = i + 1, right = nums.size() - 1;
		while (left < right){
			int tempsum = nums[i] + nums[left] + nums[right];
			int tempchaju = abs(tempsum - target);
			if (tempchaju < chaju){
				chaju = tempchaju;
				ressum = tempsum;
			}
			if (tempsum < target)
				left++;
			else if (tempsum > target)
				right--;
			else return tempsum;
		}
	}
	return ressum;
}

int main() {
	//test1
	vector<int>nums = { -1,2,1,-4 };
	int target = 1;
	int a = threeSumClosest(nums, target);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}