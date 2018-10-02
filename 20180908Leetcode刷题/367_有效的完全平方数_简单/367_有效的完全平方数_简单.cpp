#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
//
//说明：不要使用任何内置的库函数，如  sqrt。
//
//示例 1：
//输入：16
//输出：True
//
//示例 2：
//输入：14
//输出：False

//此题必须用long long类型，否则会超出时间限制
//bool isPerfectSquare(int num) {
//	long long left = 0, right = num;
//	while (left <= right) {
//		long long temp = (left + right) / 2;
//		long long mid = temp*temp;
//		if (mid == num)
//			return true;
//		else if (mid < num)
//			left = (left + right) / 2+1;
//		else if (mid > num)
//			right = (left + right) / 2-1;
//	}
//	return false;
//}

//巧法，所有的平方数均可表达为连续奇数之和
bool isPerfectSquare(int num)
{
	int i = 1;
	while (num > 0) {
		num -= i;
		i += 2;
	}
	return num == 0;
}

int main() {
	//test1
	bool a = isPerfectSquare(9);

	//test2
	bool b = isPerfectSquare(14);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}