#include "stdafx.h"
#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;


//此函数为快速排序内部调用函数
//【功能】:找到轴值索引
//此处寻找索引为两个数的中间值
int findpivotindex(int i, int j)
{
	return (i + j) / 2;
}

//此函数为快速排序内部调用函数
//【功能】:交换数组下标为i和j的元素
void Swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//此函数为快速排序内部调用函数
//【功能】:将小于轴值的放在数组左边，将大于轴值的放在数组右边,返回右边数组的第一个索引
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

//此函数为快速排序内部调用函数
//【功能】:将左右两个数组合并成为一个数组
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
//快速排序，在新建其他数组的情况下
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
	kuaisupaixu(arr, 0, 9, newarr);//此处结果为6，
	for (int i = 0; i < 10; ++i)
	{
		cout << newarr[i] << endl;
	}
	system("pause");
}