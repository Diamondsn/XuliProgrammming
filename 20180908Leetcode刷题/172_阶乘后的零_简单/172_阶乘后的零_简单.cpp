#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个整数 n，返回 n! 结果尾数中零的数量。
//
//示例 1:
//输入: 3
//输出: 0
//解释: 3! = 6, 尾数中没有零。
//
//示例 2:
//输入: 5
//输出: 1
//解释: 5! = 120, 尾数中有 1 个零.
//说明: 你算法的时间复杂度应为 O(log n) 。

//得到一个数的5和2的因子数
//void GetYinzi(int a, int &b, int & c) {
//	b = 0; c = 0;
//	if (a <= 0)return;
//	while (a % 5 == 0)
//	{
//		b++;
//		a /= 5;
//	}
//	while (a % 2 == 0)
//	{
//		c++;
//		a /= 2;
//	}
//}
//
////该方法超出时间限制;
//int trailingZeroes(int n) {
//	if (n <= 4)return 0;
//	int sumb = 0, sumc = 0;
//	for (int i = n; i > 1; --i) {
//		int b = 0, c = 0;
//		GetYinzi(i, b, c);
//		sumb += b;
//		sumc += c;
//	}
//	return sumb < sumc ? sumb : sumc;
//}

//此问题有规律，每到5的倍数这个数的阶乘增加一个零
int trailingZeroes(int n) {
	int count = 0;
	while (n > 0) {
		count += n % 5;
		n /= 5;
	}
	return count;
}

int main() {
	//test1
	int a = trailingZeroes(0);

	//test2
	int b = trailingZeroes(5);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}