#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;

//给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
//
//示例 1:
//输入: 
//[
//  [1,1,1],
//  [1,0,1],
//  [1,1,1]
//]
//输出: 
//[
//  [1,0,1],
//  [0,0,0],
//  [1,0,1]
//]
//
//示例 2:
//输入: 
//[
//  [0,1,2,0],
//  [3,4,5,2],
//  [1,3,1,5]
//]
//输出: 
//[
//  [0,0,0,0],
//  [0,4,5,0],
//  [0,3,1,0]
//]
//
//进阶:
//一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
//你能想出一个常数空间的解决方案吗？

//O(mn)空间是记录下所有0所在的位置坐标
//O(m+n)空间记录下所有0所在的行号和列号
//使用常数空间代表不能另行记录其他信息，必须边变化矩阵中的数字同时在数字当中隐藏记录所在信息
//思路：在首行首列记录是否需要置0
void setZeroes(vector<vector<int>>& matrix) {
	bool row = false, col = false;
	for (int i = 0; i < matrix[0].size(); ++i)
	{
		if (matrix[0][i] == 0){
			row = true;
			break;
		}
	}
	for (int i = 0; i < matrix.size(); ++i)
	{
		if (matrix[i][0] == 0){
			col = true;
			break;
		}
	}
	for (int i = 1; i < matrix.size(); ++i){
		for (int j = 1; j < matrix[0].size(); ++j){
			if (matrix[i][j] == 0){
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}
	//开始进行首行首列以外的置零操作
	for (int i = 1; i < matrix[0].size(); ++i)//每列置0
	{
		if (matrix[0][i] == 0){
			for (int j = 1; j < matrix.size(); ++j)
				matrix[j][i] = 0;
		}
	}
	for (int i = 1; i < matrix.size(); ++i){
		if (matrix[i][0] == 0){
			for (int j = 1; j < matrix[0].size(); ++j){
				matrix[i][j] = 0;
			}
		}
	}
	if (row){
		for (int i = 0; i < matrix[0].size(); ++i)
		{
			matrix[0][i] = 0;
		}
	}
	if (col){
		for (int i = 0; i < matrix.size(); ++i){
			matrix[i][0] = 0;
		}
	}
}

int main() {
	//test1
	vector<vector<int>>matrix = { { 1, 1, 1 },
	{ 1, 0, 1 },
	{ 1, 1, 1 } };
	setZeroes(matrix);
	for (vector<int>vec : matrix)
	{
		for (int i : vec)
			cout << i << ",";
		cout << endl;
	}

	//test2
	matrix = { { 0, 1, 2, 0 },
	{ 3, 4, 5, 2 },
	{ 1, 3, 1, 5 } };
	setZeroes(matrix);
	for (vector<int>vec : matrix)
	{
		for (int i : vec)
			cout << i << ",";
		cout << endl;
	}
	
	//test3
	matrix = { { 5 }, { 2 }, { 0 }, { 3 }, { 6 }, { 7 }, { 2 } };
	setZeroes(matrix);
	for (vector<int>vec : matrix)
	{
		for (int i : vec)
			cout << i << ",";
		cout << endl;
	}
	//test end
	system("pause");
	return 0;
}