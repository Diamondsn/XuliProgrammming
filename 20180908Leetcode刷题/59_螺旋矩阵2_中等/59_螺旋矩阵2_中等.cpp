#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
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

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>>res;
	vector<int>temp(n);
	for (int i = 0; i < n; ++i)res.push_back(temp);
	vector < pair<int, int >>dir= { {0,1}, { 1,0}, { 0,-1 }, { -1,0 }};
	int curdir = 0,i=0,j=0,num=1;
	int left = 0, right = n - 1,top=0,bottom=n-1;
	while (num<=n*n) {
		if (curdir == 0 && j == right) {
			curdir = 1;
			top++;
		}
		else if (curdir == 1 && i == bottom) {
			curdir = 2;
			right--;
		}
		else if (curdir == 2 && j == left) {
			curdir = 3;
			bottom--;
		}
		else if (curdir == 3 && i == top) {
			curdir = 0;
			left++;
		}
		else {
			res[i][j] = num;
			i = i + dir[curdir].first;
			j = j + dir[curdir].second;
			num++;
		}
	}
	return res;
}

int main() {
	//test1
	vector<vector<int>>res = generateMatrix(5);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}