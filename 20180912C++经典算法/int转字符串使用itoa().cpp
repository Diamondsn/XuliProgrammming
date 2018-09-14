#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
#include<stdint.h>
using namespace std;
#pragma warning(disable:4996)

//int转字符串使用itoa()
//itoa函数:char* itoa(int value, char * str, int base ); 

void main(){
	//test1
	int a = 30;
	char str[10];
	itoa(a, str, 2);
	
	cout << "整数二进制转换为字符串" << str << endl;
	//test2
	itoa(a, str, 10);
	cout << "整数十进制转换为字符串:" << str << endl;

	//test3
	itoa(a, str, 16);
	cout << "整数十六进制转换为字符串:" << str << endl;
	//test end
	system("pause");
}
