#include<iostream>
#include<vector>
using namespace std;

//给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。
//
//找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
//
//示例 1:
//[[0,0,1,0,0,0,0,1,0,0,0,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,1,1,0,1,0,0,0,0,0,0,0,0],
// [0,1,0,0,1,1,0,0,1,0,1,0,0],
// [0,1,0,0,1,1,0,0,1,1,1,0,0],
// [0,0,0,0,0,0,0,0,0,0,1,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,0,0,0,0,0,0,1,1,0,0,0,0]]
//对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
//
//示例 2:
//[[0,0,0,0,0,0,0,0]]
//对于上面这个给定的矩阵, 返回 0。
//
//注意: 给定的矩阵grid 的长度和宽度都不超过 50。

//标注查找过的矩阵，同时统计当前块岛屿面积
int AreaOfIsland(vector<vector<int>>& grid, int i, int j)
{
	int val = 0;
	if (grid[i][j] == 1)
	{
		val++;
		grid[i][j] = 2;
	}
	if (i - 1 >= 0 && grid[i - 1][j] == 1)
	{
		val++;
		grid[i - 1][j] = 2;
		val += AreaOfIsland(grid, i - 1, j);
	}
	if (i + 1 < grid.size() && grid[i + 1][j] == 1)
	{
		val++;
		grid[i + 1][j] = 2;
		val += AreaOfIsland(grid, i + 1, j);
	}
	if (j - 1 >= 0 && grid[i][j - 1] == 1)
	{
		val++;
		grid[i][j-1] = 2;
		val += AreaOfIsland(grid, i , j-1);
	}
	if (j + 1 <grid[0].size() && grid[i][j + 1] == 1)
	{
		val++;
		grid[i][j + 1] = 2;
		val += AreaOfIsland(grid, i, j + 1);
	}
	return val;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int max = 0;
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[i].size(); ++j)
		{
			if (grid[i][j] == 1)
			{
				int temp = AreaOfIsland(grid, i, j);
				if (temp > max)
					max = temp;
			}
		}
	}
	return max;
}

void main() {
	//test1
	vector<vector<int>>num1 = { {0,0,1,0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,0,0,0},
	{0,1,1,0,1,0,0,0,0,0,0,0,0 },
	{0,1,0,0,1,1,0,0,1,0,1,0,0},
	{0,1,0,0,1,1,0,0,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,1,1,0,0,0,0} };
	int len1 = maxAreaOfIsland(num1);
	cout << "test1结果" << len1 << endl;

	//test2
	vector<vector<int>>num2 = {{0, 0, 0, 0, 0, 0, 0, 0}};
	int len2 = maxAreaOfIsland(num2);
	cout << "test2结果" << len2 << endl;
	//test end
	system("pause");
}
