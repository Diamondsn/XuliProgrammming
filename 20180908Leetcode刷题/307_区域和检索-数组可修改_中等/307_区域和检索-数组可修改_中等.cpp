#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<unordered_set>
#include"time.h"
#include<bitset>
using namespace std;

//给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
//
//update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。
//
//示例:
//Given nums = [1, 3, 5]
//
//sumRange(0, 2) -> 9
//update(1, 2)
//sumRange(0, 2) -> 8
//
//说明:
//数组仅可以在 update 函数下进行修改。
//你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。

//初解，更新时花费时间较长
//class NumArray {
//public:
//	NumArray(vector<int> nums) {
//		m_nums = nums;
//		if (nums.size() <= 0)return;
//		m_sums.push_back(nums[0]);
//		for (int i = 1; i < nums.size(); ++i){
//			m_sums.push_back(m_sums[i - 1] + nums[i]);
//		}
//	}
//
//	void update(int i, int val) {
//		int chazhi = val - m_nums[i];
//		for (int m = i; m < m_sums.size(); ++m){
//			m_sums[m] += chazhi;
//		}
//		m_nums[i] = val;
//	}
//
//	int sumRange(int i, int j) {
//		return i>0?m_sums[j] - m_sums[i - 1]: m_sums[j];
//	}
//	vector<int>m_nums;
//	vector<int>m_sums;
//};

//使用树状数组，特殊数据结构
//https://www.cnblogs.com/grandyang/p/4985506.html
class NumArray {
public:
	NumArray(vector<int> nums) {
		num.resize(nums.size() + 1);
		bit.resize(nums.size() + 1);
		for (int i = 0; i < nums.size(); ++i)
			update(i, nums[i]);
	}

	void update(int i, int val) {
		int diff = val - num[i];
		for (int j = i + 1; j < num.size(); j += (j&-j)){
			bit[j] += diff;
		}
		num[i] = val;
	}

	int sumRange(int i, int j) {
		return getSum(j + 1) - getSum(i);//树状数组是从1开始的
	}
	
	int getSum(int i){
		int res = 0;
		for (int j = i; j > 0; j -= (j&-j)){
			res += bit[j];
		}
		return res;
	}

	vector<int>num;
	vector<int>bit;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* obj.update(i,val);
* int param_2 = obj.sumRange(i,j);
*/

void main(){
	//test1
	vector<int>nums = { 1, 3, 5 };
	NumArray obj(nums);
	int a = obj.sumRange(0, 2);
	obj.update(1, 2);
	int b = obj.sumRange(1, 2);
	cout << a << endl << b << endl;
	//test end
	system("pause");
}