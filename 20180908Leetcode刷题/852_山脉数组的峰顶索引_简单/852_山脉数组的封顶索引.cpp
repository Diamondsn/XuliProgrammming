#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//我们把符合下列属性的数组 A 称作山脉：
//
//A.length >= 3
//存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1]
//给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1] 的 i 的值。
//
//示例 1：
//
//输入：[0, 1, 0]
//输出：1
//
//示例 2：
//
//输入：[0, 2, 1, 0]
//输出：1
//
//提示：
//
//3 <= A.length <= 10000
//0 <= A[i] <= 10 ^ 6
//A 是如上定义的山脉

int peakIndexInMountainArray(vector<int>& A) {
	//二分查找
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

	//顺序查找
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