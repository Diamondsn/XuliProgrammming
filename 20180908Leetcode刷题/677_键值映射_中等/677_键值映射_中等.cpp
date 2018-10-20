#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//实现一个 MapSum 类里的两个方法，insert 和 sum。
//对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。
//如果键已经存在，那么原来的键值对将被替代成新的键值对。
//对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。
//
//示例 1:
//输入: insert("apple", 3), 输出: Null
//输入: sum("ap"), 输出: 3
//输入: insert("app", 2), 输出: Null
//输入: sum("ap"), 输出: 5

//此题标准更快解法是新建字典树，以下为字典树节点数据结构;
//class TrieNode {
//public:
//	int val;
//	vector<TrieNode*> clds;
//	TrieNode() :val(0), clds(26, NULL) {
//
//	}
//};

class MapSum {
public:
	/** Initialize your data structure here. */
	MapSum() {
		hash.clear();
		sumhash.clear();
	}

	void insert(string key, int val) {
		if (hash.find(key) == hash.end()) {
			hash.insert(pair<string, int>(key, val));
			for (int i = 1; i <= key.size(); ++i) {
				string prefix = key.substr(0, i);
				if (sumhash.find(prefix) == sumhash.end()) {
					sumhash.insert(pair<string, int>(prefix, val));
				}
				else {
					sumhash[prefix] += val;
				}
			}
		}
		else {
			int chazhi = val - hash[key];
			for (int i = 1; i <= key.size(); ++i) {
				string prefix = key.substr(0, i);
				sumhash[prefix] += chazhi;
			}
		}
	}

	int sum(string prefix) {
		return sumhash[prefix];
	}
	map<string, int>hash;
	map<string, int>sumhash;
};

/**
* Your MapSum object will be instantiated and called as such:
* MapSum obj = new MapSum();
* obj.insert(key,val);
* int param_2 = obj.sum(prefix);
*/

void main() {
	//test
	MapSum obj = MapSum();
	obj.insert("apple", 3);
	int a = obj.sum("ap");
	obj.insert("app", 2);
	int b = obj.sum("ap");
	cout << a << endl << b << endl;
	//test end
	system("pause");
}
