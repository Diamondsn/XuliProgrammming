﻿#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdint.h>
using namespace std;

//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//
//示例 1:
//
//给定 nums = [1,1,1,2,2,3],
//
//函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
//
//你不需要考虑数组中超出新长度后面的元素。
//
//示例 2:
//
//给定 nums = [0,0,1,1,1,1,2,3,3],
//
//函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
//
//你不需要考虑数组中超出新长度后面的元素。
//
//说明:
//
//为什么返回数值是整数，但输出的答案是数组呢?
//
//请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
//
//你可以想象内部操作如下:
//
//// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
//int len = removeDuplicates(nums);
//
//// 在函数里修改输入数组对于调用者是可见的。
//// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
//for (int i = 0; i < len; i++) {
//    print(nums[i]);
//}

int removeDuplicates(vector<int>& nums) {
	if (nums.size() <= 0)return 0;
	int kongwei=0,curnum=nums[0],num=1;
	for (int cur = 1; cur < nums.size(); ++cur){
		if (nums[cur] == curnum){
			num++;
		}
		else{
			curnum = nums[cur];
			num = 1;
		}
		if (num > 2){
			if (kongwei == 0)
				kongwei = cur;
		}
		if (kongwei != 0 && num<=2)
		{
			nums[kongwei++] = nums[cur];
		}
	}
	return kongwei==0?nums.size():kongwei;
}

void main() {
	//test1
	//vector<int>nums = { 1, 1, 1, 2, 2, 3 };
	vector<int>nums = { 1, 2, 2 };
	int a = removeDuplicates(nums);
	for (int i = 0; i < a; ++i){
		cout << nums[i] << ",";
	}
	cout << endl;

	//test2
	nums = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
	int b = removeDuplicates(nums);
	for (int i = 0; i < b; ++i){
		cout << nums[i] << ",";
	}
	cout << endl;
	//test end
	system("pause");
}
