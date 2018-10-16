#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
using namespace std;

//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。
//
//示例:
//输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。

//此初解超出时间限制,递归过程中有大量重复计算
int minPathSumCore(vector<vector<int>>&grid, int i, int j, int targeti, int targetj){
	if (i == targeti && targetj == j)return grid[i][j];
	int down= -1, right = -1,min;
	if (i + 1 <= targeti)
		down = minPathSumCore(grid, i + 1, j, targeti, targetj);
	if (j + 1 <= targetj)
		right = minPathSumCore(grid, i, j + 1, targeti, targetj);
	if (down == -1)
		min = right;
	else if (right == -1)
		min = down;
	else
		min = down < right ? down : right;
	return min + grid[i][j];
}

int minPathSum(vector<vector<int>>& grid) {
	int targeti = grid.size() - 1, targetj = grid[0].size() - 1;
	int res = minPathSumCore(grid, 0, 0, targeti, targetj);
	return res;
}

int main() {
	//test1
	vector<vector<int>>grid = { {1,3,1}, {1,5,1}, {4,2,1} };
	int res = minPathSum(grid);

	//test2
	grid = {{3, 8, 6, 0, 5, 9, 9, 6, 3, 4, 0, 5, 7, 3, 9, 3}, {0, 9, 2, 5, 5, 4, 9, 1, 4, 6, 9, 5, 6, 7, 3, 2}, {8, 2, 2, 3, 3, 3, 1, 6, 9, 1, 1, 6, 6, 2, 1, 9}, {1, 3, 6, 9, 9, 5, 0, 3, 4, 9, 1, 0, 9, 6, 2, 7}, {8, 6, 2, 2, 1, 3, 0, 0, 7, 2, 7, 5, 4, 8, 4, 8}, {4, 1, 9, 5, 8, 9, 9, 2, 0, 2, 5, 1, 8, 7, 0, 9}, {6, 2, 1, 7, 8, 1, 8, 5, 5, 7, 0, 2, 5, 7, 2, 1}, {8, 1, 7, 6, 2, 8, 1, 2, 2, 6, 4, 0, 5, 4, 1, 3}, {9, 2, 1, 7, 6, 1, 4, 3, 8, 6, 5, 5, 3, 9, 7, 3}, {0, 6, 0, 2, 4, 3, 7, 6, 1, 3, 8, 6, 9, 0, 0, 8}, {4, 3, 7, 2, 4, 3, 6, 4, 0, 3, 9, 5, 3, 6, 9, 3}, {2, 1, 8, 8, 4, 5, 6, 5, 8, 7, 3, 7, 7, 5, 8, 3}, {0, 7, 6, 6, 1, 2, 0, 3, 5, 0, 8, 0, 8, 7, 4, 3}, {0, 4, 3, 4, 9, 0, 1, 9, 7, 7, 8, 6, 4, 6, 9, 5}, {6, 5, 1, 9, 9, 2, 2, 7, 4, 2, 7, 2, 2, 3, 7, 2}, {7, 1, 9, 6, 1, 2, 7, 0, 9, 6, 6, 4, 4, 5, 1, 0}, {3, 4, 9, 2, 8, 3, 1, 2, 6, 9, 7, 0, 2, 4, 2, 0}, {5, 1, 8, 8, 4, 6, 8, 5, 2, 4, 1, 6, 2, 2, 9, 7}};
	int res2 = minPathSum(grid);
	cout << res << endl << res2 << endl;
	//test end

	system("pause");
	return 0;
}