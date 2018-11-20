#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<deque>
#include<functional>
using namespace std;

//给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。
//
//现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。
//
//给定一个对数集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
//
//示例 :
//输入: [[1,2], [2,3], [3,4]]
//输出: 2
//解释: 最长的数对链是 [1,2] -> [3,4]
//
//注意：
//给出数对的个数在 [1, 1000] 范围内。

//初次尝试，排序的依据都不正确，要根据数对中的第二个数进行排序
//bool bijiao(vector<int>& a, vector<int>& b){
//	return a.front() < b.front();
//}
//int findLongestChain(vector<vector<int>>& pairs) {
//	sort(pairs.begin(), pairs.end(), bijiao);
//	vector<int>dp(pairs.size());
//	dp[0] = 1;
//	int min = pairs[0][1];
//	for (int i = 1; i < pairs.size(); ++i){
//		if (pairs[i][0] > min){
//			dp[i] = dp[i - 1] + 1;
//		}
//		else{
//			dp[i] = dp[i - 1];
//		}
//	}
//	return dp.back();
//}

//https://blog.csdn.net/qq_26410101/article/details/80876280
//法一:贪心算法，将数对根据第二个数进行排序后，如果满足后一个数对的第一个数大于最后的end，则长度加一。
//bool bijiao(vector<int>a,vector<int>b){
//	return a[1] < b[1];
//}

//int findLongestChain(vector<vector<int>>& pairs) {
//	sort(pairs.begin(), pairs.end(), bijiao);
//	int res = 0,end=INT_MIN;
//	for (vector<int>pair:pairs){
//		if (pair[0] > end)
//		{
//			end = pair[1];
//			res++;
//		}
//	}
//	return res;
//}

//法二:动态规划，dp[i]是以第i个数对结尾的最长数对链的长度,返回dp中的最大值
//此题变化非常大，解法非常多，可细致深入思考动规条件
bool bijiao1(vector<int>a, vector<int>b){
	return a[0] < b[0];
}
int findLongestChain(vector<vector<int>>& pairs) {
	sort(pairs.begin(), pairs.end(), bijiao1);
	vector<int> dp(pairs.size(), 1);
	for (int i = 1; i < pairs.size(); ++i){
		for (int j = 0; j < i; j++){
			if (pairs[i][0] > pairs[j][1]){
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
	}
	return dp.back();
}

int main() {
	//test1
	vector<vector<int>>pairs = { { 1, 2 }, { 2, 3 }, { 3, 4 } };
	int a = findLongestChain(pairs);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}