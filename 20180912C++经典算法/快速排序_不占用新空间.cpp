#include "stdafx.h"
#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;


//�˺���Ϊ���������ڲ����ú���
//�����ܡ�:�ҵ���ֵ����
//�˴�Ѱ������Ϊ���������м�ֵ
int findpivotindex(int i, int j)
{
	return (i + j) / 2;
}

//�˺���Ϊ���������ڲ����ú���
//�����ܡ�:���������±�Ϊi��j��Ԫ��
void Swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//�˺���Ϊ���������ڲ����ú���
//�����ܡ�:��С����ֵ�ķ���������ߣ���������ֵ�ķ��������ұ�,�����ұ�����ĵ�һ������
int kuaisupaixucore(int arr[], int i, int j,int pivot)
{
	do {
		while (arr[++i] < pivot);
		while (arr[--j] > pivot);
		Swap(arr, i, j);
	} while (i < j);
	Swap(arr,i, j);
	return i;
}

//���������ڲ��½���������������
void kuaisupaixu(int arr[], int i, int j)
{
	if (i >= j)
		return;

	int pivotindex = findpivotindex(i, j);
	Swap(arr, pivotindex, j);
	int k = kuaisupaixucore(arr, i - 1, j,arr[j]);
	Swap(arr, k, j);
	kuaisupaixu(arr, i, k-1);
	kuaisupaixu(arr, k + 1, j);
}

int main()
{
	int arr[10] = { 72,6,57,88,85,42,83,73,48,60 };
	kuaisupaixu(arr, 0,9);//�˴����Ϊ6��
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << endl;
	}
	system("pause");
}