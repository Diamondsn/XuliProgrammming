#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdint.h>
#include<map>
using namespace std;

//给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
//
//字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
//
//说明：
//字母异位词指字母相同，但排列不同的字符串。
//不考虑答案输出的顺序。
//
//示例 1:
//输入:
//s: "cbaebabacd" p: "abc"
//输出:
//[0, 6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
//
//示例 2:
//输入:
//s: "abab" p: "ab"
//输出:
//[0, 1, 2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

//思路:map计数法,
//此题代码较长原因是当找到了所有字母均为map中的时候会重用之前的map
//同时，至始至终只用了同一个map
//用较长的代码换了较少的空间占用和叫短的时间占用
vector<int> findAnagrams(string s, string p) {
	vector<int>vec;
	if (s.size() < p.size())return vec;
	map<char, int>hash;
	bool flag = false;//未找到第一个符合要求的
	for (int i = 0; i < p.size(); ++i){
		if (hash.find(p[i]) == hash.end())
			hash.insert(pair<char, int>(p[i], 1));
		else
			hash[p[i]]++;
	}
	
	for (int i = 0; i <= s.size()-p.size();){
		if (!flag){
			for (int j = i; j < i + p.size(); ++j){
				if (hash.find(s[j]) == hash.end())
				{
					int m = i;
					while (m < j){
						hash[s[m]]++;
						m++;
					}
					i = j + 1;
					break;
				}
				else{
					hash[s[j]]--;
					if (j == i + p.size() - 1)
						flag = true;
				}
			}
		}
		else{
			if (hash.find(s[i + p.size() - 1]) == hash.end())
			{
				int m = i-1;
				while (m < i + p.size()-1){
					hash[s[m]]++;
					m++;
				}
				i = i + p.size();
				flag = false;
			}
			else
			{
				hash[s[i-1]]++;
				hash[s[i + p.size() - 1]]--;
			}
		}
		if (!flag)
		{
			continue;
		}
		bool sucess = true;
		for (auto it = hash.begin(); it != hash.end(); ++it){
			if (it->second != 0){
				sucess = false;
				break;
			}
		}
		if (sucess)vec.push_back(i);
		i++;
	}
	return vec;
}

void VectorBianLi(vector<int>& vec){
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
}

int main() {
	//test1
	vector<int>res1 = findAnagrams("cbaebabacd", "abc");
	VectorBianLi(res1);

	//test2
	cout << "test2" << endl;
	res1 = findAnagrams("ababa", "ab");
	VectorBianLi(res1);
	//test end

	system("pause");
	return 0;
}