#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定两个字符串 s 和 t，它们只包含小写字母。
//字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
//请找出在 t 中被添加的字母。
//
//示例:
//输入：
//s = "abcd"
//t = "abcde"
//输出：
//e
//
//解释：
//'e' 是那个被添加的字母。

char findTheDifference(string s, string t) {
	int* arr = new int[26];
	for (int i = 0; i < 26; ++i)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		arr[(s[i] - 97)]++;
	}
	for (int i = 0; i < t.size(); ++i)
	{
		arr[(t[i] - 97)]--;
		if (arr[(t[i] - 97)] < 0)
			return (char)t[i];
	}
	return 'a';
}

void main(){
	//test1
	char a = findTheDifference("abcd", "abcde");
	cout << a << endl;
	//test end
	system("pause");
}
