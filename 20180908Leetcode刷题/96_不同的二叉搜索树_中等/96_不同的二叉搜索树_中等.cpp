#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<stack>
#include<queue>
#include<functional>
using namespace std;

//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
//
//示例:
//输入: 3
//输出: 5
//解释:
//给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3

//此题采用动态规划,初解采用二维数组表示从i到j的数量，其实可以只采用一维数组，存储的是n个连续的数所组成的二叉搜索树的数量
//int numTrees(int n) {
//	if (n <= 0)return 0;
//	vector<int>vec(n+1, 0);
//	vector<vector<int>>dp(n+1,vec);
//	//初始化，dp[i][j]表示从i到j的二叉搜索树的种类数量,此处i<=j
//	for (int i = 1; i < n + 1; i++){
//		dp[i][i] = 1;
//	}
//	for (int k = 1; k <= n - 1; ++k){
//		for (int i = 1;i < n + 1&& k+i<n+1; i++){
//			int num = 0;
//			for (int t = i; t <= k + i; ++t){
//				if (t == i)
//					num += dp[t + 1][k + i];
//				else if (t == k + i)
//					num += dp[i][t-1];
//				else
//					num += dp[i][t - 1] * dp[t + 1][k + i];
//			}
//			dp[i][k + i] = num;
//		}
//	}
//	return dp[1][n];
//}

//使用一维数组进行动态规划
int numTrees(int n){
	if (n <= 0)return 0;
	vector<int>dp(n + 1, 0);
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i < n + 1; ++i){
		for (int j = 0; j < i; ++j){
			dp[i] = dp[i] + dp[j] * dp[i - 1 - j];
		}
	}
	return dp[n];
}

int main() {
	//test1
	int a = numTrees(3);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}