#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;


//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
//影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
//如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
//
//示例 1:
//输入: [1,2,3,1]
//输出: 4
//解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//     偷窃到的最高金额 = 1 + 3 = 4 。
//
//示例 2:
//输入: [2,7,9,3,1]
//输出: 12
//解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

//注意此题不一定为简单的奇数位或偶数位相加，应为迭代思考
//测试用例[2,1,1,2],答案为4
//此方法时间复杂度过大
//int rob(vector<int>& nums) {
//	if (nums.size() < 1)
//		return 0;
//	if (nums.size() == 1)
//		return nums[0];
//	vector<int>v1, v2;
//	if (nums.size()>=2)
//		v1.assign(nums.begin()+2,nums.end());
//	if(nums.size()>=3)
//		v2.assign(nums.begin()+3, nums.end());
//	int n1 = nums[0] + rob(v1);
//	int n2 = nums[1] + rob(v2);
//	return (n1 > n2 ? n1 : n2);
//}

//使用动态规划
//动态规划由于同时从相邻的两个房屋中盗取会触发警报所以：
//1.若选择第i个房间盗取财宝，就一定不能选择第i - 1个房间盗取财宝
//2.若不选择第i个房间，相当于只考虑前i - 1个房间
//
//1.确认原问题与子问题
//原问题是求n个房间的最优解，子问题是求前1个房间，前2个房间.....，前n - 1个房间的最优解
//
//2.确认状态
//第i个状态即为前i个房间能够获得的最大财宝（最优解）
//
//3.确认边界状态的值
//前1个房间的最优解，就是第1个房间的财宝值
//前2个房间的最优解，就是第1, 2个房间中较大的值
//
//4.确定状态转移方程
//
//a.选择第i个房间：第i个房间 + 前i - 2个房间的最优解
//b.不选择第i个房间：前i - 1个房间的最优解
//转移方程：dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]); i >= 3
//
//本文来自 从零开始学习的ZHL 的CSDN 博客 ，全文地址请点击：https ://blog.csdn.net/qq_22080999/article/details/80849540?utm_source=copy 
int rob(vector<int>& nums) {
	if (nums.size() < 1)return 0;
	if (nums.size() == 1)return nums[0];

	int shu1 = nums[0], shu2 = max(nums[0], nums[2]);//shu1为i-2子问题的解，shu2为i-1子问题的解
	//也可将解存入数组;
	for (int i = 2; i < nums.size(); ++i)
	{
		int temp = max(nums[i] + shu1, shu2);
		shu1 = shu2;
		shu2 = temp;
	}
	return shu2;
}

int main() {
	//test1
	vector<int>nums = { 1,2,3,1 };
	int a = rob(nums);

	//test2
	nums = { 2,7,9,3,1 };
	int b = rob(nums);

	//test3
	nums = { 2,1,1,2 };
	int c = rob(nums);
	cout << a << endl << b << endl<<c<<endl;
	//test end

	system("pause");
	return 0;
}