#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//编写一个函数，其作用是将输入的字符串反转过来。
//
//示例 1:
//输入: "hello"
//输出 : "olleh"
//
//示例 2 :
//输入 : "A man, a plan, a canal: Panama"
//输出 : "amanaP :lanac a ,nalp a ,nam A"

string reverseString(string s) {
	//1解
	/*reverse(s.begin(),s.end());
	return s;*/
	//2解
	string newstr = "";
	for (int i = s.size() - 1; i >= 0; --i)
	{
		newstr += s[i];
	}
	return newstr;
}

int main() {
	//test
	string str1 = reverseString("hello");
	string str2 = reverseString("A man, a plan, a canal: Panama");
	cout << str1 << endl << str2 << endl;
	//test end

	system("pause");
	return 0;
}