#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
using namespace std;

/********************************/
//插入排序时间复杂度
//
//最佳 : O(n)//当待排序数组已经排好序时，无需移动数据仅需内循环比较n次
//平均 :O(n^2)
//最差 : O(n^ 2);
/********************************/

//插入排序内部交换函数
void Swap(vector<int>&nums, int i, int j)
{
	if (i == j)
		return;
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

//不占用新空间的插入排序
void insert_sort(vector<int>& nums)
{
	for (int i = 1; i < nums.size(); ++i)
	{
		for (int j = i; j>0 &&nums[j]<nums[j-1]; --j)//顺次交换待排序子数组
		{
			Swap(nums, j, j - 1);
		}
	}
}

int main() {
	//test1
	vector<int>nums = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	insert_sort(nums);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << endl;
	}

	//test end
	system("pause");
	return 0;
}
