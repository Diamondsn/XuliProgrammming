#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//��дһ���������������ǽ�������ַ�����ת������
//
//ʾ�� 1:
//����: "hello"
//��� : "olleh"
//
//ʾ�� 2 :
//���� : "A man, a plan, a canal: Panama"
//��� : "amanaP :lanac a ,nalp a ,nam A"

string reverseString(string s) {
	//1��
	/*reverse(s.begin(),s.end());
	return s;*/
	//2��
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