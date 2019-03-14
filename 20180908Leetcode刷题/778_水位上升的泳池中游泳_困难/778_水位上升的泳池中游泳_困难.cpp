#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j) 的平台高度。
//
//现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。
//
//你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N-1, N-1)？
//
//示例 1:
//
//输入: [[0,2],[1,3]]
//输出: 3
//解释:
//时间为0时，你位于坐标方格的位置为 (0, 0)。
//此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。
//
//等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
//示例2:
//
//输入: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
//输入: 16
//解释:
// 0  1  2  3  4
//24 23 22 21  5
//12 13 14 15 16
//11 17 18 19 20
//10  9  8  7  6
//
//最终的路线用加粗进行了标记。
//我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
//提示:
//
//2 <= N <= 50.
//grid[i][j] 位于区间 [0, ..., N*N - 1] 内。

void dfs(vector<vector<int>>& grid, vector<vector<bool>>flag,int& num, int sum,int x, int y){
	if (x + 1 == grid.size() && y + 1 == grid[0].size() && sum < num)
		num = sum;
	else
	{
		flag[x][y] = true;
		if (grid[x][y] > sum)
			sum = grid[x][y];
		if ()
	}
}

int swimInWater(vector<vector<int>>& grid) {
	int num = INT_MAX;
	vector<vector<bool>>flag(grid.size(), vector<bool>(grid[0].size(), false));
	dfs(grid, flag,num,0, 0, 0);
	return num;
}

int main() {
	//test1
	vector<vector<int>>vec1;
	vector<int>temp1 = { 0, 2 }, temp2 = { 1, 3 };
	vec1.push_back(temp1);
	vec1.push_back(temp2);
	int a = swimInWater(vec1);
	//test2
	vector<vector<int>>vec2;
	vector<int>t1 = { 0, 1, 2, 3, 4 },
		t2 = { 24, 23, 22, 21, 5 },
		t3 = { 12, 13, 14, 15, 16 },
		t4 = { 11, 17, 18, 19, 20 },
		t5 = { 10, 9, 8, 7, 6 };
	vec2 = { t1, t2, t3, t4, t5 };
	int b = swimInWater(vec2);
	cout << a << endl << b << endl;
	//test end
	system("pause");
	return 0;
}