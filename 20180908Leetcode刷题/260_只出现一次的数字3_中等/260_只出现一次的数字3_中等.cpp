#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;

//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
//
//示例 :
//输入: [1,2,1,3,2,5]
//输出: [3,5]
//注意：
//结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
//你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

//C++11支持for in循环
//思路:对所有数循环，最后结果即为那两个只出现一次的数的异或
//再对其进行分组，分组目的是制造出所有数出现两次，只有一个数出现了一次的简单情形
//分组依据，由所有数异或结果最低一位1可得到那两个特殊数在该位上一定一个为1，一个为0
//根据与最低位为1其他为0的数进行与操作，为1和为0两种情况进行分组
vector<int> singleNumber(vector<int>& nums) {
	vector<int>res;
	int x = 0,res1=0,res2=0;
	for (int num : nums) x ^= num;
	x &= -x;//和自己的负数与操作可得到最低位为1其他位为0的数
	for (int num : nums)
	{
		if (x&num)res1 ^= num;
		else res2 ^= num;
	}
	res.push_back(res1);
	res.push_back(res2);
	return res;
}

int main() {
	//subtest
	//以下测试一个数和自己的负数与运算得到
	//保留该数最右一个1，其余位置0
	int a =2; int b = -2;
	int c = a&b;
	//subtest end

	//test1
	vector<int>nums = { 1,2,1,3,2,3,4,5 ,4,100};
	vector<int>res = singleNumber(nums);
	for (int i = 0; i < res.size(); ++i)cout << res[i] << endl;
	//test end

	system("pause");
	return 0;
}