#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;

//给定两个表示复数的字符串。
//返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。
//
//示例 1:
//输入: "1+1i", "1+1i"
//输出: "0+2i"
//解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
//
//示例 2:
//输入: "1+-1i", "1+-1i"
//输出: "0+-2i"
//解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。
//
//注意:
//输入字符串不包含额外的空格。
//输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。

string complexNumberMultiply(string a, string b) {
	int a1 = a[0] == '-' ? -stoi(a.substr(1, a.find('+') - 1)) : stoi(a.substr(0, a.find('+')));
	string aa = a.substr(a.find('+') + 1);
	int a2 = aa[0] == '-' ? -stoi(aa.substr(1,aa.find('i')-1)):stoi(aa.substr(0,a.find('i'))) ;
	
	int b1 = b[0] == '-' ? -stoi(b.substr(1, b.find('+') - 1)) : stoi(b.substr(0, b.find('+')));
	string bb = b.substr(b.find('+') + 1);
	int b2 = bb[0] == '-' ? -stoi(bb.substr(1, bb.find('i') - 1)) : stoi(bb.substr(0, b.find('i')));
	int c1 = a1*b1 - (a2*b2),c2 = a1*b2 + a2*b1;
	string res = to_string(c1) + "+" + to_string(c2) + "i";
	return res;
}

int main() {
	//test1
	string a = complexNumberMultiply("1+1i", "1+1i");

	//test2
	string b = complexNumberMultiply("1+-1i", "1+-1i");
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}