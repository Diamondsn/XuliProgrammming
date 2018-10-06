#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//输入: [1,2,3,4,5,6,7] 和 k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右旋转 1 步: [7,1,2,3,4,5,6]
//向右旋转 2 步: [6,7,1,2,3,4,5]
//向右旋转 3 步: [5,6,7,1,2,3,4]
//
//示例 2:
//输入: [-1,-100,3,99] 和 k = 2
//输出: [3,99,-1,-100]
//解释: 
//向右旋转 1 步: [99,-1,-100,3]
//向右旋转 2 步: [3,99,-1,-100]
//
//说明:
//尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//要求使用空间复杂度为 O(1) 的原地算法。

void rotate(vector<int>& nums, int k) {
	k %= nums.size();
	if (k == 0)return;
	bool flag = k <= nums.size()?true:false;
	k = k <= nums.size() / 2 ? k : nums.size() - k;

}

void main() {
	//test1
	vector<int>nums = { 1,2,3,4,5,6,7 };
	rotate(nums,3);
	for (int i = 0; i < nums.size(); ++i)cout << nums[i] << ",";
	cout << endl<<"test2";

	vector<int>nums1 = { -1,-100,3,99 };
	rotate(nums1, 2);
	for (int i = 0; i < nums1.size(); ++i)cout << nums1[i] << ",";
	cout << endl;

	//test end
	system("pause");
}
