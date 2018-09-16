#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<algorithm>
using namespace std;

//给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
//
//说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
//
//示例 1:
//输入: [3,2,3]
//输出: [3]
//
//示例 2:
//输入: [1,1,1,3,3,2,2,2]
//输出: [1,2]

vector<int> majorityElement(vector<int>& nums) {

}

void main() {
	//test 1
	vector<int>nums1 = { 3,2,3 };
	vector<int>nums2 = { 1,1,1,3,3,2,2,2 };
	vector<int> result1 = majorityElement(nums1);
	vector<int> result2 = majorityElement(nums2);
	cout << "test1" << endl;
	for (int i = 0; i < result1.size(); ++i)
	{
		cout << result1[i] << endl;
	}
	cout << "test2" << endl;
	for (int i = 0; i < result2.size(); ++i)
	{
		cout << result2[i] << endl;
	}
	//test end
	system("pause");
}
