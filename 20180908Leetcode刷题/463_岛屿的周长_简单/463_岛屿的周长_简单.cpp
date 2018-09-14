#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdint.h>
using namespace std;

//给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
//网格中的格子水平和垂直方向相连（对角线方向不相连）。
//整个网格被水完全包围，但其中恰好有一个岛屿
//（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
//岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。
//格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。
//计算这个岛屿的周长。
//
//示例 :
//[[0, 1, 0, 0],
//[1, 1, 1, 0],
//[0, 1, 0, 0],
//[1, 1, 0, 0]]
//
//答案 : 16
//解释 : 它的周长是下面图片中的 16 个黄色的边：

int islandPerimeter(vector<vector<int>>& grid) {
	int result = 0;
	int temp;
	for (int i = 0; i < grid.size(); ++i)
	{
		temp = 0;
		for (int j = 0; j < grid[i].size(); ++j)
		{
			temp = 0;
			if (grid[i][j] == 0)
				continue;

			if (j - 1 >= 0 && j - 1 < grid[i].size())
				temp += (grid[i][j - 1] == 1 ? 1 : 0);

			if (j + 1 >= 0 && j + 1 < grid[i].size())
				temp += (grid[i][j + 1] == 1 ? 1 : 0);

			if (i - 1 >= 0 && i - 1 < grid.size())
				temp += (grid[i - 1][j] == 1 ? 1 : 0);

			if (i + 1 >= 0 && i + 1 < grid.size())
				temp += (grid[i + 1][j] == 1 ? 1 : 0);

			result += (4 - temp);
		}
	}
	return result;
}

void main() {
	//test1
	vector<vector<int>>grid;
	vector<int>temp = { 0,1,0,0 };
	grid.push_back(temp);
	temp = { 1,1,1,0 };
	grid.push_back(temp);
	temp = { 0,1,0,0 };
	grid.push_back(temp);
	temp = { 1,1,0,0 };
	grid.push_back(temp);

	int b = islandPerimeter(grid);
	cout << b << endl;

	//test2
	grid.clear();
	temp = { 1 };
	grid.push_back(temp);
	int c = islandPerimeter(grid);
	cout << c << endl;
	//test end
	system("pause");
}
