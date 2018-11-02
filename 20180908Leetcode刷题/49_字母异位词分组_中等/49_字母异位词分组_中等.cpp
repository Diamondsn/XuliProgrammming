#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
//示例:
//输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//
//说明：
//所有输入均为小写字母。
//不考虑答案输出的顺序。

vector<vector<string>> groupAnagrams(vector<string>& strs) {

}

int main() {
	//test1
	vector<string>strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>>res = groupAnagrams(strs);
	for (vector<string>& vec : res)
		for (string s : vec)
			cout << s << endl;
	//test end
	system("pause");
	return 0;
}