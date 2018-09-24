#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
//
//示例 1:
//输入: 1
//输出: true
//解释: 2^0 = 1
//
//示例 2:
//输入: 16
//输出: true
//解释: 2^4 = 16
//
//示例 3:
//输入: 218
//输出: false

bool isPowerOfTwo(int n){
	if (n <= 0)
		return false;

	return (n & n - 1) == 0 ;//是2的幂同时奇数位才能有1
}

int main() {
	//test1
	bool a = isPowerOfTwo(1);

	//test2
	bool b = isPowerOfTwo(16);

	//test3
	bool c = isPowerOfTwo(218);

	cout << a << endl << b << endl << c << endl;
	//test end

	system("pause");
	return 0;
}