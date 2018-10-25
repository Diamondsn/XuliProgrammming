#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//编写一个函数，其作用是将输入的字符串反转过来。
//
//示例 1:
//输入 : "hello"
//输出 : "olleh"
//
//示例 2 :
//输入 : "A man, a plan, a canal: Panama"
//输出 : "amanaP :lanac a ,nalp a ,nam A"

//直接使用stl中reverse函数;
//string reverseString(string s) {
//	reverse(s.begin(), s.end());
//	return s;
//}

string reverseString(string s){
	string res;
	for (int i = s.size() - 1; i >= 0; --i){
		res+=(s[i]);
	}
	return res;
}

int main() {
	//test1
	string a = reverseString("hello");

	//test2
	string b = reverseString("A man, a plan, a canal: Panama");
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}