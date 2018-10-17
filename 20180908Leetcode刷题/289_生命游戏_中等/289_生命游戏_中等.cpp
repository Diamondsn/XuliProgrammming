#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
using namespace std;

//根据百度百科，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在1970年发明的细胞自动机。
//
//给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞具有一个初始状态 live（1）即为活细胞， 
//或 dead（0）即为死细胞。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
//
//如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
//根据当前状态，写一个函数来计算面板上细胞的下一个（一次更新后的）状态。
//下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
//
//示例:
//输入: 
//[
//  [0,1,0],
//  [0,0,1],
//  [1,1,1],
//  [0,0,0]
//]
//输出: 
//[
//  [0,0,0],
//  [1,0,1],
//  [0,1,1],
//  [0,1,0]
//]
//
//进阶:
//你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：
//你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
//本题中，我们使用二维数组来表示面板。原则上，面板是无限的，
//但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？

int getLiveNum(vector<vector<int>>&board, int i, int j){
	int count = 0;
	if (i - 1 >= 0)
	{
		if (board[i-1][j])
		count++;
		if (j - 1 >= 0 && board[i - 1][j - 1])
			count++;
		if (j + 1 <= board[0].size() - 1 && board[i - 1][j + 1])
			count++;
	}
	if (i + 1 <= board.size() - 1)
	{
		if (board[i+1][j])
		count++;
		if (j - 1 >= 0 && board[i + 1][j - 1])
			count++;
		if (j + 1 <= board[0].size() - 1 && board[i + 1][j + 1])
			count++;
	}
	if (j - 1 >= 0 && board[i][j - 1])
		count++;
	if (j + 1 <= board[0].size() - 1 && board[i][j + 1])
		count++;
	return count;
}

void gameOfLife(vector<vector<int>>& board) {
	vector<pair<int, int>>hash;//不能用map,使用map如果pair->first值相同则不会重复插入，其会自动根据键值去重
	for (int i = 0; i < board.size(); ++i){
		for (int j = 0; j < board[i].size(); ++j){
			int temp = getLiveNum(board, i, j);
			if (board[i][j] && (temp < 2 || temp > 3))
				hash.push_back(pair<int,int>(i, j));
			else if (!board[i][j] && temp == 3)
				hash.push_back(pair<int, int>(i, j));
		}
	}
	for (auto it = hash.begin(); it != hash.end(); ++it){
		board[it->first][it->second] = !board[it->first][it->second];
	}
}

int main() {
	//test1
	vector<vector<int>>board = { { 0, 1, 0 }, { 0, 0, 1 }, { 1, 1, 1 }, { 0, 0, 0 } };
	gameOfLife(board);
	for (vector<int>vec : board){
		for (int temp : vec){
			cout << temp << ",";
		}
		cout << endl;
	}

	//test2
	board = { { 1, 1 } };
	gameOfLife(board);
	for (vector<int>vec : board){
		for (int temp : vec){
			cout << temp << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}