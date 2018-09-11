#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个矩阵 A， 返回 A 的转置矩阵。
//
//矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
//
//示例 1：
//输入：[[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//输出：[[1, 4, 7], [2, 5, 8], [3, 6, 9]]
//
//示例 2：
//输入：[[1, 2, 3], [4, 5, 6]]
//输出：[[1, 4], [2, 5], [3, 6]]
//
//提示：
//1.1 <= A.length <= 1000
//2.1 <= A[0].length <= 1000

vector<vector<int>> transpose(vector<vector<int>>& A) {
	vector<vector<int>> result;
	vector<int> temp;
	for (int i = 0; i < A[0].size(); ++i)
	{
		temp.clear();
		for (int j = 0; j < A.size(); ++j)
		{
			temp.push_back(A[j][i]);
		}
		result.push_back(temp);
	}
	return result;
}

void output(vector<vector<int>>& A)
{
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < A[i].size(); ++j)
		{
			cout << A[i][j] << " ,";
		}
		cout << endl;
	}
}
int main() {
	//test1
	vector<vector<int>> A;
	vector<int>temp = { 1,2,3 };
	A.push_back(temp);
	temp = { 4,5,6 };
	A.push_back(temp);
	temp = { 7,8,9 };
	A.push_back(temp);
	vector<vector<int>> result1 = transpose(A);
	
	vector<vector<int>> B;
	temp = { 1,2,3 };
	B.push_back(temp);
	temp = { 4,5,6 };
	B.push_back(temp);

	vector<vector<int>> result2 = transpose(B);

	output(result1);
	//[[1,4,7],[2,5,8],[3,6,9]]
	output(result2);
	//[[1,4],[2,5],[3,6]]
	//test end
	system("pause");
	return 0;
}