#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
using namespace std;

//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。
//
//示例 1：
//输入: "babad"
//输出: "bab"
//注意: "aba"也是一个有效答案。
//
//示例 2：
//输入: "cbbd"
//输出: "bb"

string longestPalindrome(string s) {

}

int main() {
	//test1
	string a = longestPalindrome("babad");

	//test2
	string b = longestPalindrome("cbbd");
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}