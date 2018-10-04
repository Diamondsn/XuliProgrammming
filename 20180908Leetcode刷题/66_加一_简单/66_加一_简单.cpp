#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//
//最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
//
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//
//示例 1:
//输入: [1,2,3]
//输出: [1,2,4]
//解释: 输入数组表示数字 123。
//
//示例 2:
//输入: [4,3,2,1]
//输出: [4,3,2,2]
//解释: 输入数组表示数字 4321。

vector<int> plusOne(vector<int>& digits) {
	if (digits[digits.size() - 1] != 9)
	{
		digits[digits.size() - 1]++;
		return digits;
	}
	int jinwei = 1;
	digits[digits.size() - 1] = 0;
	for (int i = 1; i < digits.size(); ++i) {
		int temp = digits[digits.size() - 1 - i] + jinwei;
		digits[digits.size() - 1 - i] = temp>=10?temp - 10:temp;
		jinwei = temp >= 10 ? 1 : 0;
		if (jinwei == 0)
			break;
	}
	if (jinwei != 0)
		digits.insert(digits.begin(), 1);
	return digits;
}

int main() {
	//test1
	vector<int>digits = { 1,2,3 };
	vector<int>res = plusOne(digits);
	for (int i = 0; i < res.size(); ++i)cout << res[i] <<endl;

	//test2
	cout <<endl<< "test2" << endl;
	digits = { 9,9,9 };
	res = plusOne(digits);
	for (int i = 0; i < res.size(); ++i)cout << res[i] << endl;
	//test end

	system("pause");
	return 0;
}