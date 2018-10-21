#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<set>
using namespace std;

//题目描述
//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
//每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
//例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
//但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

bool fit(int curx, int cury, int threshold) {
	int count = 0;
	while (curx) {
		count += (curx % 10);
		curx /= 10;
	}
	while (cury) {
		count += (cury % 10);
		cury /= 10;
	}
	return count <= threshold;
}

void dfs(set<pair<int, int>>& myset,int curx,int cury,int &maxrow,int &maxcol,int &threshold) {
	if (curx<0 || cury<0 || curx>maxrow || cury>maxcol || !fit(curx, cury, threshold))return;
	myset.insert(pair<int, int>(curx, cury));
	if(myset.find(pair<int,int>(curx-1,cury))==myset.end())//加入判断，以减少不必要的计算
	dfs(myset, curx - 1, cury, maxrow, maxcol, threshold);
	if (myset.find(pair<int, int>(curx + 1, cury)) == myset.end())
	dfs(myset, curx + 1, cury, maxrow, maxcol, threshold);
	if (myset.find(pair<int, int>(curx, cury-1)) == myset.end())
	dfs(myset, curx, cury - 1, maxrow, maxcol, threshold);
	if (myset.find(pair<int, int>(curx, cury+1)) == myset.end())
	dfs(myset, curx, cury + 1, maxrow, maxcol, threshold);
}

int movingCount(int threshold, int rows, int cols)
{
	int maxrow = rows - 1, maxcol = cols - 1;
	set<pair<int, int>>myset;
	dfs(myset, 0, 0, maxrow, maxcol, threshold);
	return myset.size();
}

int main() {
	//test 1
	int a = movingCount(3,5,5);
	cout << a << endl;
	//test end
	system("pause");
	return 0;
}