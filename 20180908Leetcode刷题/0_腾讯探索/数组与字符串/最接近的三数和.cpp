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

int threeSumClosest(vector<int>& nums, int target) {

}

int main() {
	//test1
	vector<int>nums = { -1, 2, 1, -4 };
	int target = 1;
	int a = threeSumClosest(nums, target);
	//test end

	system("pause");
	return 0;
}