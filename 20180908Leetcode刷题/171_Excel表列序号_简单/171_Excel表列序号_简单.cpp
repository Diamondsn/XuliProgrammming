#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//����һ��Excel����е������ƣ���������Ӧ������š�
//
//���磬
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//ʾ�� 1:
//����: "A"
//��� : 1
//
//ʾ�� 2 :
//���� : "AB"
//��� : 28
//
//ʾ�� 3 :
//���� : "ZY"
//��� : 701

int titleToNumber(string s) {
	int result=0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 65 && s[i] <= 90)//A-Z
			result +=(s[i]-64)* pow(26,s.size()-1-i);
		else if (s[i] >= 97 && s[i] <= 122)
			result += (s[i] - 97)*pow(26,s.size()-1-i);
	}
	return result;
}

int main() {
	//test1
	int a = titleToNumber("A");
	int b= titleToNumber("AB");
	int c= titleToNumber("ZY");
	cout << a << endl<< b<<endl << c<< endl;//1,28,701
	//test end

	system("pause");
	return 0;
}