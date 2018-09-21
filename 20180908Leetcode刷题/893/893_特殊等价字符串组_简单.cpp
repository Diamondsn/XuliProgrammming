#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
using namespace std;

//你将得到一个字符串数组 A。
//如果经过任意次数的移动，S == T，那么两个字符串 S 和 T 是特殊等价的。
//一次移动包括选择两个索引 i 和 j，且 i％2 == j％2，并且交换 S[j] 和 S [i]。
//现在规定，A 中的特殊等价字符串组是 A 的非空子集 S，
//这样不在 S 中的任何字符串与 S 中的任何字符串都不是特殊等价的。
//
//返回 A 中特殊等价字符串组的数量。
//
//示例 1：
//输入：["a","b","c","a","c","c"]
//输出：3
//解释：3 组 ["a","a"]，["b"]，["c","c","c"]
//
//示例 2：
//输入：["aa","bb","ab","ba"]
//输出：4
//解释：4 组 ["aa"]，["bb"]，["ab"]，["ba"]
//
//示例 3：
//输入：["abc","acb","bac","bca","cab","cba"]
//输出：3
//解释：3 组 ["abc","cba"]，["acb","bca"]，["bac","cab"]
//
//示例 4：
//输入：["abcd","cdab","adcb","cbad"]
//输出：1
//解释：1 组 ["abcd","cdab","adcb","cbad"]
// 
//提示：
//1 <= A.length <= 1000
//1 <= A[i].length <= 20
//所有 A[i] 都具有相同的长度。
//所有 A[i] 都只由小写字母组成。

//判断两个字符串是不是特殊等价字符串
bool teshu(string str1,string str2)
{
	if (str1.size() != str2.size())
		return false;

	int jiarr[26];
	int ouarr[26];
	memset(jiarr, 0, sizeof(jiarr));
	memset(ouarr, 0, sizeof(ouarr));
	for (int i = 0; i < str1.size(); ++i)
	{
		if (i % 2 == 0)//偶数
		{
			ouarr[str1[i]-97]++;
			ouarr[str2[i] - 97]--;
		}
		else//奇数
		{
			jiarr[str1[i] - 97]++;
			jiarr[str2[i] - 97]--;
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		if (jiarr[i] != 0 || ouarr[i] != 0)
			return false;
	}
	return true;
}

int numSpecialEquivGroups(vector<string>& A) {
	int flag = false;
	map<string, int>hash;
	for (int i = 0; i < A.size(); ++i)
	{
		flag = false;
		for (auto it = hash.begin();!flag && it != hash.end(); ++it)
		{
			if (teshu(it->first,A[i]))
			{
				it->second++;
				flag = true;
			}
		}
		if (!flag)
		{
			hash.insert(pair<string, int>(A[i], 1));
		}
	}
	return hash.size();
}

int main() {
	//test1
	vector<string>num = { "a", "b", "c", "a", "c", "c" };
	int a = numSpecialEquivGroups(num);

	//test2
	num = { "aa", "bb", "ab", "ba" };
	int b = numSpecialEquivGroups(num);
	
	//test3
	num = { "abc", "acb", "bac", "bca", "cab", "cba" };
	int c = numSpecialEquivGroups(num);

	//test4
	num = { "abcd", "cdab", "adcb", "cbad" };
	int d = numSpecialEquivGroups(num);

	cout << a << endl << b << endl << c << endl << d<<endl;//3,4,3,1
	//test end
	system("pause");
	return 0;
}
