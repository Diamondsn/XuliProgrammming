#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;

//给定一个 n × n 的二维矩阵表示一个图像。
//将图像顺时针旋转 90 度。
//
//说明：
//你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
//
//示例 1:
//给定 matrix = 
//[
//  [1,2,3],
//  [4,5,6],
//  [7,8,9]
//],
//
//原地旋转输入矩阵，使其变为:
//[
//  [7,4,1],
//  [8,5,2],
//  [9,6,3]
//]
//
//示例 2:
//给定 matrix =
//[
//  [ 5, 1, 9,11],
//  [ 2, 4, 8,10],
//  [13, 3, 6, 7],
//  [15,14,12,16]
//], 
//原地旋转输入矩阵，使其变为:
//[
//  [15,13, 2, 5],
//  [14, 3, 4, 1],
//  [12, 6, 8, 9],
//  [16, 7,10,11]
//]

void rotate(vector<vector<int>>& matrix) {

}

int main() {
	//test1
	vector<vector<int>>matrix1 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	rotate(matrix1);
	for (vector<int>vec : matrix1){
		for (int temp : vec){
			cout << temp << ",";
		}
		cout << endl;
	}

	//test2
	cout << "test2" << endl;
	vector<vector<int>>matrix2 = { { 5, 1, 9, 11 }, { 2, 4, 8, 10 }, { 13, 3, 6, 7 }, { 15, 14, 12, 16 } };
	rotate(matrix2);
	for (vector<int>vec : matrix2){
		for (int temp : vec){
			cout << temp << ",";
		}
		cout << endl;
	}

	//test end

	system("pause");
	return 0;
}