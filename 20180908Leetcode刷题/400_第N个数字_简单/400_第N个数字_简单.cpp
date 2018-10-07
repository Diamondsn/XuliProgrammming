#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

//在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
//
//注意:
//n 是正数且在32为整形范围内 ( n < 2^31)。
//
//示例 1:
//输入:
//3
//输出:
//3
//
//示例 2:
//输入:
//11
//输出:
//0
//
//说明:
//第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。

int findNthDigit(int n) {
	int count = 1;
	long long t = 9 * pow(10, count - 1)*count;//此处计算可能会超过int所能表示的最大数
	while (n>t) {
		n -= t;
		count++;
		t= 9 * pow(10, count - 1)*count;
	}
	int num = pow(10, count-1)+(n-1)/count;//此处num能表示为int
	n=count-(n-1) % count;
	//求解num的从右数n位;
	while (n > 1) {
		num /= 10;
		n--;
	}
	return num % 10;
}

void main() {
	//test1
	int a = findNthDigit(1000000000);

	//test2
	int b = findNthDigit(11);
	cout << a << endl << b << endl;
	//test end
	system("pause");
}