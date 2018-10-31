#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<time.h>
#include<map>
#include<unordered_map>
#include<functional>
using namespace std;

//给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
//
//示例 1:
//输入:
//"tree"
//输出:
//"eert"
//解释:
//'e'出现两次，'r'和't'都只出现一次。
//因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
//
//示例 2:
//输入:
//"cccaaa"
//输出:
//"cccaaa"
//解释:
//'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
//注意"cacaca"是不正确的，因为相同的字母必须放在一起。
//
//示例 3:
//输入:
//"Aabb"
//输出:
//"bbAa"
//解释:
//此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
//注意'A'和'a'被认为是两种不同的字符。

struct mygreater{
	bool operator()(const int& a, const int &b)const{
		return a > b;
	}
};

string frequencySort(string s) {
	unordered_map<char, int>hash;
	map<int, vector<char>,greater<int>>m;
	for (char c : s){
		if (hash.find(c) == hash.end())hash.insert(pair<char, int>(c, 1));
		else hash[c]++;
	}
	for (auto it = hash.begin(); it != hash.end(); ++it)
	{
		if (m.find(it->second) == m.end()){
			vector<char>vec = { it->first };
			m.insert(make_pair(it->second, vec)); 
		}
		else{
			m[it->second].push_back(it->first);
		}
	}
	string res;
	for (auto it = m.begin(); it != m.end(); ++it){
		vector<char>v = it->second;
		for (char c : v){
		//加k个相同的字符可以像以下处理
			res += string(it->first, c);
			/*int cur = it->first;
			while (cur){
				string a(1, c);
				res += a;
				cur--;
			}*/
		}
	}
	return res;
}

int main() {
	//test1
	string a = frequencySort("tree");

	//test2
	string b = frequencySort("cccaaa");

	//test3
	string c = frequencySort("Aabb");
	cout << a << endl << b << endl << c << endl;
	//test end
	system("pause");
	return 0;
}