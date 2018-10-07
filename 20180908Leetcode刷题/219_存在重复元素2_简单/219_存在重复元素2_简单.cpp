#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
using namespace std;

//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
//
//示例 1:
//输入: nums = [1,2,3,1], k = 3
//输出: true
//
//示例 2:
//输入: nums = [1,0,1,1], k = 1
//输出: true
//
//示例 3:
//输入: nums = [1,2,3,1,2,3], k = 2
//输出: false

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	map<int, int>hash;
	for (int i = 0; i < nums.size(); ++i) {
		if (hash.find(nums[i]) == hash.end())
			hash.insert(pair<int, int>(nums[i], i));
		else if (i - hash[nums[i]] <= k)
			return true;
		else
			hash[nums[i]] = i;
	}
	return false;
}

void main() {
	//test1
	vector<int>nums = { 1,2,3,1 };
	bool a = containsNearbyDuplicate(nums, 3);

	//test2
	nums = { 1,0,1,1 };
	bool b = containsNearbyDuplicate(nums, 1);

	//test3
	nums = { 1,2,3,1,2,3 };
	bool c = containsNearbyDuplicate(nums, 2);

	cout << a << endl << b << endl << c << endl;
	//test end
	system("pause");
}