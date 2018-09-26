#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

//给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
//
//找到所有在 [1, n] 范围之间没有出现在数组中的数字。
//
//您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
//
//示例:
//输入:
//[4,3,2,7,8,2,3,1]
//
//输出:
//[5,6]


vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int>res;
	for (int i = 0; i < nums.size(); ++i)
	{
		if(nums[abs(nums[i]) - 1]>0)
			nums[abs(nums[i]) - 1]= -nums[abs(nums[i]) - 1];
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > 0)
			res.push_back(i+1);//未被访问的索引即为缺失的数
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = {4,3,2,7,8,2,3,1};
	vector<int>res = findDisappearedNumbers(nums);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}