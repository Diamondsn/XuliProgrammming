#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<deque>
using namespace std;

//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//图片地址 : http ://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
//
//示例:
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//说明:
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

void dfs(vector<string>& res, vector<vector<char>>vec, string& digits, string& temp,int cur){
	if (cur == digits.size())
		res.push_back(temp);
	else{
		for (int i = 0; i < vec[digits[cur] - '0'].size(); ++i){
			temp.push_back(vec[digits[cur] - '0'][i]);
			dfs(res, vec, digits, temp, cur + 1);
			temp.pop_back();
		}
	}
}

vector<string> letterCombinations(string digits) {
	if (digits.size() == 0)return{};
	vector<vector<char>>vec = { {}, {}, { 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 'i' }, { 'j', 'k', 'l' },
	{ 'm', 'n', 'o' }, { 'p', 'q', 'r', 's' }, { 't', 'u', 'v' }, { 'w', 'x', 'y', 'z' } };
	vector<string>res;
	string temp;
	dfs(res,vec, digits,temp,0);
	return res;
}

int main() {
	//test1
	vector<string>res = letterCombinations("23");
	for (string str : res)
		cout << str << endl;
	//test end

	system("pause");
	return 0;
}