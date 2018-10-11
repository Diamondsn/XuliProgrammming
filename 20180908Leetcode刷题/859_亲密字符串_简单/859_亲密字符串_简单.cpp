#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false 。
//
//示例 1：
//输入： A = "ab", B = "ba"
//输出： true
//
//示例 2：
//输入： A = "ab", B = "ab"
//输出： false
//
//示例 3:
//输入： A = "aa", B = "aa"
//输出： true
//
//示例 4：
//输入： A = "aaaaaaabc", B = "aaaaaaacb"
//输出： true
//
//示例 5：
//输入： A = "", B = "aa"
//输出： false
// 
//提示：
//0 <= A.length <= 20000
//0 <= B.length <= 20000
//A 和 B 仅由小写字母构成。

bool buddyStrings(string A, string B) {
	if (A.size() != B.size())return false;
	map<char, int>hash;
	for (int i = 0; i < A.size(); ++i){
		if (hash.find(A[i]) == hash.end())
			hash.insert(pair<char, int>(A[i], 1));
		else
			hash[A[i]]++;
	}
	if (A.compare(B) == 0)
	{
		for (auto it = hash.begin(); it != hash.end(); ++it)
			if (it->second > 1)
				return true;
		return false;
	}
    for (int i = 0; i < B.size();++i){
		if (hash.find(A[i]) == hash.end())
			return false;
		else
			hash[B[i]]--;

		if (hash[B[i]] < 0)
			return false;
    }
	int i,j;
	for (i = 0; i < A.size(); ++i){
		if (A[i] != B[i])break;
	}
	for (j = A.size() - 1; j >= 0; --j)
		if (A[j]!= B[j])break;
	if (A[i] == B[j]&&A[j]==B[i])return true;
	return false;
}

int main() {
	//test1
	bool a = buddyStrings("ab", "ba");

	//test2
	bool b = buddyStrings("ab", "ab");

	//test3
	bool c = buddyStrings("aa", "aa");

	//test4
	bool d = buddyStrings("aaaaaaabc","aaaaaaacb");

	//test5
	bool e = buddyStrings("", "aa");
	cout << a << endl << b << endl<<c<<endl<<d<<endl<<e<<endl;
	//test end

	system("pause");
	return 0;
}