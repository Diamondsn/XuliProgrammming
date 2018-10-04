#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，
//该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。
//
//若无答案，则返回空字符串。
//
//示例 1:
//输入: 
//words = ["w","wo","wor","worl", "world"]
//输出: "world"
//解释: 
//单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
//
//示例 2:
//输入: 
//words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
//输出: "apple"
//解释: 
//"apply"和"apple"都能由词典中的单词组成。但是"apple"得字典序小于"apply"。
//
//注意:
//所有输入的字符串都只包含小写字母。
//words数组长度范围为[1,1000]。
//words[i]的长度范围为[1,30]。

string longestWord(vector<string>& words) {
	vector<vector<string>>tu(31);
	for (int i = 0; i < words.size(); ++i) {
		tu[words[i].size()].push_back(words[i]);
	}
	if (tu[1].size() == 0)
		return "";
	int suoyin = 1;
	for (suoyin = 2; suoyin< tu.size(); ++suoyin) {
		for (auto j = tu[suoyin].begin(); j != tu[suoyin].end(); ) {//在遍历vector时删除与插入均需更新迭代器
			string t = j->substr(0, j->size() - 1);
			auto it = find(tu[suoyin - 1].begin(), tu[suoyin - 1].end(), t);
			if (it == tu[suoyin - 1].end())
				j = tu[suoyin].erase(j);//自动指向删除后的下一个
			else
				j++;
		}
		if (tu[suoyin].size() == 0) {
			break;
		}
	}
	int lowindex = 0;
	for (int j = 1; j < tu[suoyin - 1].size(); ++j) {//字典序比较
		if (tu[suoyin - 1][j] < tu[suoyin - 1][lowindex])
			lowindex = j;
	}
	return tu[suoyin - 1][lowindex];
}

int main() {
	//test1
	vector<string>words = { "w","wo","wor","worl", "world" };
	string a = longestWord(words);

	words = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
	string b = longestWord(words);

	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}