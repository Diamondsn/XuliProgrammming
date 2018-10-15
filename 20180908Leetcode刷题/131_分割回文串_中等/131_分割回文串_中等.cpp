#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//
//返回 s 所有可能的分割方案。
//
//示例:
//输入: "aab"
//输出:
//[
//  ["aa","b"],
//  ["a","a","b"]
//]
bool isHuiwenchuan(string s) {
	string ss;
	ss.resize(s.size());
	reverse_copy(s.begin(), s.end(), ss.begin());
	return s == ss;
}

void dfs(vector<vector<string>>& res, vector<string>&vec, int begin, string s) {
	if (begin == s.size()) {
		res.push_back(vec);
	}
	else {
		for (int i = begin+1; i <= s.size();++i) {
			if (isHuiwenchuan(s.substr(begin, i - begin)))
			{
				vec.push_back(s.substr(begin, i - begin));
				dfs(res, vec, i, s);
				vec.pop_back();
			}
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string>>res;
	vector<string>vec;
	dfs(res, vec, 0, s);
	return res;
}

int main() {
	//test1
	vector<vector<string>>res = partition("aab");
	for (vector<string>vec : res) {
		for (string temp : vec) {
			cout << temp << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}