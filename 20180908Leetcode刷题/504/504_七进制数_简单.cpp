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

//给定一个整数，将其转化为7进制，并以字符串形式输出。
//
//示例 1:
//
//输入: 100
//输出: "202"
//
//示例 2:
//输入: -7
//输出: "-10"
//注意: 输入范围是 [-1e7, 1e7] 。

string convertToBase7(int num) {
	string res;
	if (num == 0)
	{
		res = "0";
		return res;
	}
	stringstream ss;
	bool flag = num >= 0?true : false;
	num = abs(num);
	while (num)
	{
		ss.str("");
		ss.clear();
		ss << num % 7;
		res = ss.str() + res;
		num /= 7;
	}
	if (!flag)
		res = '-' + res;
	return res;
}

int main() {
	//test1
	string res = convertToBase7(100);

	string res1 = convertToBase7(-7);

	cout << res << endl << res1 <<endl;
	//test end
	system("pause");
	return 0;
}
