#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
using namespace std;

//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
//
//请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
//
//你可以假设 nums1 和 nums2 不同时为空。
//
//示例 1:
//nums1 = [1, 3]
//nums2 = [2]
//中位数是 2.0
//
//示例 2:
//nums1 = [1, 2]
//nums2 = [3, 4]
//中位数是 (2 + 3)/2 = 2.5

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

}

int main() {
	//test1
	vector<int>nums1 = { 1, 3 }, nums2 = { 2 };
	double a = findMedianSortedArrays(nums1, nums2);

	//test2
	nums1 = { 1, 2 };
	nums2 = { 3, 4 };
	double b = findMedianSortedArrays(nums1, nums2);
	cout << a << b << endl;
	//test end

	system("pause");
	return 0;
}