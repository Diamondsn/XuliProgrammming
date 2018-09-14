#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
#include<stdint.h>
using namespace std;

//字符串转int，float-使用stringstream

template<class Type>
Type stringToNum(string str)
{
	istringstream is(str);
	Type result;
	is >> result;
	return result;
}

void main(){
	//test1
	string str1("00801");
	int result1=stringToNum<int>(str1);
	cout << "test1:"<<result1 << endl;

	//test2
	string str2("0.8333");
	float result2 = stringToNum<float>(str2);
	cout << "test2:" << result2 << endl;
	//test end
	system("pause");
}
