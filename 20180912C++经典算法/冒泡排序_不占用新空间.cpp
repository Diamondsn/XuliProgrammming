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
//冒泡排序时间复杂度
//
//最佳 :O(n^2)
//平均 :O(n^2)
//最差 :O(n^ 2);
/********************************/

//冒泡排序的内部交换函数
void Swap(vector<int>& nums, int i, int j)
{
	if (i == j)
		return;
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

//不占用新空间的冒泡排序
void bubble_sort(vector<int>& nums)
{
	for (int i = 1; i < nums.size(); ++i)
	{
		for (int j = nums.size() - 1; j > 0; --j)
		{
			if (nums[j] < nums[j - 1])
				Swap(nums, j, j - 1);
		}
	}
}

int main() {
	//test1
	vector<int>nums = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	bubble_sort(nums);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << endl;
	}

	//test end
	system("pause");
	return 0;
}
