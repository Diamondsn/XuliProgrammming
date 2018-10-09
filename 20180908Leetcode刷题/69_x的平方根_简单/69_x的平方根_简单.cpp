#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdint.h>
#include<map>
using namespace std;

//实现 int sqrt(int x) 函数。
//
//计算并返回 x 的平方根，其中 x 是非负整数。
//
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
//
//示例 1:
//输入: 4
//输出: 2
//
//示例 2:
//输入: 8
//输出: 2
//说明: 8 的平方根是 2.82842..., 
//     由于返回类型是整数，小数部分将被舍去。

int mySqrt(int x) {
	if (x <2)return x;
	long long temp1,temp2;
	for (long long i = 1; i <= x / 2; ++i)//注意此题应用long long
	{
		temp1 = i*i;
		temp2 = (i + 1)*(i + 1);
		if ((temp1 == x) || (temp1 < x && temp2 > x))
			return i;
	}
}

int main() {
	//test1
	int a = mySqrt(4);

	//test2
	int b = mySqrt(8);

	//test3
	int c = mySqrt(2147483647);
	cout << a << endl << b << endl<<c<<endl;
	//test end

	system("pause");
	return 0;
}