#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//不使用任何内建的哈希表库设计一个哈希集合
//
//具体地说，你的设计应该包含以下的功能
//
//add(value)：向哈希集合中插入一个值。
//contains(value) ：返回哈希集合中是否存在这个值。
//remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
//
//示例 :
//MyHashSet hashSet = new MyHashSet();
//hashSet.add(1);
//hashSet.add(2);
//hashSet.contains(1);    // 返回 true
//hashSet.contains(3);    // 返回 false (未找到)
//hashSet.add(2);
//hashSet.contains(2);    // 返回 true
//hashSet.remove(2);
//hashSet.contains(2);    // 返回  false (已经被删除)
//
//注意：
//所有的值都在[1, 1000000]的范围内。
//操作的总数目在[1, 10000]范围内。
//不要使用内建的哈希集合库。

//使用数组存储bool值减轻存储负担
class MyHashSet {
public:
	/** Initialize your data structure here. */
	MyHashSet() {
		hashset = vector<bool>(1000001, false);
	}

	void add(int key) {
		hashset[key] = true;
	}

	void remove(int key) {
		hashset[key] = false;
	}

	/** Returns true if this set did not already contain the specified element */
	bool contains(int key) {
		return hashset[key];
	}
private:
	vector<bool>hashset;
};

/**
* Your MyHashSet object will be instantiated and called as such:
* MyHashSet obj = new MyHashSet();
* obj.add(key);
* obj.remove(key);
* bool param_3 = obj.contains(key);
*/

int main() {
	//test1
	MyHashSet hashSet = MyHashSet();
	hashSet.add(1);
	hashSet.add(2);
	bool a=hashSet.contains(1);    // 返回 true
	bool b=hashSet.contains(3);    // 返回 false (未找到)
	hashSet.add(2);
	bool c=hashSet.contains(2);    // 返回 true
	hashSet.remove(2);
	bool d=hashSet.contains(2);    // 返回  false (已经被删除)
	cout << a << endl << b << endl << c << endl << d << endl;
	//test end
	system("pause");
	return 0;
}