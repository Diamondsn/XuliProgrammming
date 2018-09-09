#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//���ǰѷ����������Ե����� A ����ɽ����
//
//A.length >= 3
//���� 0 < i < A.length - 1 ʹ��A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1]
//����һ��ȷ��Ϊɽ�������飬�����κ����� A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1] �� i ��ֵ��
//
//ʾ�� 1��
//
//���룺[0, 1, 0]
//�����1
//
//ʾ�� 2��
//
//���룺[0, 2, 1, 0]
//�����1
//
//��ʾ��
//
//3 <= A.length <= 10000
//0 <= A[i] <= 10 ^ 6
//A �����϶����ɽ��

int peakIndexInMountainArray(vector<int>& A) {
	//���ֲ���
	if (A.size() == 1)
		return 0;

	/*int start = 0, end = A.size() - 1;
	int middle;
	
	while (end-start>1) {
		middle = (start + end) / 2;
		if (A[middle] > A[middle + 1])
			end= middle;
		else if (A[middle] < A[middle + 1])
			start = middle;
	}
	if (A[start] < A[end])
		return end;
	else
		return start;*/

	//˳�����
	for (int i = 0; i < A.size(); ++i)
	{
		if (i == 0 && A[i] > A[i + 1])
			return 0;

		if (i>0 && i < A.size() - 1 &&  A[i] > A[i + 1] && A[i] > A[i - 1])
			return i;

		if (i == A.size() - 1 && A[i - 1] < A[i])
			return i;
	}
}

int main() {
	//test1
	vector<int> A = { 0,1,0 };
	vector<int> B = { 0,2,1,0 };
	int a = peakIndexInMountainArray(A);//1
	int b = peakIndexInMountainArray(B);//1
	cout << a << " ," << b << endl;
	//test end

	system("pause");
	return 0;
}