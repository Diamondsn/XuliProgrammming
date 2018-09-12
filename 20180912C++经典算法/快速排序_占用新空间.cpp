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
int kuaisupaixucore(int arr[], int i, int j, int pivot)
{
	do {
		while (arr[++i] < pivot);
		while (arr[--j] > pivot);
		Swap(arr, i, j);
	} while (i < j);
	Swap(arr, i, j);
	return i;
}

//�˺���Ϊ���������ڲ����ú���
//�����ܡ�:��������������ϲ���Ϊһ������
int* MergeArr(int *arr1,int arr1num, int pivot,int* arr2,int arr2num)
{
	int* newarr = new int(arr1num+arr2num+1);
	for (size_t i = 0; i < arr1num + arr2num + 1; ++i)
	{
		if (i < arr1num)
			newarr[i] = arr1[i];
		else if (i == arr1num)
			newarr[i] = pivot;
		else if (i >arr1num)
		    newarr[i] = arr2[i - arr1num-1];
	}
	return newarr;
}
//�����������½���������������
void kuaisupaixu(int arr[], int i, int j,int newarr[])
{
	if (i >= j)
		return;

	int pivotindex = findpivotindex(i, j);
	int left = 0;
	int right = 0;
	for (int k = i; i <= j; ++i)
	{
		if (i == pivotindex)
			continue;

		if (arr[k] < arr[pivotindex])
			left++;

		if (arr[k] >= arr[pivotindex])
			right++;
	}
	int *leftarr = new int[left];
	int * rightarr = new int[right];

	left = 0;
	right = 0;
	for (int k = i; i <= j; ++i)
	{
		if (i == pivotindex)
			continue;

		if (arr[k] < arr[pivotindex])
		{
			leftarr[left++] = arr[k];
		}

		if (arr[k] > arr[pivotindex])
		{
			rightarr[right++] = arr[k];
		}
	}

	int * newleftarr = new int[left];
	int * newrightarr = new int[right];
	kuaisupaixu(leftarr, 0, left - 1, newleftarr);
	kuaisupaixu(rightarr, 0, right - 1, newrightarr);
	newarr=MergeArr(newleftarr,left, arr[pivotindex],newrightarr,right);
	
}

int main()
{
	int arr[10] = { 72,6,57,88,85,42,83,73,48,60 };
	int *newarr = new int[10];
	kuaisupaixu(arr, 0, 9, newarr);//�˴����Ϊ6��
	for (int i = 0; i < 10; ++i)
	{
		cout << newarr[i] << endl;
	}
	system("pause");
}