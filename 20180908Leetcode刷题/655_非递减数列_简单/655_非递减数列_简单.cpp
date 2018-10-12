#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
using namespace std;

//给定一个长度为 n 的整数数组，你的任务是判断在最多改变 1 个元素的情况下，该数组能否变成一个非递减数列。
//
//我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，满足 array[i] <= array[i + 1]。
//
//示例 1:
//输入: [4,2,3]
//输出: True
//解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
//
//示例 2:
//输入: [4,2,1]
//输出: False
//解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
//说明:  n 的范围为 [1, 10,000]。

//注意[3，4，2，3]测试用例情况，其一共有3个逆序对，但这些逆序对中由两个因子3，4引起
//更改一个数可以将一个数的逆序对数量减为0
//故此题统计引起逆序对的因子的数量
bool checkPossibility(vector<int>& nums) {
	set<int>s1, s2;//分别存储逆序对的索引
	for (int i = 0; i < nums.size()-1; ++i){
		for (int j = i + 1; j < nums.size(); ++j){
			if (nums[i]>nums[j]){
				s1.insert(i);
				s2.insert(j);
			}
		}
		if (s1.size()>=2 && s2.size()>=2)return false;//必须最小值>=2才返回false
	}
	return true;
}

int main() {
	//test1
	vector<int>nums = { 4, 2, 3 };
	bool a = checkPossibility(nums);//true

	//test2
	nums = { 4, 2, 1 };
	bool b = checkPossibility(nums);//false

	//test3
	nums = { 3, 4, 2, 3 };
	bool c = checkPossibility(nums);//false

	//test4
	nums = { 2, 3, 3, 2, 4 };//注:此用例表明需分别统计逆序对两边因子的数量，两边因子数量的最小值>=2则false
	bool d = checkPossibility(nums);//true
	cout << a << endl << b << endl<<c<<endl<<d<<endl;
	//test end

	system("pause");
	return 0;
}