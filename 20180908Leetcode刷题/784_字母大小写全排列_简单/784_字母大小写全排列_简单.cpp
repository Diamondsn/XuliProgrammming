#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<sstream>
using namespace std;

//给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
//
//示例:
//输入: S = "a1b2"
//输出: ["a1b2", "a1B2", "A1b2", "A1B2"]
//
//输入: S = "3z4"
//输出: ["3z4", "3Z4"]
//
//输入: S = "12345"
//输出: ["12345"]
//
//注意：
//S 的长度不超过12。
//S 仅由数字和字母组成。

vector<string> letterCasePermutation(string S) {
	vector<string>vec;
	if (S.size() < 1)
	{
		vec.push_back("");
		return vec;
	}

	int i = 0;
	string temp;
	while (i < S.size()){
		if (S[i] < 48 || S[i]>58)
			break;

		temp += S[i];
		i++;
	}
	if (i == S.size())
	{
		vec.push_back(temp);
		return vec;
	}
	else
	{
		string t1 = (temp + char(S[i] >= 97 ? S[i] : S[i] + 32));
		string t2 = (temp + char(S[i] >= 97 ? S[i] - 32 : S[i]));
		S = S.substr(i + 1);
		vector<string>sub;
		sub = letterCasePermutation(S);
		if (sub.size() > 0)
		{
			for (int i = 0; i < sub.size(); ++i)
			{
				vec.push_back(t1 + sub[i]);
				vec.push_back(t2 + sub[i]);
			}
		}
		else
		{
			vec.push_back(t1);
			vec.push_back(t2);
		}
		return vec;
	}
}

int main() {
	//test1
	cout << "test1" << endl;
	vector<string>str = letterCasePermutation("a1b2");
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << endl;
	}
	cout << endl;

	//test2
	cout << "test2" << endl;
	str = letterCasePermutation("3z4");
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << endl;
	}
	cout << endl;

	//test3
	cout << "test3" << endl;
	str = letterCasePermutation("12345");
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << endl;
	}
	cout << endl;

	//test4
	cout << "test4" << endl;
	str = letterCasePermutation("");
	cout << "空字符串的输出结果应该包含一个空元素" <<str.size()<< endl;
	//test end

	system("pause");
	return 0;
}