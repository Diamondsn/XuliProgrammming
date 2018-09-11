#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//����һ������ A�� ���� A ��ת�þ���
//
//�����ת����ָ����������Խ��߷�ת���������������������������
//
//ʾ�� 1��
//���룺[[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//�����[[1, 4, 7], [2, 5, 8], [3, 6, 9]]
//
//ʾ�� 2��
//���룺[[1, 2, 3], [4, 5, 6]]
//�����[[1, 4], [2, 5], [3, 6]]
//
//��ʾ��
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