#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
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

//初解为按计数分类
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<int>vec(26, 0);
	vector<vector<string>>res;
	map<vector<int>, vector<string>>hash;
	for (string s : strs){
		vec.assign(26,0);
		for (char c : s){
			vec[c-'a']++;
		}
		hash[vec].push_back(s);
	}
	for (auto it = hash.begin(); it != hash.end(); ++it)
	{
		res.push_back(it->second);
	}
	return res;
}

//也可按照排序后的string进行分类
//vector<vector<string>> groupAnagrams(vector<string>& strs) {
//	vector<vector<string> > res;
//	unordered_map<string, vector<string> > m;
//	for (auto str : strs){
//		string t = str;
//		sort(t.begin(), t.end());
//		m[t].push_back(str);
//	}
//
//	for (auto a : m){
//		res.push_back(a.second);
//	}
//
//	return res;
//}

int main() {
	//test1
	vector<string>strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>>res = groupAnagrams(strs);
	for (vector<string>& vec : res)
	{
		for (string s : vec)
			cout << s << ",";
		cout << endl;
	}
	//test end
	system("pause");
	return 0;
}