#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdint.h>
#include<map>
#include<algorithm>
using namespace std;

//给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：
//
//() 得 1 分。
//AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
//(A) 得 2 * A 分，其中 A 是平衡括号字符串。
//
//示例 1：
//输入： "()"
//输出： 1
//
//示例 2：
//输入： "(())"
//输出： 2
//
//示例 3：
//输入： "()()"
//输出： 2
//
//示例 4：
//输入： "(()(()))"
//输出： 6
//
//提示：
//S 是平衡括号字符串，且只含有(和) 。
//2 <= S.length <= 50

int scoreOfParentheses(string S) {
	if (S.size() == 0)return 0;
	int cur = 1, num = 1;
	while (num!=0){
		if (S[cur] == '(')
			num++;
		else
			num--;
		cur++;
	}
	if (cur == S.size()){
		if (cur == 2)return 1;
		else return 2 * scoreOfParentheses(S.substr(1, S.size() - 2));
	}
	return scoreOfParentheses(S.substr(0, cur)) + scoreOfParentheses(S.substr(cur));
}

void main() {
	//test1
	int a = scoreOfParentheses("()");

	//test2
	int b = scoreOfParentheses("(())");

	//test3
	int c = scoreOfParentheses("()()");

	//test4
	int d = scoreOfParentheses("(()(()))");
	cout << a << endl << b << endl << c << endl << d << endl;
	//test end
	system("pause");
}