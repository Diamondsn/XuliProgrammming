#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;


//�����ַ���J ����ʯͷ�б�ʯ�����ͣ����ַ��� S������ӵ�е�ʯͷ�� S ��ÿ���ַ�������һ����ӵ�е�ʯͷ�����ͣ�����֪����ӵ�е�ʯͷ���ж����Ǳ�ʯ��
//
//J �е���ĸ���ظ���J �� S�е������ַ�������ĸ����ĸ���ִ�Сд�����"a"��"A"�ǲ�ͬ���͵�ʯͷ��
//
//ʾ�� 1:
//����: J = "aA", S = "aAAbbbb"
//��� : 3
//
//ʾ�� 2 :
//���� : J = "z", S = "ZZ"
//��� : 0
//
//ע�� :
//
//S �� J ��ຬ��50����ĸ��
//J �е��ַ����ظ���

int numJewelsInStones(string J, string S) {
	int count = 0;
	for (int i = 0; i < S.length(); ++i)
	{
		if (find(J.begin(),J.end(),S[i])!=J.end())
			count++;
	}
	return count;
}

int main() {
	//test
	int a = numJewelsInStones("aA", "aAAbbbb");
	int b= numJewelsInStones("z", "ZZ");

	cout << a << "," << b << endl;
	//test end
	system("pause");
	return 0;
}