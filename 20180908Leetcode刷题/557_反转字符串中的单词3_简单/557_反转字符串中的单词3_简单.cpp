#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
//
//ʾ�� 1:
//����: "Let's take LeetCode contest"
//��� : "s'teL ekat edoCteeL tsetnoc"
//ע�⣺���ַ����У�ÿ�������ɵ����ո�ָ��������ַ����в������κζ���Ŀո�

string reverseWords(string s) {
	vector<string> vec;
	string result="";
	while (s.size() > 0)
	{
		int n = s.find_first_of(" ");
		if (n == -1)
		{
			vec.push_back(s);
			s = "";
		}
		else {
			vec.push_back(s.substr(0, n));
			s = s.substr(n + 1);
		}
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		reverse(vec[i].begin(), vec[i].end());
		if (i == 0)
		{
			result += vec[i];
		}
		else
		{
			result = result + " " + vec[i];
		}
	}
	return result;
}

int main() {
	//test1
	string s = reverseWords("Let's take LeetCode contest");
	cout << s << endl;//s'teL ekat edoCteeL tsetnoc
	//test end

	system("pause");
	return 0;
}