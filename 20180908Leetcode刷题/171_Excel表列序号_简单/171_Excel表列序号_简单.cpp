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

}

int main() {
	//test1
	string s = reverseWords("Let's take LeetCode contest");
	cout << s << endl;//s'teL ekat edoCteeL tsetnoc
					  //test end

	system("pause");
	return 0;
}