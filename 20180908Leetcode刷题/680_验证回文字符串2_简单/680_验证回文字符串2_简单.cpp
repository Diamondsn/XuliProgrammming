#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
//
//示例 1:
//输入: "aba"
//输出: True
//
//示例 2:
//输入: "abca"
//输出: True
//解释: 你可以删除c字符。
//
//注意:
//字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

bool validPalindrome(string s) {

}

int main() {
	//test1
	bool a = validPalindrome("aba");

	//test2
	bool b = validPalindrome("abca");

	cout << a << endl<<b<<endl;
	//test end

	system("pause");
	return 0;
}