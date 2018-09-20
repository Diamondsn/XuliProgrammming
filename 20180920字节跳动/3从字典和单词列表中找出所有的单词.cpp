#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

//题目描述
//给定一个(M*N)二维的字母词典和一组单词列表(长度K)，M为列数，
//N为行数，从词典里找出所有的单词。
//单词要遵循的规则是所有的字母要词典中是相邻的，可以上下相邻也可以左右相邻，
//词典中每个字母单元只能使用一次。
//
//输入描述
//第一行三个整数分别代表M N K
//第二行 K个单词
//第三行到第K+3行为词典
//输出描述
//找到的单词，每行一个
//
//示例1
//输入
//5 5 3
//hello help high
//p a b h m
//f h e c p
//c i l l h
//b g h o n
//h x c m l
//输出
//hello
//high

//k为第几个字符
bool findword(vector<vector<char>>& vec, vector<vector<bool>> flag,string str, int i, int j,int k)
{
	if (flag[i][j] == true)
		return false;

	if (k < str.size() && str[k] != vec[i][j])
		return false;

	if (k < str.size() && str[k] == vec[i][j])
	{
		flag[i][j] = true;
		if (k == str.size() - 1)
			return true;

		k = k + 1;
		if (i - 1 >= 0)
		{
			if (findword(vec, flag, str, i - 1, j, k))
				return true;
		}
		if (i + 1 < vec.size())
		{
			if (findword(vec, flag, str, i + 1, j, k))
				return true;
		}
		if (j - 1>=0)
		{
			if (findword(vec, flag, str, i, j-1, k))
				return true;
		}
		if (j + 1 < vec[0].size())
		{
			if (findword(vec, flag, str, i , j+1, k))
				return true;
		}
	}

	return false;

	
}

vector<string> test(vector<vector<char>>& vec, vector<string>& word)
{
	vector<string>res;
	vector<char> w;
	for (int i = 0; i < word.size(); ++i)
	{
		w.push_back(word[i][0]);
	}
	vector<vector<bool>> flag;
	for (int m = 0; m < vec.size(); ++m)
	{
		vector<bool>temp;
		for (int t = 0; t < vec[m].size(); ++t)
		{
			temp.push_back(false);
		}
		flag.push_back(temp);
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec[i].size(); ++j)
		{
			for (int k = 0; k < w.size(); ++k)
			{
				if (w[k] == vec[i][j])
				{
					if (findword(vec,flag, word[k], i, j,0) &&find(res.begin(),res.end(),word[k])==res.end())
						res.push_back(word[k]);
				}
			}
		}
	}
	return res;
}

void main() {
	vector<vector<char>> vec = {
		{'p','a','b','h','m'},
	{'f','h','e','c','p'},
	{'c','i','l','l','h'},
	{'b','g','h','o','n'},
	{'h','x','c','m','l'} };
	vector<string>word = { "hello", "help","high" };

	vector<string>res = test(vec, word);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}

	system("pause");
}
