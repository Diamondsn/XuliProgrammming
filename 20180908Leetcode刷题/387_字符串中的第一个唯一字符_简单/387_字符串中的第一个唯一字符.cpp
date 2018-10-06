#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
//
//案例:
//
//s = "leetcode"
//返回 0.
//
//s = "loveleetcode",
//返回 2.
// 
//注意事项：您可以假定该字符串只包含小写字母。

int firstUniqChar(string s) {

}

int main() {
	//test1
	int a = firstUniqChar("leetcode");

	//test2
	int b = firstUniqChar("loveleetcode");
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}