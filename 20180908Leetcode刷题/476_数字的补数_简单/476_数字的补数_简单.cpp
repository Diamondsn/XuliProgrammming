#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//����һ����������������Ĳ����������ǶԸ����Ķ����Ʊ�ʾȡ����
//
//ע�� :
//
//������������֤��32λ�����������ķ�Χ�ڡ�
//����Լٶ���������������ǰ����λ��
//ʾ�� 1 :
//���� : 5
//��� : 2
//���� : 5�Ķ����Ʊ�ʾΪ101��û��ǰ����λ�����䲹��Ϊ010����������Ҫ���2��
//
//ʾ�� 2 :
//���� : 1
//��� : 0
//���� : 1�Ķ����Ʊ�ʾΪ1��û��ǰ����λ�����䲹��Ϊ0����������Ҫ���0��

int findComplement(int num) {
	int flag = 0;
	int result = 0;
	for (int i = 31; i >= 0; --i)
	{
		int a = num >> i & 1;
		if (a == 1)
		{
			flag = 1;
		}
		if (flag && a == 0)
		{
			//���2��n�η�
			//1�⣬ʹ��pow����
			//result += pow(2,i);
			//2��,ʹ������
			result += (1 << i);
		}
	}
	return result;
}

int main() {
	//test
	int a = findComplement(5);//2
	int b = findComplement(1);//0
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}