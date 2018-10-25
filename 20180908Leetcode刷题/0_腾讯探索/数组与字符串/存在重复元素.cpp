#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定一个整数数组，判断是否存在重复元素。
//如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
//
//示例 1:
//输入: [1,2,3,1]
//输出: true
//
//示例 2:
//输入: [1,2,3,4]
//输出: false
//
//示例 3:
//输入: [1,1,1,3,3,4,3,2,4,2]
//输出: true

//1解，排序后轮询O(nlogn),此解速度较快
bool containsDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < (int)nums.size() - 1; ++i){//size_t减一必须先将size_t转化为int
		if (nums[i] == nums[i + 1])return true;
	}
	return false;
}

////2解 用set直接赋值，看set的size和nums的size是否相同，需要用红黑树插入操作
//bool containsDuplicate(vector<int>& nums){
//	set<int>myset(nums.begin(),nums.end());
//	return myset.size() < nums.size();
//}
//
////3解 用hash进行插入和查找,此处查找必须用hash自己的查找，用stl的查找很慢
//bool containsDuplicate(vector<int>& nums){
//	set<int>vec;
//	for (int i = 0; i < nums.size(); ++i){
//		if (vec.find(nums[i])==vec.end())
//			vec.insert(nums[i]);
//		else
//			return true;
//	}
//	return false;
//}

int main() {
	//test1
	vector<int>nums = { 1, 2, 3, 1 };
	bool a = containsDuplicate(nums);

	//test2
	nums = { 1, 2, 3, 4 };
	bool b = containsDuplicate(nums);

	//test3
	nums = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
	bool c = containsDuplicate(nums);
	cout << a << endl << b << endl << c << endl;
	//test end

	system("pause");
	return 0;
}