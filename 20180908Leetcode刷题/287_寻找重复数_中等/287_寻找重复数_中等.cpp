#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<map>
using namespace std;

//给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
//
//示例 1:
//输入: [1,3,4,2,2]
//输出: 2
//
//示例 2:
//输入: [3,1,3,4,2]
//输出: 3
//
//说明：
//不能更改原数组（假设数组是只读的）。
//只能使用额外的 O(1) 的空间。
//时间复杂度小于 O(n2) 。
//数组中只有一个重复的数字，但它可能不止重复出现一次。

int findDuplicate(vector<int>& nums) {

}

int main() {
	//test1
	vector<int>nums = { 1,3,4,2,2 };
	int a = findDuplicate(nums);

	//test2
	nums = { 3,1,3,4,2 };
	int b = findDuplicate(nums);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}