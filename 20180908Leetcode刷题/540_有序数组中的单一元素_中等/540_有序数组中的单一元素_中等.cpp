#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。
//
//示例 1:
//输入: [1,1,2,3,3,4,4,8,8]
//输出: 2
//
//示例 2:
//输入: [3,3,7,7,10,11,11]
//输出: 10
//注意: 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。

int singleNonDuplicate(vector<int>& nums) {
	if (nums.size() == 1)return nums[0];
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if ((mid == 0 && nums[mid] != nums[mid + 1]) || (mid == nums.size() - 1 && nums[mid] != nums[mid - 1]) || (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]))
			return nums[mid];
		else if ((mid % 2 == 0&& nums[mid]==nums[mid+1])||(mid%2==1 && nums[mid]==nums[mid-1])) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int main() {
	//test1
	vector<int>nums = { 10 };
	int a = singleNonDuplicate(nums);

	//test2
	nums = { 3,3,7,7,10,11,11 };
	int b = singleNonDuplicate(nums);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}