#include<iostream>
#include<vector>
#include<stack>
#include<stdint.h>
using namespace std;

//不使用运算符 + 和 -，计算两整数a 、b之和。
//
//示例 1:
//输入 : a = 1, b = 2
//输出 : 3
//	
//示例 2 :
//输入 : a = -2, b = 3
//输出 : 1

int getSum(int a, int b) {
	if (b == 0)
		return a;

	int c = a^b;
	int d = a&b;
	int result = getSum(c, d << 1);
	return result;
}

void main(){
	//test1
	int a, b;
	a = 1;
	b = 2;
	int result = getSum(a, b);
	cout << result << endl;

	a = -2;
	b = 3;
	result = getSum(a, b);
	cout << result << endl;

	//test end
	system("pause");
}
