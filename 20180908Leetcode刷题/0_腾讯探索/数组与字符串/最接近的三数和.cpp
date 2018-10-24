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
	if (nums.size() < 3)return 0;
	sort(nums.begin(), nums.end());
	if (target <= nums[0])
		return nums[0] + nums[1] + nums[2];
	else if (target >= nums[nums.size() - 1])
		return nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
	else
	{
		int l = 0, r = nums.size() - 1,mid;
		while (r>=l){
			mid = (r + l) / 2;
			if (nums[mid] > target && nums[mid - 1] <= target)
				break;
			else if (nums[mid] <= target)
				l = mid+1;
			else if (nums[mid] >= target)
				r = mid-1;
		}
		mid = (r + l) / 2;
		l = mid - 3 >= 0 ? mid - 3 : 0;
		r = mid + 3 < nums.size() ? mid + 3 : nums.size() - 1;
		int chaju = abs(nums[l] + nums[l + 1] + nums[l + 2] - target);
		int max = nums[l] + nums[l + 1] + nums[l + 2];
		for (int i = l+1; i+2 <= r; ++i){
			if (abs(nums[i] + nums[i + 1] + nums[i + 2] - target) < chaju)
			{
				chaju = abs(nums[i] + nums[i + 1] + nums[i + 2] - target);
				max = nums[i] + nums[i + 1] + nums[i + 2];
			}
		}
		return max;
	}
}

int main() {
	//test1
	vector<int>nums = { 0,2,1,-3 };
	int target = 1;
	int a = threeSumClosest(nums, target);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}