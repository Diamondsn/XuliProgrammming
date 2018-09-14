#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。
//
//示例 1:
//输入 : S = "loveleetcode", C = 'e'
//输出 : [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
//
//说明 :
//字符串 S 的长度范围为[1, 10000]。
//C 是一个单字符，且保证是字符串 S 里的字符。
//S 和 C 中的所有字母均为小写字母。

vector<int> shortestToChar(string S, char C) {
	vector<int> result;
	if (S.size() < 1 || S.find(C) == -1)
		return result;

	for (int i = 0; i < S.size(); ++i)
	{
		if (S[i] == C)
		{
			result.push_back(0);
			continue;
		}

		int you = S.find(C, i + 1);
		int zuo = S.rfind(C, i - 1);
		int left = INT_MAX, right = INT_MAX;
		if (you != -1)
			left = abs(you - i);
		if (zuo != -1)
			right = abs(zuo - i);
			
		result.push_back(left < right ? left : right);
	}
	return result;
}

void main(){
	//test
	vector<int> result = shortestToChar("loveleetcode", 'e');
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	//test end
	system("pause");
}
