#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

//给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
//请注意，它是排序后的第k小元素，而不是第k个元素。
//
//示例:
//matrix = [
//   [ 1,  5,  9],
//   [10, 11, 13],
//   [12, 13, 15]
//],
//k = 8,
//
//返回 13。
//
//说明: 
//你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。

//此题使用二分查找，需注意其中索引的变化策略
int kthSmallest(vector<vector<int>>& matrix, int k) {
	priority_queue<int, vector<int>, less<int>>q;
}

int main() {
	//test1
	vector<vector<int>>matrix = { {1,5,9}, {10,11,13}, {12,13,15} };
	int a = kthSmallest(matrix, 8);
	cout << a << endl;
	//test end
	system("pause");
	return 0;
}