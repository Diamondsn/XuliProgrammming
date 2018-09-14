#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
#include<stdint.h>
using namespace std;
#pragma warning(disable:4996)

//int,float转字符串使用sstringstream

void main(){
	//test1
	int a=99;
	float b = 234.5566;
	string str;
	stringstream ss;
	ss << a << "---" << b;
	ss >> str;//或者 str=ss.str();
	//str = ss.str();
	//注意:默认保留3位小数
	cout << "使用stringstream将int，float转换为string" << str << endl;
	//test end
	system("pause");
}
