#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
//
//示例 1:
//输入: 16
//输出: true
//
//示例 2:
//输入: 5
//输出: false
//
//进阶：
//你能不使用循环或者递归来完成本题吗？

//这到题和Power of two类似，如果不能用递归循环做，就使用位操作。1个数是2的幂肯定是4的幂，
//但反过来不成立，4的幂只能是奇数位为1，而2的幂只有有一个位置为1就行。
//
//所以先判断是否为2的幂，然后通过与.0X55555555(....1010101)进行&操作，保留奇数位，判断是否改变。
//
//本文来自 记忆力不好 的CSDN 博客 ，全文地址请点击：https ://blog.csdn.net/chenchaofuck1/article/details/51227222?utm_source=copy 
//此处使用位运算
bool isPowerOfFour(int num) {
	if (num <= 0)
		return false;

	return ((num & num - 1) == 0 && (num & 0x55555555) == num);//是2的幂同时奇数位才能有1
}

int main() {
	//test1
	bool a = isPowerOfFour(8);

	//test2
	bool b = isPowerOfFour(5);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}