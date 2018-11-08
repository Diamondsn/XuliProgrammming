#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
using namespace std;

//给定两个字符串s1, s2，找到使两个字符串相等所需删除字符的ASCII值的最小和。
//
//示例 1:
//输入: s1 = "sea", s2 = "eat"
//输出: 231
//解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
//在 "eat" 中删除 "t" 并将 116 加入总和。
//结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
//
//示例 2:
//输入: s1 = "delete", s2 = "leet"
//输出: 403
//解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
//将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
//结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
//如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
//
//注意:
//0 < s1.length, s2.length <= 1000。
//所有字符串中的字符ASCII值在[97, 122]之间。

//https://blog.csdn.net/OneDeveloper/article/details/79945091
//思路:子问题是短一点的两字符串的解
//递归规律:当前dp[i][j]当s[1]==s2[j]时，dp[i][j]=dp[i-1][j-1]
//当不等时，是dp[i-1][j]+s1[i]和dp[i][j-1]+s2[j]的最小的值
//dp[i][j]表示s1.substr(0, i)和s2.substr(0,j)的解
int minimumDeleteSum(string s1, string s2) {
	vector<vector<int>>dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	//赋初值
	for (int i = 1; i <= s1.size(); ++i){
		dp[i][0] = dp[i - 1][0] + s1[i - 1];
	}
	for (int i = 1; i <=s2.size(); ++i){
		dp[0][i] = dp[0][i - 1] + s2[i - 1];
	}
	//迭代计算
	for (int i = 1; i <= s1.size(); ++i){
		for (int j = 1; j <=s2.size(); ++j){
			if (s1[i - 1] == s2[j - 1])dp[i][j] = dp[i - 1][j - 1];
			else{
				dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
			}
		}
	}
	return dp.back().back();
}

int main() {
	//test1
	string s1 = "sea", s2 = "eat";
	int ans1 = minimumDeleteSum(s1, s2);

	//test2
	s1 = "delete";
	s2 = "leet";
	int ans2 = minimumDeleteSum(s1, s2);
	cout << ans1 << endl << ans2 << endl;
	//test end
	system("pause");
	return 0;
}