#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
using namespace std;

//给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
//
//如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
//
//返回所有不常用单词的列表。
//
//您可以按任何顺序返回列表。
//
//示例 1：
//输入：A = "this apple is sweet", B = "this apple is sour"
//输出：["sweet","sour"]
//
//示例 2：
//输入：A = "apple apple", B = "banana"
//输出：["banana"]
//
//提示：
//0 <= A.length <= 200
//0 <= B.length <= 200
//A 和 B 都只包含空格和小写字母。

vector<string> uncommonFromSentences(string A, string B) {
	string C = A +" "+ B;
	vector<string>res;
	vector<string>del;
	while (C.size()>0)
	{
		int i=C.find_first_of(" ");
		string str;
		if (i != -1)
		{
			str = C.substr(0, i);
			C = C.substr(i + 1);
		}
		else{
			str = C;
			C = "";
		}
		if (str.size() > 0)
		{
			auto ii = find(del.begin(), del.end(), str);
			auto it = find(res.begin(), res.end(), str);
			if (ii == del.end() && it == res.end())
			{
				res.push_back(str);
				continue;
			}
			if (ii==del.end() && it!=res.end())
			{
				res.erase(it);
				del.push_back(str);
				continue;
			}
			if (ii != del.end() && it != res.end())
			{
				res.erase(it);
				continue;
			}
		}
	}
	return res;
}

void main(){
	//test1
	string A = "this apple is sweet";
	string B = "this apple is sour";
	vector<string> res1 = uncommonFromSentences(A, B);
	cout << "test1" << endl;
	for (int i = 0; i < res1.size(); ++i)
	{
		cout << res1[i] << endl;
	}

	//test2
	A = "apple apple";
	B = "banana";
	vector<string> res2 = uncommonFromSentences(A, B);
	cout << "test2" << endl;
	for (int i = 0; i < res2.size(); ++i)
	{
		cout << res2[i] << endl;
	}

	//test3
	A = "fd kss fd";
	B = "fd fd kss";
	vector<string> res3 = uncommonFromSentences(A, B);
	cout << "test3" << endl;
	for (int i = 0; i < res3.size(); ++i)
	{
		cout << res3[i] << endl;
	}
	//test end
	system("pause");
}
