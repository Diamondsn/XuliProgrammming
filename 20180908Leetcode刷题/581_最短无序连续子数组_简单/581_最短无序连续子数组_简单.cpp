#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdint.h>
#include<map>
using namespace std;

//给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
//
//你找到的子数组应是最短的，请输出它的长度。
//
//示例 1:
//输入: [2, 6, 4, 8, 10, 9, 15]
//输出: 5
//解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
//
//说明 :
//输入的数组长度范围在 [1, 10,000]。
//输入的数组可能包含重复元素 ，所以升序的意思是<=。

int findUnsortedSubarray(vector<int>& nums) {
	vector<int>n = nums;
	sort(n.begin(), n.end());
	int i, j;
	for (i = 0; i < n.size(); ++i) {
		if (n[i] != nums[i])break;
	}
	for (j = n.size() - 1; j >= 0; --j) {
		if (n[j] != nums[j])break;
	}
	return (j>i?j - i+1:0);//如果原数组已经排好序，则j<i，直接输出0
}

int main() {
	//test1
	vector<int>nums = { 2,6,4,8,10,9,15 };
	int a = findUnsortedSubarray(nums);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}