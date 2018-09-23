#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
//
//示例 1：
//输入 : "Hello"
//输出 : "hello"
//	
//示例 2：
//输入 : "here"
//输出 : "here"
//
//示例 3：
//输入 : "LOVELY"
//输出 : "lovely"

string toLowerCase(string str) {
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = char(str[i] + 32);
    }
	return str;
}

int main() {
	//test
	string a = toLowerCase("Hello");
	string b = toLowerCase("here");
	string c = toLowerCase("LOVELY");

	cout << a << "," << b <<","<<c<< endl;
	//test end
	system("pause");
	return 0;
}