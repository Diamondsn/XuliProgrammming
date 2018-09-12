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

//快速排序，在不新建其他数组的情况下
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
	kuaisupaixu(arr, 0,9);//此处结果为6，
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << endl;
	}
	system("pause");
}