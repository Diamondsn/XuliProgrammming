#include<iostream>
#include<vector>
using namespace std;

//给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如(a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。
//
//示例 1:
//输入 : [1, 4, 3, 2]
//输出 : 4
//
//解释 : n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
//  
//提示 :
//n 是正整数, 范围在[1, 10000].
//数组中的元素范围在[-10000, 10000].

void Swap(vector<int>& nums, int i, int j)
{
	if (i == j)
		return;

	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

int core(vector<int>& nums, int i, int j,int pivot)
{
	do{
		while (nums[++i] < pivot);
		while ((j!=0) && nums[--j] >= pivot);
		Swap(nums, i, j);
	} while (i < j);
	Swap(nums,i, j);
	return i;
}

void kuaisupaixu(vector<int>& nums,int i,int j)
{
	if (i>=j)
		return;

	int pivotindex = (i+j) / 2;
	Swap(nums, pivotindex, j);
	int k = core(nums, i-1, j,nums[j]);
	Swap(nums, k, j);

	kuaisupaixu(nums, i, k - 1);
	kuaisupaixu(nums, k + 1, j);
}

int arrayPairSum(vector<int>& nums) {
	if (nums.size() < 2)
		return 0;

	kuaisupaixu(nums, 0, nums.size()-1);
	int result=0;
	for (size_t i = 0; i < nums.size(); i+=2)
	{
		result += nums[i];
	}
	return result;
}

void main(){
	//test 1
	/*vector<int> vec = { 1, 4, 3, 2 };
	int result = arrayPairSum(vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
	cout << "结果为"<<result << endl;*/
	//test 2 
	vector<int> vec1 = { 1, 1, 1, 1 };
	int result = arrayPairSum(vec1);
	for (int i = 0; i < vec1.size(); ++i)
	{
		cout << vec1[i] << endl;
	}
	cout << "结果为" << result << endl;
	//test end
	system("pause");
}
