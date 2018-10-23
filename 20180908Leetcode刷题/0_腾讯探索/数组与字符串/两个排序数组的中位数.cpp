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

double findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
	//首先让数组1的长度小于等于数组2的长度
	if (nums1.size() - i > nums2.size() - j)
		return findKth(nums2, j, nums1, i, k);
	//终止条件
	if (nums1.size() == i)
		return nums2[j + k - 1];
	if (k == 1)
		return min(nums1[i], nums2[j]);
	int pa = min(i + k / 2, (int)nums1.size()), pb = j + k - pa + i;
	if (nums1[pa-1] < nums2[pb-1])
		return findKth(nums1, pa, nums2, j, k - pa + i);
	else if (nums1[pa-1]>nums2[pb-1])
		return findKth(nums1, i, nums2, pb, k - pb + j);
	else
		return nums1[pa-1];

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int a = nums1.size(), b = nums2.size();
	if (((a + b) & 1) == 0)//偶数
		return (findKth(nums1, 0, nums2, 0, (a + b) / 2) + findKth(nums1, 0, nums2, 0, (a + b) / 2 + 1)) / 2.0;
	else
		return findKth(nums1, 0, nums2, 0, (a + b) / 2+1);
}

int main() {
	//test1
	vector<int>nums1 = { 1, 3 }, nums2 = { 2 };
	double a = findMedianSortedArrays(nums1, nums2);

	//test2
	nums1 = { 1, 2 };
	nums2 = { 3, 4 };
	double b = findMedianSortedArrays(nums1, nums2);
	cout << a <<endl<< b << endl;
	//test end

	system("pause");
	return 0;
}