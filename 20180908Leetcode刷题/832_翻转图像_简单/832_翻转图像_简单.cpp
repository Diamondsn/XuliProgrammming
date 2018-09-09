#include "stdafx.h"
#include<string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

//����һ�������ƾ��� A����������ˮƽ��תͼ��Ȼ��תͼ�񲢷��ؽ����
//
//ˮƽ��תͼƬ���ǽ�ͼƬ��ÿһ�ж����з�ת�����������磬ˮƽ��ת[1, 1, 0] �Ľ����[0, 1, 1]��
//
//��תͼƬ����˼��ͼƬ�е� 0 ȫ���� 1 �滻�� 1 ȫ���� 0 �滻�����磬��ת[0, 1, 1] �Ľ����[1, 0, 0]��
//
//ʾ�� 1:
//
//����: [[1, 1, 0], [1, 0, 1], [0, 0, 0]]
//��� : [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
//���� : ���ȷ�תÿһ�� : [[0, 1, 1], [1, 0, 1], [0, 0, 0]]��
//Ȼ��תͼƬ : [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
//	
//ʾ�� 2 :
//
//���� : [[1, 1, 0, 0], [1, 0, 0, 1], [0, 1, 1, 1], [1, 0, 1, 0]]
//��� : [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]
//���� : ���ȷ�תÿһ�� : [[0, 0, 1, 1], [1, 0, 0, 1], [1, 1, 1, 0], [0, 1, 0, 1]]��
//Ȼ��תͼƬ : [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]
//	
//˵�� :
//
//1 <= A.length = A[0].length <= 20
//0 <= A[i][j] <= 1

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	for (int i = 0; i < A.size(); ++i)
	{
		reverse(A[i].begin(), A[i].end());
		for (int j = 0; j < A[i].size(); ++j)
		{
			A[i][j] = (int)(!A[i][j]);
		}
	}
	return A;
}

int main() {
	//test1
	vector<vector<int>>A;
	vector<int> temp = { 1,1,0 };
	A.push_back(temp);
	temp = { 1,0,1 };
	A.push_back(temp);
	temp = { 0,0,0 };
	A.push_back(temp);
	
	vector<vector<int>>B = flipAndInvertImage(A);
	
	for (int i = 0; i < B.size(); ++i)
	{
		for(int j = 0; j < B[i].size(); ++j)
		{
			if (j == 0)
				cout << B[i][j];
			else if (j == B[i].size() - 1)
				cout <<" ,"<< B[i][j] << endl;
			else
				cout << " ," << B[i][j];
		}
	}

	//test2
	A.clear();
	temp = { 1,1,0,0 };
	A.push_back(temp);
	temp = { 1,0,0,1 };
	A.push_back(temp);
	temp = { 0,1,1,1 };
	A.push_back(temp);
	temp = { 1,0,1,0 };
	A.push_back(temp);

	B.clear();
	B= flipAndInvertImage(A);

	for (int i = 0; i < B.size(); ++i)
	{
		for (int j = 0; j < B[i].size(); ++j)
		{
			if (j == 0)
				cout << B[i][j];
			else if (j == B[i].size() - 1)
				cout << " ," << B[i][j] << endl;
			else
				cout << " ," << B[i][j];
		}
	}
	//test end

	system("pause");
	return 0;
}