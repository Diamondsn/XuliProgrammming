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

//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//
//注意：
//num1 和num2 的长度都小于 5100.
//num1 和num2 都只包含数字 0-9.
//num1 和num2 都不包含任何前导零。
//你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

string addStrings(string num1, string num2) {
	string res;
	int dangqian = 0,jinwei = 0;
	int n1, n2;
	stringstream ss;
	for (int i = 1; i<=(num1.size()>num2.size() ? num1.size() : num2.size()); ++i)//使用三元运算符时需要加括号
	{
		ss.str("");//清除内容
		ss.clear();//清除流状态
		ss<<(i<=num1.size()?num1[num1.size() - i]:'0');
		ss >> n1;
		ss.str("");
		ss.clear();
		ss << (i <= num2.size() ? num2[num2.size() - i] : '0');
		ss >> n2;
		dangqian = jinwei + n1 + n2;
		jinwei = dangqian / 10;
		dangqian %= 10;
		ss.str("");
		ss.clear();
		ss << dangqian;
		res = ss.str() + res;
	}
	if (jinwei != 0)
	{
		ss.str("");
		ss.clear();
		ss << jinwei;
		res = ss.str() + res;
	}
	return res;
}

int main() {
	//test1
	string a = addStrings("12356", "35");
	cout << a << endl;
	//test end
	system("pause");
	return 0;
}
