#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，
//它们的乘积也表示为字符串形式。
//
//示例 1:
//输入: num1 = "2", num2 = "3"
//输出: "6"
//
//示例 2:
//输入: num1 = "123", num2 = "456"
//输出: "56088"
//
//说明：
//num1 和 num2 的长度小于110。
//num1 和 num2 只包含数字 0-9。
//num1 和 num2 均不以零开头，除非是数字 0 本身。
//不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

//以下解法不仅使用了字符串的加法，而且算法执行过程中多次执行加法
//影响效率
//string add(string num1, string num2){
//	if (num1.size() == 0)return num2;
//	else if (num2.size() == 0)return num1;
//	string res;
//	int jinwei=0;
//	for (int i = 1; i <= max(num1.size(), num2.size()); ++i){
//		int n1 = (int)num1.size() - i >= 0 ? num1[num1.size()-i] - '0' : 0;
//		int n2 = (int)num2.size() - i >= 0 ? num2[num2.size()-i] - '0' : 0;
//		int temp = n1 + n2+jinwei;
//		res = to_string(temp%10)+res;
//		jinwei = temp / 10;
//	}
//	return jinwei>0?to_string(jinwei)+res:res;
//}
//
//string multiply(string num1, string num2) {
//	if (num1.compare("0") == 0 || num2.compare("0") == 0)return"0";
//	string res,tempstr;
//	for (int i = 1; i <= num2.size(); ++i){
//		int jinwei = 0;
//		tempstr = "";
//		int n2 = num2[num2.size() - i] - '0';
//		for (int j = 1; j <= num1.size(); ++j){
//			int n1 = num1[num1.size() - j] - '0';
//			int temp = n1*n2+jinwei;
//			tempstr = to_string(temp % 10)+tempstr;
//			jinwei = temp / 10;
//		}
//		if (jinwei > 0)
//			tempstr = to_string(jinwei) + tempstr;
//		int ling = i - 1;
//		while (ling)
//		{
//			tempstr += "0";
//			ling--;
//		}
//		res =add(res,tempstr);
//	}
//	return res;
//}

//以下解法首先存储乘法所产生的值，后再统一进位
string multiply(string num1, string num2)
{
	int n1 = num1.size(), n2 = num2.size();
	int k = n1 + n2 - 2;
	vector<int>v(n1 + n2, 0);
	for (int i = 0; i < n1; ++i){
		for (int j = 0; j < n2; ++j){
			v[k - i - j] += (num1[i]-'0') * (num2[j]-'0');
		}
	}
	int jinwei = 0;
	for (int i = 0; i < n1 + n2; ++i){
		int temp = v[i] + jinwei;
		v[i] = temp % 10;
		jinwei = temp / 10;
	}
	int m = n1 + n2 - 1;
	while (v[m] == 0)m--;
	if (m < 0)return "0";
	string res;
	while (m >= 0){ res.push_back(v[m] + '0'); --m; }
	return res;
}

int main() {
	//test1
	string a = multiply("2", "3");

	//test2
	string b = multiply("123", "456");
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}