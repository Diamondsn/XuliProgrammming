#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
#include<stdint.h>
using namespace std;

//字符串转int，float-使用atoi(),atof()
//注意：使用 atoi 的话，如果 string s 为空，返回值为0.则无法判断s是0还是空
void main(){
	//test1
	string str1("00801");
	int result1=atoi(str1.c_str());
	cout << "test1:"<<result1 << endl;

	//test2
	string str2("0.8333");
	float result2 = atof(str2.c_str());
	cout << "test2:" << result2 << endl;
	//test end
	system("pause");
}
