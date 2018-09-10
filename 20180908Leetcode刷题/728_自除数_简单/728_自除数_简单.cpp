#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//�Գ��� ��ָ���Ա���������ÿһλ������������
//���磬128 ��һ���Գ�������Ϊ 128 % 1 == 0��128 % 2 == 0��128 % 8 == 0��
//���У��Գ������������ 0 ��
//�����ϱ߽���±߽����֣����һ���б��б��Ԫ���Ǳ߽磨���߽磩�����е��Գ�����
//
//ʾ�� 1��
//���룺
//�ϱ߽�left = 1, �±߽�right = 22
//�����[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
//
//ע�⣺
//ÿ����������ı߽����� 1 <= left <= right <= 10000��

bool zhengchu(vector<int>& number, int i)
{
	for (int j = 0; j < number.size(); ++j)
	{
		if (number[j] == 0 || i%number[j] != 0)
			return false;
	}
	return true;
}

vector<int> selfDividingNumbers(int left, int right) {
	vector<int> vec;
	vector<int> number;
	for (int i = left; i <= right; ++i)
	{
		number.clear();
		int m = i;
		while (m > 0)
		{
			number.push_back(m % 10);
			m /= 10;
		}

		if (!zhengchu(number, i))
			continue;

		vec.push_back(i);
	}
	return vec;
}

int main() {
	//test
	vector<int> result = selfDividingNumbers(1,22);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}