#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
//
//示例 1：
//输入："ab-cd"
//输出："dc-ba"
//
//示例 2：
//输入："a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"
//
//示例 3：
//输入："Test1ng-Leet=code-Q!"
//输出："Qedo1ct-eeLg=ntse-T!"
// 
//提示：
//S.length <= 100
//33 <= S[i].ASCIIcode <= 122 
//S 中不包含 \ or "

void Swap(string & s, int i, int j){
	if (i == j)return;
	else
	{
		s[i] ^= s[j];
		s[j] ^= s[i];
		s[i] ^= s[j];
	}
}
bool isChar(char c){
	if ((c >= 'a'&& c <= 'z') || (c >= 'A'&& c <= 'Z'))
		return true;
	return false;
}
string reverseOnlyLetters(string S) {
	int i = 0, j = S.size() - 1;
	do{
		while (i<S.size() && !isChar(S[i]))i++;
		while (j>=0 && !isChar(S[j]))--j;
		if (i < j){
			Swap(S, i, j);
			i++; --j;
		}
	} while (i < j);
	return S;
}

int main() {
	//test1
	string a = reverseOnlyLetters("ab-cd");

	//test2
	string b = reverseOnlyLetters("a-bC-dEf-ghIj");

	//test3
	string c = reverseOnlyLetters("Test1ng-Leet=code-Q!");
	cout << a << endl<<b<<endl<<c<<endl;
	//test end

	system("pause");
	return 0;
}