#include "stdafx.h"
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

//ʵ�ֺ��� ToLowerCase()���ú�������һ���ַ������� str���������ַ����еĴ�д��ĸת����Сд��ĸ��֮�󷵻��µ��ַ�����
//
//ʾ�� 1��
//���� : "Hello"
//��� : "hello"
//	
//ʾ�� 2��
//���� : "here"
//��� : "here"
//
//ʾ�� 3��
//���� : "LOVELY"
//��� : "lovely"

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