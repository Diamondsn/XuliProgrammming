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

//此题用于面试
//找出连续数组但乱序中唯一出现多次的数
//https://segmentfault.com/a/1190000003817671

/**************************************/
//1.使用hash表进行查询，空间O(n)，时间O(n),hash插入和查询需要时间

//2.从左边查询一个数和右边查询，看索引是不是一样，时间O(n^2)

//3.先排序再遍历，更改原始数组，时间O(nlogn)

//4.二分法进行查找，使用抽屉原理，n个盒子放n+1双袜子，肯定有一个盒子里放了两双,时间O(nLogn)

//5.数组索引和数组内存的值存在映射关系，如果存在两个索引映射到同一个数，即通过索引去轮询即形成了环，
//该问题转换为寻找环的交叉点的问题，应该使用快慢指针法
/**************************************/

//以下使用二分法和抽屉原理
//int findDuplicate(vector<int>& nums) {
//	int left = 1,right = nums.size() - 1;
//	while (left <= right) {
//		int mid = (left + right) / 2,count=0;
//		for (int t : nums) {
//			if (t <= mid)
//				count++;
//		}
//		if (count <= mid)
//			left = mid + 1;
//		else
//			right = mid - 1;
//	}
//	return left;
//}

//以下 为二分法另解
//int findDuplicate(vector<int>& nums) {
//	int left = 1, right = nums.size() - 1;
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		int l = 0, m = 0, r = 0;
//		for (int t : nums) {
//			if (t == mid)m++;
//			else if (t >= left && t < mid)l++;
//			else if (t > mid && t <= right)r++;
//		}
//		if (m > 1)return mid;
//		if (l < r)
//			left = mid + 1;
//		else
//			right = mid - 1;
//	}
//}

//快慢指针法,时间复杂度O(n)
//int findDuplicate(vector<int>& nums) {
//	int kuai = 0, man = 0;
//	do {
//		kuai = nums[nums[kuai]];
//		man = nums[man];
//	} while (kuai != man);
//	int res = 0;//需要从头开始
//	while (res!=man) {
//		res = nums[res];
//		man = nums[man];
//	}
//	return res;
//}

//快慢指针法另解
int findDuplicate(vector<int>& nums) {
	int kuai = 0, man = 0;
	do {
		kuai = nums[nums[kuai]];
		man = nums[man];
	} while (nums[kuai] != nums[man]);
	int res = 0;//需要从头开始
	while (nums[res]!=nums[man]) {
		res = nums[res];
		man = nums[man];
	}
	return nums[res];
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