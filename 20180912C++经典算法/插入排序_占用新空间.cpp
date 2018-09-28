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

//占用新空间的插入排序
vector<int> insert_sort(vector<int>& nums)
{
	vector<int>res;
	res.push_back(nums[0]);
	auto it = res.begin();
	for (int i = 1; i < nums.size(); ++i)
	{
		for (it = res.begin(); it != res.end() && nums[i] > *it; ++it);//直接找到插入位置，要么末尾，要么中间
		     res.insert(it, nums[i]);
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int>res=insert_sort(nums);
	for (int i = 0; i < res.size(); ++i)
	{
		cout <<res[i] << endl;
	}

	//test end
	system("pause");
	return 0;
}
