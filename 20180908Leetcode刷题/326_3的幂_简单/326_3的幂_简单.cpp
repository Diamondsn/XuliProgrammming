#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
using namespace std;

//给定一个整数，写一个函数来判断它是否是 3 的幂次方。
//
//示例 1:
//输入: 27
//输出: true
//
//示例 2:
//输入: 0
//输出: false
//
//示例 3:
//输入: 9
//输出: true
//
//示例 4:
//输入: 45
//输出: false
//进阶：
//你能不使用循环或者递归来完成本题吗？

//使用循环
//bool isPowerOfThree(int n) {
//	if (n == 1)
//		return true;
//	if (n <= 0 ||n%3!=0)
//		return false;
//	while (n >1)
//	{
//		if (n % 3)
//			return false;
//		n=n / 3;
//	}
//	return true;
//}

//使用递归
//bool isPowerOfThree(int n) {
//	if (n <= 0)
//		return false;
//
//	if (n == 1)
//		return true;
//
//	return n%3==0 && isPowerOfThree(n / 3);
//}

//使用对数
//bool isPowerOfThree(int n)
//{
//	double cishu = log10(n) / log10(3);
//	return cishu == (int)cishu ? true:false;//次数double先转换为int后转化为double进行比较
//}

//使用int中能表示的最大的3的幂的数来取余n，余数为0则是3的幂
bool isPowerOfThree(int n)
{
	if (n <= 0)return false;
	int x = 0x7fffffff;
	int cishu = log10(x) / log10(3);
	int max = pow(3, cishu);
	return max%n == 0;
}

int main() {
	//test1
	bool a = isPowerOfThree(27);

	//test2
	bool b = isPowerOfThree(0);

	//test3
	bool c = isPowerOfThree(9);

	//test4
	bool d = isPowerOfThree(45);

	cout << a << endl << b << endl << c << endl<<d<<endl;
	//test end
	system("pause");
	return 0;
}
