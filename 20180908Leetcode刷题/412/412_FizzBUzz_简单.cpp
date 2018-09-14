#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdint.h>
using namespace std;

//写一个程序，输出从 1 到 n 数字的字符串表示。
//
//1. 如果 n 是3的倍数，输出“Fizz”；
//2. 如果 n 是5的倍数，输出“Buzz”；
//3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
//
//示例：
//n = 15,
//返回:
//[
//	"1",
//	"2",
//	"Fizz",
//	"4",
//	"Buzz",
//	"Fizz",
//	"7",
//	"8",
//	"Fizz",
//	"Buzz",
//	"11",
//	"Fizz",
//	"13",
//	"14",
//	"FizzBuzz"
//]

vector<string> fizzBuzz(int n) {
	vector<string> result;
	if (n == 0)
		return result;
	for (int i = 1; i <= n; ++i)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			result.push_back("FizzBuzz");
			continue;
		}
		if (i % 3 == 0)
		{
			result.push_back("Fizz");
			continue;
		}
		if (i % 5 == 0)
		{
			result.push_back("Buzz");
			continue;
		}

		result.push_back(to_string(i));
	}
	return result;
}

void main(){
	//test1
	vector<string> result = fizzBuzz(15);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	//test end
	system("pause");
}
