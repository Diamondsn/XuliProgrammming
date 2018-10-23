#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
using namespace std;

//给定一个二维的甲板， 请计算其中有多少艘战舰。 战舰用 'X'表示，空位用 '.'表示。 你需要遵守以下规则：
//
//给你一个有效的甲板，仅由战舰或者空位组成。
//战舰只能水平或者垂直放置。换句话说,战舰只能由 1xN (1 行, N 列)组成，或者 Nx1 (N 行, 1 列)组成，其中N可以是任意大小。
//两艘战舰之间至少有一个水平或垂直的空位分隔 - 即没有相邻的战舰。
//
//示例 :
//X..X
//...X
//...X
//在上面的甲板中有2艘战舰。
//
//无效样例 :
//...X
//XXXX
//...X
//你不会收到这样的无效甲板 - 因为战舰之间至少会有一个空位将它们分开。
//
//进阶:
//你可以用一次扫描算法，只使用O(1)额外空间，并且不修改甲板的值来解决这个问题吗？

//思路:找一艘战舰的左上角的'X'，即为一艘战舰，其他'X'不计数
int countBattleships(vector<vector<char>>& board) {
	int count = 0, height = board.size(),width=board[0].size();
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width; ++j){
			if (board[i][j] == '.' || (i - 1 >= 0 && board[i - 1][j] == 'X') || (j - 1 >= 0 && board[i][j - 1] == 'X'))continue;
			count++;
		}
	}
	return count;
}

int main() {
	//test1
	vector<vector<char>>board = { { 'X', '.', '.', 'X' }, { '.', '.', '.', 'X' }, { '.', '.', '.', 'X' } };
	int a = countBattleships(board);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}