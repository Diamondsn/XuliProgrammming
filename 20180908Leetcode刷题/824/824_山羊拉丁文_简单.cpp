#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个由空格分割单词的句子 S。每个单词只包含大写或小写字母。
//
//我们要将句子转换为 “Goat Latin”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。
//
//山羊拉丁文的规则如下：
//
//如果单词以元音开头（a, e, i, o, u），在单词后添加"ma"。
//例如，单词"apple"变为"applema"。
//
//如果单词以辅音字母开头（即非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
//例如，单词"goat"变为"oatgma"。
//
//根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从1开始。
//例如，在第一个单词后添加"a"，在第二个单词后添加"aa"，以此类推。
//返回将 S 转换为山羊拉丁文后的句子。
//
//示例 1:
//输入: "I speak Goat Latin"
//输出: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
//
//示例 2:
//输入: "The quick brown fox jumped over the lazy dog"
//输出: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
//
//说明:
//S 中仅包含大小写字母和空格。单词间有且仅有一个空格。
//1 <= S.length <= 150。

string toGoatLatin(string S) {
	string res;
	int m = 0;
	while (S.size() > 0)
	{
		m++;
		string temp;
		int i = S.find(" ");
		if (i != -1)
		{
			temp = S.substr(0, i);
			S = S.substr(i + 1);
		}
		else
		{
			temp = S;
			S = "";
		}
		int j = 0;
		if ((temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u' || temp[0] == 'A' || temp[0] == 'E' || temp[0] == 'I' || temp[0] == 'O' || temp[0] == 'U'))
		{
			temp += "ma";
			while (j != m)
			{
				temp += 'a';
				j++;
			}
		}
		else{
			char t = temp[0];
			temp.erase(temp.begin());
			temp += t;
			temp += "ma";
			while (j != m)
			{
				temp += 'a';
				j++;
			}
		}
		if (m==1)
		res += temp;
		else
		{
			res = res + " " + temp;
		}
	}
	return res;
}

void main(){
	//test1
	string a = toGoatLatin("I speak Goat Latin");

	//test2
	string b = toGoatLatin("The quick brown fox jumped over the lazy dog");

	cout << a+'?' << endl << b+'?' << endl;
	//test end
	system("pause");
}
