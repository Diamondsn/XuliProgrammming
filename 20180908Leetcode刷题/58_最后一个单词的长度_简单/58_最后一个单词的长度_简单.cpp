#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
//
//如果不存在最后一个单词，请返回 0 。
//
//说明：一个单词是指由字母组成，但不包含任何空格的字符串。
//
//示例:
//输入: "Hello World"
//输出: 5

int lengthOfLastWord(string s) {
	if (s.size() < 1)return 0;
	s.erase(0, s.find_first_not_of(' '));
	s.erase(s.find_last_not_of(' ') + 1);//以上三行为trim()去掉字符串首尾空格代码;
	int a = s.find_last_of(' ');
	if (a == -1)return s.size();
	else return s.substr(a + 1).size();
}

void main() {
	//test1
	int a = lengthOfLastWord("Hello World");

	//test2
	int b = lengthOfLastWord("a ");
	cout << a << endl<<b<<endl;
	//test end
	system("pause");
}