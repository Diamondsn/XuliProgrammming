﻿#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明:
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//
//示例:
//输入:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//输出: [1,2,2,3,5,6]

//思路:从后往前归并
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int cur = m + n - 1;
	while (n>0){
		if ((m>0&&nums1[m - 1] <= nums2[n - 1])||(m<=0)){
			nums1[cur] = nums2[n - 1];
			n--;
		}
		else{
			nums1[cur] = nums1[m - 1];
			m--;
		}
		cur--;
	}
}

int main() {
	//test1
	vector<int>nums1 = { 3,4,5, 0, 0, 0 }, nums2 = { 2, 5, 6 };
	merge(nums1, 3, nums2,3);
	for (int t : nums1)
		cout << t << endl;
	//test end

	system("pause");
	return 0;
}