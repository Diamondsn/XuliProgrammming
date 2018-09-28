#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
using namespace std;

//在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
//
//每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。
//
//返回结果形体的总表面积。
//示例 1：
//输入：[[2]]
//输出：10
//
//示例 2：
//输入：[[1,2],[3,4]]
//输出：34
//
//示例 3：
//输入：[[1,0],[0,2]]
//输出：16
//
//示例 4：
//输入：[[1,1,1],[1,0,1],[1,1,1]]
//输出：32
//
//示例 5：
//输入：[[2,2,2],[2,1,2],[2,2,2]]
//输出：46
//
//提示：
//1 <= N <= 50
//0 <= grid[i][j] <= 50

int surfaceArea(vector<vector<int>>& grid) {
	int sum = 0;
	int xdel = 0;
	int ydel = 0;
	int zdel = 0;
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[i].size(); ++j)
		{
			sum += grid[i][j];
			zdel += grid[i][j]>1 ? grid[i][j] - 1 :0;
			if (j - 1>=0)
				xdel += min(grid[i][j - 1], grid[i][j]);
			if (j + 1 < grid[i].size())
				xdel += min(grid[i][j + 1], grid[i][j]);
			if (i - 1 >= 0)
				ydel += min(grid[i- 1][j], grid[i][j]);
			if (i + 1 < grid.size())
				ydel += min(grid[i + 1][j], grid[i][j]);
		}
	}
	return 6 * sum - xdel - ydel-zdel*2;
}

int main() {
	//test1
	vector<vector<int>>grid = { { 2 } };
	int a = surfaceArea(grid);

	//test2
	grid = { { 1, 2 }, { 3, 4 } };
	int b = surfaceArea(grid);

	//test3
	grid = { { 1, 0 }, { 0, 2 } };
	int c = surfaceArea(grid);
	//test4
	grid = { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
	int d = surfaceArea(grid);

	//test5
	grid = { { 2, 2, 2 }, { 2, 1, 2 }, {2,2,2} };
	int e = surfaceArea(grid);

	cout << a << endl << b << endl << c << endl<<d<<endl<<e<<endl;
	//test end
	system("pause");
	return 0;
}
