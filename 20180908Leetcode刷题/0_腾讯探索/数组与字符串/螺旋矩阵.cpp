#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
//
//示例 1:
//输入:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//输出: [1,2,3,6,9,8,7,4,5]
//
//示例 2:
//输入:
//[
//  [1, 2, 3, 4],
//  [5, 6, 7, 8],
//  [9,10,11,12]
//]
//输出: [1,2,3,4,8,12,11,10,9,5,6,7]

vector<int> spiralOrder(vector<vector<int>>& matrix) {

}

int main() {
	//test1
	vector<vector<int>>matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	vector<int>res = spiralOrder(matrix);
	for (int t : res){
		cout << t << ",";
	}
	cout << endl << "test2" << endl;
	//test2
	matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	res = spiralOrder(matrix);
	for (int t: res){
		cout << t << ",";
	}
	//test end

	system("pause");
	return 0;
}