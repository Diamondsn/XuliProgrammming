#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//����һ��ֻ��0��1�Ķ�ά����, ���»�����������Ԫ�ض�Ϊ1��Ϊһ��(б�Ų���), ��һ���ж���ȡֵΪ1��������

void block(vector<vector<int>>& rect,int i, int j)
{
	rect[i][j] = 4;
	if (i < rect.size() - 1 && rect[i + 1][j] == 1) {
		block(rect,i + 1, j);
	}
	if (i > 0 && rect[i - 1][j] == 1) {
		block(rect, i - 1, j);
	}
	if (j < rect[i].size() - 1 && rect[i][j + 1] == 1) {
		block(rect, i, j + 1);
	}
	if (j > 0 && rect[i][j - 1] == 1) {
		block(rect, i, j - 1);
	}
}
int main() {
	//test1

	vector<vector<int>> rect;
	vector<int> temp = { 1,0,0,0 };
	rect.push_back(temp);
	temp = { 0,0,0,0 };
	rect.push_back(temp);
	temp = { 0,0,0,1 };
	rect.push_back(temp);
	temp = { 0,0,0,0 };
	rect.push_back(temp);

	int count=0;
	for (int i = 0; i < rect.size(); i++) {
		for (int j = 0; j < rect[i].size(); j++) {
			// ���ҵ�1ʱ,��ʼ���������ڵĿ�
			if (rect[i][j] == 1) {
				block(rect,i, j);
				count++;
			}
		}
	}
	cout<<count<<endl;


	//test end

	system("pause");
	return 0;
}