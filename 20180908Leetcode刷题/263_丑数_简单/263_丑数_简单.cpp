#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

//编写一个程序判断给定的数是否为丑数。
//
//丑数就是只包含质因数 2, 3, 5 的正整数。
//
//示例 1:
//输入: 6
//输出: true
//解释: 6 = 2 × 3
//
//示例 2:
//输入: 8
//输出: true
//解释: 8 = 2 × 2 × 2
//
//示例 3:
//输入: 14
//输出: false 
//解释: 14 不是丑数，因为它包含了另外一个质因数 7。
//
//说明：
//1 是丑数。
//输入不会超过 32 位有符号整数的范围: [−231,  231 − 1]。

bool isUgly(int num) {
	if (num <= 0)
		return false;
	if (num == 1)
		return true;

	if (num % 2 && num % 3 && num % 5)
		return false;

	if (!(num % 2))
		return isUgly(num / 2);
	else if (!(num % 3))
		return isUgly(num / 3);
	else if (!(num % 5))
		return isUgly(num / 5);

	return true;
}

int main() {
	//test1
	bool a = isUgly(6);

	//test2
	bool b = isUgly(8);

	//test3
	bool c = isUgly(14);
	cout << a << endl << b << endl << c << endl;
	//test end

	system("pause");
	return 0;
}