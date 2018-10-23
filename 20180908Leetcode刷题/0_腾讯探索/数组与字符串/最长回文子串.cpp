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

//https://www.cnblogs.com/mini-coconut/p/9074315.html
//本题极为经典

//1暴力求解 时间复杂度O(n^3)
//string longestPalindrome(string s) {
//	int max = 0;
//	string res;
//	for (int i = 0; i < s.size(); ++i){
//		for (int j = 1; j <= s.size() - i; ++j){
//			string m = s.substr(i, j);
//			string n = m;
//			reverse(n.begin(), n.end());
//			if (m.compare(n) == 0 && j>max)
//			{
//				max = j;
//				res = m;
//			}
//		}
//	}
//	return res;
//}

//2动态规划方法，也就是先计算dp[i][j]即从i到j的子串是不是回文串,复杂度O(n^2)
//string longestPalindrome(string s){
//	if (s.size() <= 1)return s;
//	int len = s.size();
//	string res;
//	vector<bool> temp(len,false);
//	vector<vector<bool>>flag(len,temp);
//	//初始化
//	for (int i = 0; i < len; ++i){
//		flag[i][i] = true;
//		if (i + 1 < len&&s[i] == s[i + 1])
//		{
//			flag[i][i + 1] = true;
//			res = s.substr(i, 2);
//		}
//	}
//	for (int length = 3; length <= len; ++length){
//		for (int i = 0; i + length <= len; ++i){
//			int zhongdian = i + length - 1;//终点索引
//			if (s[i] == s[zhongdian] && flag[i + 1][zhongdian - 1])
//			{
//				flag[i][zhongdian] = true;
//				res = s.substr(i, zhongdian - i + 1);
//			}
//		}
//	}
//	return res;
//}

//3Manacher法
string longestPalindrome(string s){

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