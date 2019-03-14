#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
//
//一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
//
//示例 1:
//
//输入: S = "rabbbit", T = "rabbit"
//输出: 3
//解释:
//
//如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
//(上箭头符号 ^ 表示选取的字母)
//
//rabbbit
//^^^^ ^^
//rabbbit
//^^ ^^^^
//rabbbit
//^^^ ^^^
//示例 2:
//
//输入: S = "babgbag", T = "bag"
//输出: 5
//解释:
//
//如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
//(上箭头符号 ^ 表示选取的字母)
//
//babgbag
//^^ ^
//babgbag
//^^    ^
//babgbag
//^    ^^
//babgbag
//  ^  ^^
//babgbag
//    ^^^

//20190314 15:46使用回溯算法超出时间限制
//void huisu(vector<char>& vec, int& sum, string& s,int scur,string& t, int tcur)
//{
//	//if (tcur > t.size()+1)return;//一定要注意这里的return
//	if ((int)vec.size()==(int)t.size()){
//		sum++;
//	}
//	else{
//		for (int i = scur; i < s.size(); ++i){
//			if (s[i] == t[tcur]){
//				vec.push_back(s[i]);
//				huisu(vec, sum, s, i + 1, t, tcur + 1);
//				vec.pop_back();
//			}
//		}
//	}
//}
//int numDistinct(string s, string t) {
//	if (s.size() < t.size())return 0;
//	vector<char>vec;
//	int sum = 0;
//	huisu(vec, sum, s, 0, t, 0);
//	return sum;
//}


//20190314动态规划
//动规策略：
//dp[i][j]表示t的从0开始i长度和s的从0开始的j长度的匹配数目
//当t[i-1]==s[j-1]时 dp[i][j]=dp[i-1][j-1]+dp[i][j-1]
//当t[i-1]!=s[j-1]时 dp[i][j]=dp[i-1][j-1]
int numDistinct(string s, string t) {
	vector<vector<long>>dp(t.size() + 1,vector<long>(s.size()+1,0));
	for (int i = 0; i < dp[0].size(); ++i){
		dp[0][i] = 1;
	}
	for (int i = 1; i < dp.size(); ++i){
		for (int j = 1; j < dp[i].size(); ++j){
			if (t[i - 1] == s[j - 1]){
				dp[i][j] = dp[i - 1][j-1] + dp[i][j - 1];
			}
			else{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	return dp[t.size()][s.size()];
}

int main() {
	//test1
	int a = numDistinct("rabbbit", "rabbit");

	//test2
	int b = numDistinct("babgbag", "bag");
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}