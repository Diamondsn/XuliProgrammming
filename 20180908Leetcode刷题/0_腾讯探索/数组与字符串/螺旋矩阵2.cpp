#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
//
//示例:
//输入: 3
//输出:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//]

//以下两篇均极为简洁
//https://blog.csdn.net/wutingyehe/article/details/51249878
//https://www.cnblogs.com/ariel-dreamland/p/9149435.html
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>>temp;
	if (n <= 0)return temp;
	int count = 1,circle=0,i,j;
	vector<int>vec(n, 0);
	vector<vector<int>>res(n, vec);
	while (circle<(n+1)/2){
		for (i = circle, j = circle; j < n -1- circle; ++j){
			res[i][j] = count++;
		}
		for (i = circle, j = n - 1 - circle; i < n - 1 - circle; ++i){
			res[i][j] = count++;
		}
		for (i = n - 1 - circle, j = n - 1 - circle; j > circle; j--){
			res[i][j] = count++;
		}
		for (i = n - 1 - circle, j = circle; i > circle; i--){
			res[i][j] = count++;
		}
		circle++;
	}
	if (n & 1 == 1){
		res[n / 2][n / 2] = n*n;
	}
	return res;
}

//同理，但是不需区分是不是奇数
//vector<vector<int>> generateMatrix(int n) {
//	vector<vector<int>> res(n, vector<int>(n, 0));
//	int s = 0, e = 1, end = n * n;
//	while (e <= end) {
//		for (int i = s; i < n - s; ++i)
//			res[s][i] = e++;
//		for (int i = s + 1; i < n - s; ++i)
//			res[i][n - s - 1] = e++;
//		for (int i = n - s - 2; i >= s; --i)
//			res[n - s - 1][i] = e++;
//		for (int i = n - s - 2; i > s; --i)
//			res[i][s] = e++;
//		++s;
//	}
//	return res;
//}

int main() {
	//test1
	vector<vector<int>>res = generateMatrix(7);
	for (vector<int>vec : res){
		for (int t : vec){
			cout << t << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}