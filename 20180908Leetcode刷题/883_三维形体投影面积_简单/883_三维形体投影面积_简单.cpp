#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdint.h>
using namespace std;

//在 N * N 的网格中，我们放置了一些与 x，y，z 三轴对齐的 1 * 1 * 1 立方体。
//每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格(i, j) 上。
//现在，我们查看这些立方体在 xy、yz 和 zx 平面上的投影。
//投影就像影子，将三维形体映射到一个二维平面上。
//在这里，从顶部、前面和侧面看立方体时，我们会看到“影子”。
//返回所有三个投影的总面积。
//
//示例 1：
//输入：[[2]]
//输出：5
//
//示例 2：
//输入：[[1, 2], [3, 4]]
//输出：17
//解释：
//这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。
//
//示例 3：
//输入：[[1, 0], [0, 2]]
//输出：8
//
//示例 4：
//输入：[[1, 1, 1], [1, 0, 1], [1, 1, 1]]
//输出：14
//
//示例 5：
//输入：[[2, 2, 2], [2, 1, 2], [2, 2, 2]]
//输出：21
//
//提示：
//1 <= grid.length = grid[0].length <= 50
//0 <= grid[i][j] <= 50

int projectionArea(vector<vector<int>>& grid) {
	int xy =0;
	int xz = 0;
	int yz = 0;
	vector<int> vec;
	for (int i = 0; i < grid.size(); ++i)
	{
		int maxy = 0;
		for (int j = 0; j < grid[i].size(); ++j)
		{
			if (grid[i][j] != 0)
				xy++;

			if (maxy < grid[i][j])
				maxy = grid[i][j];

			if (i == 0)
				vec.push_back(grid[i][j]);
			else {
				if (vec[j] < grid[i][j])
					vec[j] = grid[i][j];
			}
		}
		xz += maxy;
	}
	for (int i = 0; i < vec.size(); ++i)
		yz += vec[i];
	return xy + xz + yz;
}

void main(){
	//test1
	vector<vector<int>>grid;
	vector<int>temp = { 1 };
	grid.push_back(temp);
	int a = projectionArea(grid);

	//test2
	grid.clear();
	temp = { 1,2 };
	grid.push_back(temp);
	temp = { 3,4 };
	grid.push_back(temp);
	int b = projectionArea(grid);

	//test3
	grid.clear();
	temp = { 1,0 };
	grid.push_back(temp);
	temp = { 0,2 };
	grid.push_back(temp);
	int c = projectionArea(grid);

	//test4
	grid.clear();
	temp = { 1,1,1 };
	grid.push_back(temp);
	temp = { 1,0,1 };
	grid.push_back(temp);
	temp = { 1,1,1 };
	grid.push_back(temp);
	int d = projectionArea(grid);

	//test5
	grid.clear();
	temp = { 2,2,2 };
	grid.push_back(temp);
	temp = { 2,1,2 };
	grid.push_back(temp);
	temp = { 2,2,2 };
	grid.push_back(temp);
	int e = projectionArea(grid);

	cout << a << endl << b << endl << c << endl << d << endl << e << endl;
	//test end
	system("pause");
}
