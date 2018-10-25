#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//示例 1:
//输入: "Let's take LeetCode contest"
//输出: "s'teL ekat edoCteeL tsetnoc" 
//注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

string reverseWords(string s) {
	int cur = 0,i=0;
	string res;
	for (i = 0; i < s.size(); ++i){
		if (s[i] == ' '){
			for (int j = i-1; j>=cur;--j){
				res += s[j];
			}
			res += " ";
			cur = i + 1;
		}
	}
	for (int j = s.size()-1; j >= cur; --j){
		res += s[j];
	}
	return res;
}

int main() {
	//test1
	string a = reverseWords("Let's take LeetCode contest");
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}