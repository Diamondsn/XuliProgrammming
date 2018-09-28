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

/**********************/
//快速排序时间复杂度
//
//最差:O(n^2)
//平均:O(nlogn)
//最佳:O(nlogn)
/**********************/

//使用vector的占用新空间的快速排序
vector<int> Q_sort(vector<int>& nums)
{
	vector<int>res;
	if (nums.size() <= 1){
		res = nums;
		return res;
	}
	int k = nums[0];
	vector<int>leftvec, rightvec, leftres, rightres;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] < k)
			leftvec.push_back(nums[i]);
		else
			rightvec.push_back(nums[i]);
	}
	leftres=Q_sort(leftvec);
	rightres=Q_sort(rightvec);
	for (int i = 0; i < leftres.size(); ++i)
		res.push_back(leftres[i]);
	res.push_back(k);
	for (int i = 0; i < rightres.size(); ++i)
		res.push_back(rightres[i]);
	return res;
}

int main() {
	//test1
	vector<int>nums = { 10, 9,8,7,6,5,4,3,2,1};
	vector<int>res=Q_sort(nums);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}

	//test end
	system("pause");
	return 0;
}
