#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个单词，你需要判断单词的大写使用是否正确。
//
//我们定义，在以下情况时，单词的大写用法是正确的：
//
//全部字母都是大写，比如"USA"。
//单词中所有字母都不是大写，比如"leetcode"。
//如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
//否则，我们定义这个单词没有正确使用大写字母。
//
//示例 1:
//输入: "USA"
//输出: True
//
//示例 2:
//输入: "FlaG"
//输出: False
//注意: 输入是由大写和小写拉丁字母组成的非空单词。

bool detectCapitalUse(string word) {
	bool flag;
	if (word[0] >= 97 && word[0] <= 122)
		flag = false;//小写
	else
	{
		flag = true;
	}
	bool flag1;
	for (int i = 1; i < word.size(); ++i)
	{
		if (!flag && !(word[i] >= 97 && word[i] <= 122))
		{
			return false;
		}
		else if (flag)
		{
			if (i == 1 && (word[i] >= 97 && word[i] <= 122))
				flag1 = false;
			else if (i == 1 && !(word[i] >= 97 && word[i] <= 122))
				flag1 = true;//大写

		if (i != 1 && flag1 && (word[i] >= 97 && word[i] <= 122))
			return false;

		if (i != 1 && !flag1 && !(word[i] >= 97 && word[i] <= 122))
			return false;
		}
	}
	return true;
}

void main(){
	//test1
	bool a = detectCapitalUse("USA");

	//test2
	bool b = detectCapitalUse("FlaG");

	cout << a << endl << b << endl;
	//test end
	system("pause");
}
