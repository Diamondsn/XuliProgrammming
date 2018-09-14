#include<iostream>
#include<vector>
#include<stack>
#include<stdint.h>
using namespace std;

//编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数
//（也被称为汉明重量）。
//
//示例 :
//输入 : 11
//输出 : 3
//解释 : 整数 11 的二进制表示为 00000000000000000000000000001011
//
//示例 2 :
//输入 : 128
//输出 : 1
//解释 : 整数 128 的二进制表示为 00000000000000000000000010000000

int hammingWeight(uint32_t n) {
	int result = 0;
	for (int i = 31; i >= 0; --i)
	{
		int m = (n >> i) & 1;
		if (m == 1)
			result++;
	}
	return result;
}

void main(){
	//test
	int m = hammingWeight(11);
	int n = hammingWeight(128);
	cout << m << endl << n << endl;//3,1
	//test end
	system("pause");
}
