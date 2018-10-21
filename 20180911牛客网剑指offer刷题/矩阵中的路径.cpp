#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<set>
using namespace std;

//题目描述
//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
//如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
//例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
//但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

bool dfs(char* matrix, vector<bool>flag, int rows, int cols, int i, int j, char* str, int m) {
	if (matrix[cols*i + j] != str[m])
		return false;
	else{
		flag[cols*i + j] = true;
		if(m==int(strlen(str)-1))
		 return true;
		else {
			bool a = false, b = false, c = false, d = false;
			if (i - 1 >= 0 && !flag[cols*(i - 1) + j])
				a = dfs(matrix, flag, rows, cols, i - 1, j, str, m + 1);
			if (i + 1 < rows &&!flag[cols*(i + 1) + j])
				b = dfs(matrix, flag, rows, cols, i + 1, j, str, m + 1);
			if (j - 1 >= 0 && !flag[cols*i + j - 1])
				c = dfs(matrix, flag, rows, cols, i, j - 1, str, m + 1);
			if (j + 1 < cols && !flag[cols*i + j + 1])
				d = dfs(matrix, flag, rows, cols, i, j + 1, str, m + 1);
			if (a || b || c || d)return true;
			else 
				return false;
		}
	}
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	vector<bool>flag(rows*cols, false);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if(dfs(matrix, flag, rows, cols, i, j, str, 0))return true;
		}
	}
	return false;
}

int main() {
	//test 1
	char matrix[12] = {'a','b','c' ,'e',' s', 'f', 'c', 's', 'a', 'd' ,'e', 'e' };
	bool a = hasPath(matrix, 3, 4, "bcced");

	//test2
	bool b = hasPath(matrix, 3, 4, "abcb");
	cout << a << endl << b << endl;
	//test end
	system("pause");
	return 0;
}