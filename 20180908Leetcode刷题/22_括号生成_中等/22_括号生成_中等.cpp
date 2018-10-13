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