#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;

//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
//
//示例 1:
//输入: S = "ababcbacadefegdehijhklij"
//输出: [9,7,8]
//解释:
//划分结果为 "ababcbaca", "defegde", "hijhklij"。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
//
//注意:
//S的长度在[1, 500]之间。
//S只包含小写字母'a'到'z'。

vector<int> partitionLabels(string S) {
	vector<int>res;
	map<char, int>hash;//记录所有字符出现的最大索引
	for (int i = 0; i < S.size(); ++i) {
		if (hash.find(S[i]) == hash.end())
			hash.insert(pair<char, int>(S[i], i));
		else {
			hash[S[i]] = i;
		}
	}
	int max = -1, min;
	for (int i = 0; i < S.size();) {
		if (max == -1)
		{
			if (hash[S[i]] == i)
				res.push_back(1);
			else {
				max = hash[S[i]];
				min = i;
			}
		}
		else
		{
			while (i < max) {
				if (hash[S[i]] > max)
					max = hash[S[i]];
				i++;
			}
			res.push_back(max - min + 1);
			max = -1;
		}
		i++;
	}
	return res;
}

int main() {
	//test1
	vector<int>res = partitionLabels("caedbdedda");
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}