#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
//列表中的项或者为一个整数，或者是另一个列表。
//示例 1:
//输入: [[1,1],2,[1,1]]
//输出: [1,1,2,1,1]
//解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
//
//示例 2:
//输入: [1,[4,[6]]]
//输出: [1,4,6]
//解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,4,6]。

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		for (int i = (int)nestedList.size() - 1; i >= 0; --i){
			mystack.push(nestedList[i]);
		}
		//为防止出现[[]]的hasNext()出现true的情况，需进行解压，保证stack的top为数；
		while (!mystack.empty() && !mystack.top().isInteger()){
			NestedInteger pNode = mystack.top();
			mystack.pop();
			if (pNode.isInteger())
				break;
			else{
				const vector<NestedInteger>&vec = pNode.getList();
				for (int i = (int)vec.size() - 1; i >= 0; --i){
					mystack.push(vec[i]);
				}
			}
		}
	}

	int next() {
		NestedInteger pTempNode = mystack.top();
		mystack.pop();
		
		while (!mystack.empty() && !mystack.top().isInteger()){
			NestedInteger pNode = mystack.top();
			mystack.pop();
			if (pNode.isInteger())
				break;
			else{
				const vector<NestedInteger>&vec = pNode.getList();
				for (int i = (int)vec.size() - 1; i >= 0; --i){
					mystack.push(vec[i]);
				}
			}
		}
		return pTempNode.getInteger();
	}

	bool hasNext() {
		return !mystack.empty();
	}
	stack<NestedInteger>mystack;
};

/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/

//以下为使用迭代器的做法
//class NestedIterator {
//public:
//	stack<vector<NestedInteger>::iterator> begins, ends;
//	NestedIterator(vector<NestedInteger> &nestedList) {
//		begins.push(nestedList.begin());
//		ends.push(nestedList.end());
//	}
//
//	int next() {
//		return (begins.top()++)->getInteger();
//	}
//
//	bool hasNext() {
//		while (begins.size())
//		{
//			if (begins.top() == ends.top())
//			{
//				begins.pop();
//				ends.pop();
//				continue;
//			}
//			else
//			{
//				auto val = begins.top();
//				if (val->isInteger()) return true;
//				begins.top()++;
//				begins.push(val->getList().begin());
//				ends.push(val->getList().end());
//			}
//		}
//		return false;
//	}
//};

int main() {
	//test1
	//由于不清楚NestedInteger的内部实现，或者根本没有构造函数，所以不能测试

	//test end
	system("pause");
	return 0;
}