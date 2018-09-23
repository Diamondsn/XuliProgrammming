#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//示例 1:
//输入: "Let's take LeetCode contest"
//输出 : "s'teL ekat edoCteeL tsetnoc"
//注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

string reverseWords(string s) {
	vector<string> vec;
	string result="";
	while (s.size() > 0)
	{
		int n = s.find_first_of(" ");
		if (n == -1)
		{
			vec.push_back(s);
			s = "";
		}
		else {
			vec.push_back(s.substr(0, n));
			s = s.substr(n + 1);
		}
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		reverse(vec[i].begin(), vec[i].end());
		if (i == 0)
		{
			result += vec[i];
		}
		else
		{
			result = result + " " + vec[i];
		}
	}
	return result;
}

int main() {
	//test1
	string s = reverseWords("Let's take LeetCode contest");
	cout << s << endl;//s'teL ekat edoCteeL tsetnoc
	//test end

	system("pause");
	return 0;
}