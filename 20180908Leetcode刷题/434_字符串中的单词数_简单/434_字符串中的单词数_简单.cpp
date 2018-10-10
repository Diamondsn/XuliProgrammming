#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdint.h>
#include<map>
using namespace std;

//统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
//
//请注意，你可以假定字符串里不包括任何不可打印的字符。
//
//示例:
//输入: "Hello, my name is John"
//输出: 5

int countSegments(string s) {
	int count = 0;
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != ' ')
			count++;
		else{
			if (count != 0)
				res++;
			count = 0;
		}
	}
	if (count != 0)res++;
	return res;
}

int main() {
	//test1
	int a = countSegments("Hello, my name is John");

	//test2
	int b = countSegments("");

	//test3
	int c = countSegments("     test");
	cout << a << endl << b << endl << c << endl;
	//test end

	system("pause");
	return 0;
}