#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
using namespace std;

//给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，
//并返回结果。 # 代表退格字符。
//
//示例 1：
//输入：S = "ab#c", T = "ad#c"
//输出：true
//解释：S 和 T 都会变成 “ac”。
//
//示例 2：
//输入：S = "ab##", T = "c#d#"
//输出：true
//解释：S 和 T 都会变成 “”。
//
//示例 3：
//输入：S = "a##c", T = "#a#c"
//输出：true
//解释：S 和 T 都会变成 “c”。
//
//示例 4：
//输入：S = "a#c", T = "b"
//输出：false
//解释：S 会变成 “c”，但 T 仍然是 “b”。

bool backspaceCompare(string S, string T) {
	string s, t;
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] != '#')
			s += S[i];
		else if (s.size() > 0 && S[i] == '#')
			s.erase(s.end() - 1);
	}
	for (int i = 0; i < T.size(); ++i)
	{
		if (T[i] != '#')
			t += T[i];
		else if (t.size() > 0 && T[i] == '#')
			t.erase(t.end() - 1);
	}
	return s == t;
}

int main() {
	//test1
	bool a = backspaceCompare("ab#c", "ad#c");

	//test2
	bool b = backspaceCompare("ab##", "c#d#");

	//test3
	bool c = backspaceCompare("a##c", "#a#c");

	//tets4
	bool d= backspaceCompare("a#c", "b");

	cout << a << endl <<b << endl <<c << endl<<d<<endl;
	//test end
	system("pause");
	return 0;
}
