#include "stdafx.h"
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

//��������֮��ĺ�������ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��
//
//������������ x �� y����������֮��ĺ������롣
//
//ע�⣺
//0 =< x, y < 2^31.
//
//ʾ��:
//����: x = 1, y = 4
//��� : 2
//
//���� :
//1   (0 0 0 1)
//4   (0 1 0 0)
//��   ��
//
//����ļ�ͷָ���˶�Ӧ������λ��ͬ��λ�á�

int hammingDistance(int x, int y) {
	int z = x^y;
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		int m = z >> i & 1;
		if (m)
			count++;
	}
	return count;
}

int main() {
	//test
	int a = hammingDistance(1, 4);//2
	int b = hammingDistance(1577962638, 1727613287);//16
	cout << a <<","<<b<< endl;
	//test end

	system("pause");
	return 0;
}