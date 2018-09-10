#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//����һ�������б�ֻ���ؿ���ʹ���ڼ���ͬһ�е���ĸ��ӡ�����ĵ��ʡ���������ͼ��ʾ��
//
//American keyboard
//
//ʾ��1 :
//����: ["Hello", "Alaska", "Dad", "Peace"]
//��� : ["Alaska", "Dad"]
//	
//ע�� :
//������ظ�ʹ�ü�����ͬһ�ַ���
//����Լ���������ַ�����ֻ������ĸ��

bool correct(int flag, string& str)
{
	vector<vector<char>> keyboard;
	vector<char> temp = { 'q','w','e','r','t','y','u','i','o','p' };
	keyboard.push_back(temp);
	temp = { 'a','s','d','f','g','h','j','k','l' };
	keyboard.push_back(temp);
	temp = { 'z','x','c','v','b','n','m' };
	keyboard.push_back(temp);

	for (int j = 1; j < str.size(); ++j)
	{
		char c = str[j] <= 90 ? str[j] + 32 : str[j];
		if (find(keyboard[flag].begin(), keyboard[flag].end(), c) == keyboard[flag].end())
		{
			return false;
		}
	}
	return true;
}

vector<string> findWords(vector<string>& words) {
	vector<vector<char>> keyboard;
	vector<char> temp = { 'q','w','e','r','t','y','u','i','o','p' };
	keyboard.push_back(temp);
	temp = { 'a','s','d','f','g','h','j','k','l' };
	keyboard.push_back(temp);
	temp = { 'z','x','c','v','b','n','m' };
	keyboard.push_back(temp);

	int flag = 4;
	vector<string> result;
	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == "")
			continue;

		for (int k = 0; k < keyboard.size(); ++k)
		{
			char c = words[i][0] <= 90 ? words[i][0] + 32 : words[i][0];
			if (find(keyboard[k].begin(), keyboard[k].end(), c) != keyboard[k].end())
			{
				flag = k;
				break;
			}
		}

		if (flag == 4)
			continue;

		if (!correct(flag, words[i]))
			continue;

		result.push_back(words[i]);
	}

	return result;
}

int main() {
	//test
	vector<string> vec = { "Hello","Alaska","Dad","Peace" };
	vector<string> result = findWords(vec);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}