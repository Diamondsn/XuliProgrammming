#include "stdafx.h"
#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//��Ŀ����
//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
//����������Yes, �������No���������������������������ֶ�������ͬ��

bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.size() <= 0)
		return false;

	vector<int> left;
	vector<int> right;
	int root = sequence[sequence.size() - 1];
	int flag = -1;//��־�������ĵ�һ���ڵ�
	for (size_t i = 0; i < sequence.size() - 1; ++i)
	{
		if (flag==-1 && sequence[i] < root)
			left.push_back(sequence[i]);
		else {
			if (flag == -1)
				flag = i;

			if (i > flag)
			{
				if (sequence[i] >= root)
					right.push_back(sequence[i]);
				else
				{
					return false;
				}
			}
		}
	}
	if (left.size() > 0 && !VerifySquenceOfBST(left))
		return false;
	if (right.size() > 0 && !VerifySquenceOfBST(right))
		return false;

	return true;
}

int main() {
	//test 1
	vector<int> vec = { 1,4,3,7,9,8,5 };
	bool b=VerifySquenceOfBST(vec);
	cout <<b << endl;
	
	//test2
	vector<int>vec1 = { 7,4,6,5 };
	bool c = VerifySquenceOfBST(vec1);
	cout << c << endl;
	//test end
	system("pause");
	return 0;
}