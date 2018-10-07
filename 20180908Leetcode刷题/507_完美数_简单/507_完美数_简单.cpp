#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

//对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。
//
//给定一个 正整数 n， 如果他是完美数，返回 True，否则返回 False
//
//示例：
//输入: 28
//输出: True
//解释: 28 = 1 + 2 + 4 + 7 + 14
// 
//注意:
//输入的数字 n 不会超过 100,000,000. (1e8)

//此种方法使用完美数定义，在检验较大的数的时候会超出时间
//bool checkPerfectNumber(int num) {
//	int sum = 0;
//	for (int i = 1; i < num; ++i) {
//		if (num%i == 0)
//			sum += i;
//		if (sum > num)
//			return false;
//	}
//	return num == sum ? true:false;
//}

bool checkPerfectNumber(int num) {//num一半的因子都在1~sqrt(num)中,可以快速削减需要判断的数的数量
	if (num == 1)return false;
	int sum = 1;
	int n = sqrt(num);
	for (int i = 2; i <= n; ++i)
	{
		if (num % i == 0)
			sum += i + num / i;
	}
	return sum == num;
}

void main() {
	//test1
	bool a = checkPerfectNumber(28);

	bool b = checkPerfectNumber(99999994);
	cout << a << endl << b << endl;
	//test end
	system("pause");
}