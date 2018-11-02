#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//让我们一起来玩扫雷游戏！
//
//给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，
//'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，
//数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
//
//现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
//
//如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
//如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的方块都应该被递归地揭露。
//如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
//如果在此次点击中，若无更多方块可被揭露，则返回面板。
// 
//示例 1：
//输入: 
//[['E', 'E', 'E', 'E', 'E'],
// ['E', 'E', 'M', 'E', 'E'],
// ['E', 'E', 'E', 'E', 'E'],
// ['E', 'E', 'E', 'E', 'E']]
//
//Click : [3,0]
//
//输出: 
//
//[['B', '1', 'E', '1', 'B'],
// ['B', '1', 'M', '1', 'B'],
// ['B', '1', '1', '1', 'B'],
// ['B', 'B', 'B', 'B', 'B']]
//
//解释:
//https ://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/minesweeper_example_1.png
//
//示例 2：
//输入: 
//
//[['B', '1', 'E', '1', 'B'],
// ['B', '1', 'M', '1', 'B'],
// ['B', '1', '1', '1', 'B'],
// ['B', 'B', 'B', 'B', 'B']]
//
//Click : [1,2]
//
//输出: 
//
//[['B', '1', 'E', '1', 'B'],
// ['B', '1', 'X', '1', 'B'],
// ['B', '1', '1', '1', 'B'],
// ['B', 'B', 'B', 'B', 'B']]
//
//解释:
//https ://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/minesweeper_example_2.png
//
//注意：
//输入矩阵的宽和高的范围为 [1,50]。
//点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
//输入面板不会是游戏结束的状态（即有地雷已被挖出）。
//简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。

int getNum(vector<vector<char>>& board, int r, int c){
	int maxr = board.size() - 1;
	int maxc = board[0].size() - 1;
	int num = 0;
	if (c - 1 >= 0 && board[r][c - 1] == 'M')num++;
	if (c + 1 <= maxc&&board[r][c + 1] == 'M')num++;
	if (r - 1 >= 0){
		if (board[r - 1][c] == 'M')num++;
		if (c - 1 >= 0 && board[r - 1][c - 1] == 'M')num++;
		if (c + 1 <= maxc && board[r - 1][c + 1] == 'M')num++;
	}
	if (r + 1 <= maxr){
		if (board[r + 1][c] == 'M')num++;
		if (c - 1 >= 0 && board[r + 1][c - 1] == 'M')num++;
		if (c + 1 <= maxc&&board[r + 1][c + 1] == 'M')num++;
	}
	return num;
}

void updateBoard(vector<vector<char>>& board, vector<int>& click,vector<vector<bool>>&flag){
	if (click[0] < 0 || click[0] >= (int)board.size() || click[1] < 0 || click[1] >= (int)board[0].size() || flag[click[0]][click[1]] == true)return;
	flag[click[0]][click[1]] = true;
	if (board[click[0]][click[1]] != 'M'){
		int num = getNum(board, click[0], click[1]);
		if (num > 0){
			board[click[0]][click[1]] = '0' + num;
		}
		else{
			board[click[0]][click[1]] = 'B';
			vector<vector<int>>vec = { { click[0], click[1] - 1 }, { click[0], click[1] + 1 }, { click[0] - 1, click[1] - 1 }, { click[0] - 1, click[1] }, { click[0] - 1, click[1] + 1 }, { click[0] + 1, click[1] - 1 }, { click[0] + 1, click[1] }, { click[0] + 1, click[1] + 1 } };
			for (vector<int>v : vec)
				updateBoard(board, v, flag);
		}
	}
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
	if (click[0] < 0 || click[0] >= (int)board.size() || click[1] < 0 || click[1] >= (int)board[0].size())return board;
	if (board[click[0]][click[1]] == 'M'){
		board[click[0]][click[1]] = 'X';
	}
	else{
		int num = getNum(board, click[0], click[1]);
		if (num > 0){
			board[click[0]][click[1]] = '0' + num;
		}
		else{
			board[click[0]][click[1]] = 'B';
			vector<vector<bool>>flag(board.size(), vector<bool>(board[0].size(), false));
			flag[click[0]][click[1]] = true;
			vector<vector<int>>vec = { { click[0], click[1] - 1 }, { click[0], click[1] + 1 }, { click[0] - 1, click[1] - 1 }, { click[0] - 1, click[1] }, { click[0] - 1, click[1] + 1 }, { click[0] + 1, click[1] - 1 }, { click[0] + 1, click[1] }, { click[0] + 1, click[1] + 1 } };
			for (int i = 0;i<vec.size();++i)
				updateBoard(board, vec[i],flag);
		}
	}
	return board;
}

int main() {
	//test1
	vector<vector<char>> board = { { 'E', 'E', 'E', 'E', 'E' },
	{ 'E', 'E', 'M', 'E', 'E' },
	{ 'E', 'E', 'E', 'E', 'E' },
	{ 'E', 'E', 'E', 'E', 'E' } };
	vector<int>click = { 3, 0 };
	vector<vector<char>>res = updateBoard(board, click);
	for (vector<char>vec : board){
		for (char c : vec)
			cout << c << ",";
		cout << endl;
	}

	//test2
	board = { { 'B', '1', 'E', '1', 'B' },
	{ 'B', '1', 'M', '1', 'B' },
	{ 'B', '1', '1', '1', 'B' },
	{ 'B', 'B', 'B', 'B', 'B' } };
	click = { 1, 2 };
	res = updateBoard(board, click);
	cout << "test2" << endl;
	for (vector<char>vec : res){
		for (char c : vec)
			cout << c <<",";
		cout << endl;
	}
	//test end
	system("pause");
	return 0;
}