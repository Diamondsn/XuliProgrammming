#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<map>
#include<list>
using namespace std;

//现在，我们用一些方块来堆砌一个金字塔。 每个方块用仅包含一个字母的字符串表示，例如 “Z”。
//
//使用三元组表示金字塔的堆砌规则如下：
//(A, B, C) 表示，“C”为顶层方块，方块“A”、“B”分别作为方块“C”下一层的的左、右子块。
//当且仅当(A, B, C)是被允许的三元组，我们才可以将其堆砌上。
//
//初始时，给定金字塔的基层 bottom，用一个字符串表示。
//一个允许的三元组列表 allowed，每个三元组用一个长度为 3 的字符串表示。
//
//如果可以由基层一直堆到塔尖返回true，否则返回false。
//
//示例 1:
//输入: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
//输出: true
//解析:
//可以堆砌成这样的金字塔:
//    A
//   / \
//  D   E
// / \ / \
//X   Y   Z
//
//因为符合('X', 'Y', 'D'), ('Y', 'Z', 'E') 和 ('D', 'E', 'A') 三种规则。
//
//示例 2:
//输入: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
//输出: false
//解析:
//无法一直堆到塔尖。
//注意, 允许存在三元组(A, B, C)和 (A, B, D) ，其中 C != D.
//
//注意：
//bottom 的长度范围在 [2, 8]。
//allowed 的长度范围在[0, 200]。
//方块的标记字母范围为{'A', 'B', 'C', 'D', 'E', 'F', 'G'}。

//也可采用回溯算法
//全排列
vector<string> quanpailie(vector<vector<string>>& vec){
	vector<string>res,temp,v;
	if (vec.size() < 1)return res;
	else if (vec.size() == 1)return vec[0];
	else{
		v = vec[0];
		vec.erase(vec.begin());
		temp = quanpailie(vec);
		for (string s : v){
			for (string str : temp){
				res.push_back(s + str);
			}
		}
		return res;
	}
}

//由于存在多种可能性，只能对所有可能的string都做检查
bool helper(multimap<string, string>& hash, string a){
	if (a.size() == 2){
		if (hash.find(a) == hash.end())return false;
		else return true;
	}
	vector<string> t;
	vector<vector<string>>vec;
	for (int i = 0; i < a.size() - 1; ++i){
		string temp = a.substr(i, 2);
		auto pair = hash.equal_range(temp);
		auto beg = pair.first;
		auto end = pair.second;
		t.clear();
		for (; beg != end; ++beg)
			t.push_back(beg->second);
		vec.push_back(t);
	}
	t = quanpailie(vec);
	for (string s : t){
		if (helper(hash, s))return true;
	}
	return false;
}

bool pyramidTransition(string bottom, vector<string>& allowed) {
	multimap<string, string>hash;
	for (string a : allowed){
		hash.insert(pair<string, string>(a.substr(0, 2), a.substr(2, 1)));
	}
	if (helper(hash, bottom))
		return true;
	return false;
}

int main() {
	//test1
	string bottom1 = "XYZ";
	vector<string>allowed = { "XYD", "YZE", "DEA", "FFF" };
	bool a = pyramidTransition(bottom1, allowed);

	//test2
	string bottom2 = "XXYX";
	allowed = { "XXX", "XXY", "XYX", "XYY", "YXZ" };
	bool b = pyramidTransition(bottom2, allowed);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}