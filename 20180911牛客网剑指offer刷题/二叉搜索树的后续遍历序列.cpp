#include "stdafx.h"
#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//题目描述
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes, 否则输出No。假设输入的数组的任意两个数字都互不相同。

bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.size() <= 0)
		return false;

	vector<int> left;
	vector<int> right;
	int root = sequence[sequence.size() - 1];
	int flag = -1;//标志右子树的第一个节点
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