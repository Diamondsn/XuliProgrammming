#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个正整数，返回它在 Excel 表中相对应的列名称。
//
//例如，
//    1 -> A
//    2 -> B
//    3 -> C
//    ...
//    26 -> Z
//    27 -> AA
//    28 -> AB 
//    ...
//示例 1:
//
//输入: 1
//输出: "A"
//示例 2:
//
//输入: 28
//输出: "AB"
//示例 3:
//
//输入: 701
//输出: "ZY"

string convertToTitle(int n) {
	if (n <= 0)return "";
	string res;
	vector<char>dic = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	while (n > 0) {
		int suoyin = (n-1) % 26;//c此题的映射关系26进制不能变，但是数不是从0开始记得，而是1
		n =(n-1)/ 26;
		res = dic[suoyin]+res;
	}
	return res;
}

void main() {
	//test1
	string a=convertToTitle(1);

	//test2
	string b = convertToTitle(28);

	//test3
	string c = convertToTitle(701);
	cout << a << endl << b << endl << c << endl;
	//test end
	system("pause");
}