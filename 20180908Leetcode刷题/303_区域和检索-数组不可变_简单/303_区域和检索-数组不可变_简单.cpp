#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
using namespace std;

//给定一个整数数组  nums，求出数组从索引 i 到 j(i ≤ j) 范围内元素的总和，包含 i, j 两点。
//
//示例：
//给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> - 1
//sumRange(0, 5) -> - 3
//
//说明:
//你可以假设数组不可变。
//会多次调用 sumRange 方法。

class NumArray {
public:
	NumArray(vector<int> nums) {
		number = nums;
	}

	int sumRange(int i, int j) {
		int sum = 0;
		for (int k = i; k <= j; k++)
		{
			sum += number[k];
		}
		return sum;
	}
	vector<int>number;
};
/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/

int main() {
	//test1
	vector<int>nums = { -2, 0, 3, -5, 2, -1 };
	NumArray obj = NumArray(nums);
	int a=obj.sumRange(0, 2);

	//test2
	int b = obj.sumRange(2, 5);

	//test3
	int c = obj.sumRange(0, 5);

	cout << a << endl << b << endl << c << endl;//1,-1,-3
	//test end
	system("pause");
	return 0;
}
