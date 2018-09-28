#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
#include<set>
using namespace std;

//给定两个字符串 s 和 t，判断它们是否是同构的。
//如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
//所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。
//两个字符不能映射到同一个字符上，但字符可以映射自己本身。
//
//示例 1:
//输入: s = "egg", t = "add"
//输出: true
//
//示例 2:
//输入: s = "foo", t = "bar"
//输出: false
//
//示例 3:
//输入: s = "paper", t = "title"
//输出: true
//
//说明:
//你可以假设 s 和 t 具有相同的长度。

bool isIsomorphic(string s, string t) {
	if (s.size() != t.size())return false;
	map<char, char>hash;
	set<char> m;
	for (int i = 0; i < s.size(); ++i){
		m.insert(t[i]);
		if (hash.find(s[i]) == hash.end())hash.insert(pair<char, char>(s[i], t[i]));
		else if (t[i] != hash[s[i]])return false;
	}
	return m.size()!=hash.size()?false:true;
}

int main() {
	//test1
	bool a = isIsomorphic("egg", "add");

	//test2
	bool b = isIsomorphic("foo", "bar");

	//test3
	bool c = isIsomorphic("paper", "title");

	cout << a << endl << b << endl << c << endl;
	//test end
	system("pause");
	return 0;
}
