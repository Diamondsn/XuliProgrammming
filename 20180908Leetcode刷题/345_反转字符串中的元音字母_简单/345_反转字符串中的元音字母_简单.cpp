#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
//
//示例 1:
//输入: "hello"
//输出: "holle"
//
//示例 2:
//输入: "leetcode"
//输出: "leotcede"
//
//说明:
//元音字母不包含字母"y"。

void swap(string& s, int i, int j)
{
	if (i == j || s[i]==s[j])
		return;

	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

bool isVowels(char s)
{
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'
		|| s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
		return true;

	return false;
}
string reverseVowels(string s) {
	if (s.size() < 1)
		return s;
	int i = -1, j = s.size();
	while (i < j)
	{
		while (i<(int)s.size() && !isVowels(s[++i]));//前面的判断是int与size_t判断-1>5
		while (j >= 1 && !isVowels(s[--j]));
		swap(s, i, j);
	}
	swap(s, i, j);
	return s;
}

int main() {
	//test1
	string a = reverseVowels("race car");

	//test2
	string b = reverseVowels("leetcode");

	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}