#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
using namespace std;

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//
//示例 1:
//输入: "()"
//输出: true
//
//示例 2:
//输入: "()[]{}"
//输出: true
//
//示例 3:
//输入: "(]"
//输出: false
//
//示例 4:
//输入: "([)]"
//输出: false
//
//示例 5:
//输入: "{[]}"
//输出: true

bool isValid(string s) {
	if (s.size() < 1)return true;
	string help;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')help += s[i];
		else {
			if (s.size() < 1 || (s[i] == ')' && help[help.size() - 1] != '(') || (s[i] == ']'&&help[help.size() - 1] != '[')
				|| (s[i] == '}'&&help[help.size() - 1] != '{'))return false;
			else
				help.erase(help.end() - 1);
		}
	}
	return help.size() > 0 ? false : true;
}

void main() {
	//test1
	bool a = isValid("()");

	//test2
	bool b = isValid("()[]{}");

	//test3
	bool c = isValid("(]");

	//test4
	bool d = isValid("([)]");
	
	//test5
	bool e = isValid("{[]}");

	cout << a << endl << b << endl << c << endl << d << endl << e << endl;
	//test end
	system("pause");
}
