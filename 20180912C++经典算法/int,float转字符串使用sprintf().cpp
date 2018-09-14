#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
#include<stdint.h>
using namespace std;
#pragma warning(disable:4996)

//int,float转字符串使用sprintf()
//sprintf函数:int sprintf ( char * str, const char * format, ... );
//参数说明:
//% 印出百分比符号，不转换。
//b 整数转成二进位。
//c 整数转成对应的 ASCII 字元。
//d 整数转成十进位。
//f 倍精确度数字转成浮点数。
//o 整数转成八进位。
//s 整数转成字串。
//x 整数转成小写十六进位。
//X 整数转成大写十六进位。

void main(){
	//test1
	int a = 30;
	char str[20];
	sprintf(str, "%o", a);
	cout << "整数八进制转换为字符串" << str << endl;

	//test2
	sprintf(str, "%d", a);
	cout << "整数十进制转换为字符串:" << str << endl;

	//test3
	sprintf(str, "%X", a);
	cout << "整数十六进制转换为字符串:" << str << endl;

	//test4
	sprintf(str, "%c", a);
	cout << "整数ACSII字元转换为字符串:" << str << endl;

	//test5
	float b = 25.567;
	sprintf(str, "%f", b);
	cout << "浮点数转换为字符串" << str << endl;

	//test6
	sprintf(str, "%.2f", b);
	cout << "浮点数保留两位小数转换为字符串" << str << endl;

	//test6
	sprintf(str, "%d-%.2f", a, b);
	cout << "同时转换两个数成为字符串" << str << endl;
	//test end
	system("pause");
}
