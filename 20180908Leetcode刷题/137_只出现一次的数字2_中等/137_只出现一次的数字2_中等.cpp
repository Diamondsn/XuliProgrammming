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

//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
//
//说明：
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//
//示例 1:
//输入: [2,2,3,2]
//输出: 3
//
//示例 2:
//输入: [0,1,0,1,0,1,99]
//输出: 99

int singleNumber(vector<int>& nums) {
	int res = 0;
	for (int i = 0; i < 32; ++i) {
		int count = 0;
		for (int j = 0; j < nums.size(); ++j) {
			//count += (nums[j] & (1 << i));//有符号整数符号位不能直接加
			if (nums[j] & (1 << i))
				count++;
		}
		if (count % 3)
			res |= (1 << i);
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 2,2,3,2 };
	int a = singleNumber(nums);

	//test2
	nums = { 0,1,0,1,0,1,99 };
	int b = singleNumber(nums);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}