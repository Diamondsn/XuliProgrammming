#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
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

//初解
//int kthSmallest(vector<vector<int>>& matrix, int k) {
//	priority_queue<int, vector<int>, greater<int>>q;//最小堆
//	for (vector<int>vec : matrix)
//		for (int i : vec)
//			q.push(i);
//	while (k>1){
//		q.pop();
//		k--;
//	}
//	return q.top();
//}

//使用最大堆的方法，priority_queue默认是最大堆
//int kthSmallest(vector<vector<int>>& matrix, int k){
//	priority_queue<int>q;
//	for (vector<int>vec : matrix){
//		for (int m : vec){
//			q.push(m);
//			if (q.size() > k)q.pop();
//		}
//	}
//	return q.top();
//}

//https://www.cnblogs.com/grandyang/p/5727892.html
//函数功能:从左下角开始遍历小于等于target的数目
int search_less_equal(vector<vector<int>>& matrix, int target){
	int n = matrix.size(), i = n - 1, j = 0, res = 0;
	while (i >= 0 && j < n){
		if (matrix[i][j] <= target){
			res += i + 1;
			++j;
		}
		else
			--i;
	}
	return res;
}
//使用二分法求解，mid值取matrix的第一个值(最小值)和最后一个值(最大值)的平均数
//统计mid在matrix中的排名
//统计方法1:轮询每行，统计比它小的数的个数
//统计方法2:利用matrix的潜在排序特性，从左下角开始
//方法1时间复杂度O(nlogn*logK)(K为matrix最大最小值之差)(每次查找每行时采用二分查找，查找一次O(nlogn))
//方法2时间复杂度O(nlogK)(查找一次O(n))
int kthSmallest(vector<vector<int>>& matrix, int k){
	int left = matrix[0][0], right = matrix.back().back();
	while (left < right){
		//int mid = (left + right) / 2;//容易超过int所能表示的最大范围，即容易溢出
		int mid = left + (right - left) / 2;
		int cnt = search_less_equal(matrix, mid);
		if (cnt < k)left = mid + 1;
		else right = mid;
	}
	return left;
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