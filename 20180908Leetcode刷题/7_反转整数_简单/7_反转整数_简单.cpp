#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

//给定一个 32 位有符号整数，将整数中的数字进行反转。
//
//示例 1:
//输入: 123
//输出: 321
//
//示例 2:
//输入: -123
//输出: -321
//
//示例 3:
//输入: 120
//输出: 21
//
//注意:
//假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

//int reverse(int x) {
//	vector<int>vec;
//	long long res=0;
//	int count = 0;
//	bool flag = true;
//	if (x < 0)flag = false;
//	x = abs(x);
//	while (x > 0) {
//		vec.push_back(x % 10);
//		count++;
//		x /= 10;
//	}
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		res += vec[i] * pow(10, count-1);
//		count--;
//	}//此题计算答案的时候可以不用统计当前数的位次，而是res=res*10+vec[i];
//	res = flag ? res:-1*res ;
//	return res > INT_MAX || res < INT_MIN ? 0:res ;
//}

//思想相同，代码精简版
int reverse(int x) {
	long long res = 0;
	bool flag = true;
	if (x < 0)flag = false;
	x = abs(x);
	while (x > 0) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	res = flag ? res : -1 * res;
	return res > INT_MAX || res < INT_MIN ? 0 : res;
}

void main() {
	//test1
	int a = reverse(123);

	//test2
	int b = reverse(-123);

	//test3
	int c = reverse(120);
	cout << a << endl << b << endl << c << endl;
	//test end
	system("pause");
}