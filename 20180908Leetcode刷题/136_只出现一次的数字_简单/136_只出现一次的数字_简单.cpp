#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
//找出那个只出现了一次的元素。
//
//说明：
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//
//示例 1:
//输入: [2, 2, 1]
//输出 : 1
//	
//示例 2 :
//输入 : [4, 1, 2, 1, 2]
//输出 : 4

//此方法时间复杂度过大，因为有排序
//int singleNumber(vector<int>& nums) {
//	sort(nums.begin(), nums.end());
//	for (int i = 0; i < nums.size(); i+=2)
//	{
//		if (i + 1 < nums.size() && nums[i] != nums[i + 1])
//			return nums[i];
//	}
//	return nums.back();
//}

//对于任意整数n，n ^ 0 = n, n ^ n = 0 ,相同的元素异或结果为0,0和n异或得自己，
//最终全部异或的值即为只出现一次的值
int singleNumber(vector<int>& nums) {
	int result=0;
	for (int i = 0; i < nums.size(); ++i)
	{
		result ^= nums[i];
	}
	return result;
}

int main() {
	//test1
	vector<int> nums = { 2,2,1 };
	int a = singleNumber(nums);

	nums = { 4,1,2,1,2 };
	int b = singleNumber(nums);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}