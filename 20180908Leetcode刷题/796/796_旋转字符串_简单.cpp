#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
using namespace std;

//给定两个字符串, A 和 B。
//
//A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后，A 能变成B，那么返回True。
//
//示例 1:
//输入: A = 'abcde', B = 'cdeab'
//输出: true
//
//示例 2:
//输入: A = 'abcde', B = 'abced'
//输出: false
//
//注意：
//A 和 B 长度不超过 100。

bool rotateString(string A, string B) {
	if (A.size() != B.size())
		return false;

	if (B.size() < 1)return true;
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] == B[0] )
		{
			string s1=B.substr(0, A.size() - i);
			string s2=A.substr(i);
			string temp = A.substr(0, i);
			string te = B.substr(A.size() - i);
			if (s1.compare(s2)==0&&temp.compare(te)==0)
				return true;
		}
	}
	return false;
}

int main() {
	//test1
	bool a = rotateString("abcde", "cdeab");

	//test2
	bool b = rotateString("abcde", "abced");

	cout << a << endl<<b<<endl;
	//test end
	system("pause");
	return 0;
}
