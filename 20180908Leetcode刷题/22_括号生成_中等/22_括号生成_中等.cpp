#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//
//例如，给出 n = 3，生成结果为：
//
//[
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
//]

vector<string> generateParenthesis(int n) {
	vector<string>res;
	if (n == 0)
	{
		res.push_back("");
		return res;
	}
	for (int i = 0; i <= n - 1; ++i) {
		vector<string> left = generateParenthesis(i);
		vector<string>  right = generateParenthesis(n - 1 - i);
		for (int m = 0; m < left.size(); ++m) {
			for (int n = 0; n < right.size(); ++n) {
				string t= "(" + left[m] + ")" + right[n];
				res.push_back(t);
			}
		}
	}
	return res;
}

int main() {
	//test1
	vector<string>res = generateParenthesis(3);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}