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
	int count = 1;
	vector<int>vec(n, 0);
	vector<vector<int>>res(n, vec);
	while (count <= n*n){

	}
}

int main() {
	//test1
	vector<vector<int>>res = generateMatrix(3);
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