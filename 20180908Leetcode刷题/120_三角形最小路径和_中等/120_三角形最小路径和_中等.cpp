#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<map>
#include<list>
using namespace std;

//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
//
//例如，给定三角形：
//
//[
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
//自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
//
//说明：
//如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

//cur表示计算的路径和，ceng指当前三角形第几行，索引指上层取的第几个值
//回溯算法超时
//void dfs(int & res, vector<vector<int>>& triangle,int cur, int ceng,int suoyin){
//	if (ceng == triangle.size())
//	{
//		if (cur<res)
//		res = cur;
//	}
//	else{
//		dfs(res, triangle, cur + triangle[ceng][suoyin], ceng + 1, suoyin);
//		dfs(res, triangle, cur + triangle[ceng][suoyin + 1], ceng + 1, suoyin + 1);
//	}
//}
//
//int minimumTotal(vector<vector<int>>& triangle) {
//	int height = triangle.size();
//	if (height < 1)return 0;
//	int res =INT_MAX,cur=triangle[0][0],suoyin=0;
//	dfs(res, triangle,cur, 1,suoyin);
//	return res;
//}

//动态规划,也可直接在triangle执行动态规划
int minimumTotal(vector<vector<int>>& triangle){
	if (triangle.size()<1)return 0;
	vector<int>dp;//存储上层结果
	dp.push_back(triangle[0][0]);
	for (int i = 1; i < triangle.size(); ++i){
		for (int j = 0; j <= i; j++){
			if (j == 0)dp.push_back(dp[j] + triangle[i][j]);
			else if (j == i)dp.push_back(dp[j - 1] + triangle[i][j]);
			else dp.push_back(triangle[i][j] + min(dp[j - 1], dp[j]));
		}
		int m = i;
		while (m){
			dp.erase(dp.begin());
			m--;
		}
	}
	int res = dp[0];
	for (int i = 1; i < dp.size(); ++i){
		if (dp[i] < res)
			res = dp[i];
	}
	return res;
}

int main() {
	//test1
	vector<vector<int>>triangle = { { 2 }, { 3, 4 }, { 6, 5, 7 }, {4,1,8,3} };
	int a = minimumTotal(triangle);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}