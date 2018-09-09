#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//对于一个只有0和1的二维矩阵, 上下或者左右相邻元素都为1则为一块(斜着不算), 求一共有多少取值为1的连续块

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
			// 当找到1时,开始处理其所在的块
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