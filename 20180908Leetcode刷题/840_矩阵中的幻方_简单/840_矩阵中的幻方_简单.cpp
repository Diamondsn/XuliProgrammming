#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdint.h>
#include<map>
using namespace std;

//3 x 3 的幻方是一个填充有从 1 到 9 的不同数字的 3 x 3 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。
//
//给定一个由整数组成的 N × N 矩阵，其中有多少个 3 × 3 的 “幻方” 子矩阵？（每个子矩阵都是连续的）。
//
//示例 1:
//输入: [[4,3,8,4],
//      [9,5,1,9],
//      [2,7,6,2]]
//输出: 1
//解释: 
//下面的子矩阵是一个 3 x 3 的幻方：
//438
//951
//276
//
//而这一个不是：
//384
//519
//762
//
//总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。
//
//提示:
//1 <= grid.length = grid[0].length <= 10
//0 <= grid[i][j] <= 15

bool isMagicSquare(vector<vector<int>>& grid, int i, int j) {
	vector<int>vec(9);
	for (int m = i - 1; m <= i + 1; ++m) {
		for (int n = j - 1; n <= j + 1; ++n) {
			if (grid[m][n] == 0 || grid[m][n] >= 10)
				return false;

			vec[grid[m][n] - 1]++;
			if (vec[grid[m][n] - 1] > 1)return false;
		}
	}
	if (grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][ j - 1] != 15)return false;
	if (grid[i - 1][j] + grid[i][j] + grid[i + 1][j] != 15)return false;
	if (grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1] != 15)return false;
	if (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] != 15)return false;
	if (grid[i][j - 1] + grid[i][j] + grid[i][j + 1] != 15)return false;
	if (grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1] != 15)return false;
	if (grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1] != 15)return false;
	if (grid[i + 1][j - 1] + grid[i][j] + grid[i - 1][j + 1] != 15)return false;
	return true;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
	int sum = 0;
	for (int i = 1; i < grid.size() - 1; ++i) {
		for (int j = 1; j < grid[i].size() - 1; ++j) {
			if (isMagicSquare(grid, i, j))
				sum++;
		}
	}
	return sum;
}

int main() {
	//test1
	vector<vector<int>>grid = { {4,3,8,4},{9,5,1,9},{2,7,6,2} };
	int a = numMagicSquaresInside(grid);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}