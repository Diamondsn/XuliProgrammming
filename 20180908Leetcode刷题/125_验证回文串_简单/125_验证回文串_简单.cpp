#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//示例 1:
//输入: "A man, a plan, a canal: Panama"
//输出: true
//
//示例 2:
//输入: "race a car"
//输出: false

bool isSmae(char a, char b) {
	if (a == b)return true;
	if (((a >= 97 && a <= 122) || (a >= 65 && a <= 90))&& ((b >= 97 && b <= 122) || (b >= 65 && b <= 90)) &&abs((int)a - (int)b) == 32)return true;
	return false;
}

bool isCharAndNumber(char a) {
	if ((a >= 97 && a <= 122) || (a >= 65 && a <= 90) || (a >= 48 && a <= 57))return true;
	return false;
}

bool isPalindrome(string s) {
	if (s.size() < 1)return true;
	int i = 0, j = s.size() - 1;
	while (i <= j) {
		while (i < s.size() && !isCharAndNumber(s[i]))++i;
		while (j >= 0 && !isCharAndNumber(s[j]))--j;
		if (!isSmae(s[i], s[j]))return false;
		i++; j--;
	}
	return true;
}

int main() {
	//test1
	bool a = isPalindrome("A man, a plan, a canal: Panama");

	//test2
	bool b = isPalindrome("race a car");

	//test3
	bool c = isPalindrome("0P");
	cout << a << endl << b << endl << c << endl;;
	//test end

	system("pause");
	return 0;
}