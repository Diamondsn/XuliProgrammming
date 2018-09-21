#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
using namespace std;

//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) -- 将元素 x 推入栈中。
//pop() -- 删除栈顶的元素。
//top() -- 获取栈顶元素。
//getMin() -- 检索栈中的最小元素。
//
//示例:
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 -2.

//使用两个栈,记录压栈时的最小值
//class MinStack {
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//
//	}
//
//	void push(int x) {
//		if(s2.empty() || x<s2.top()) s2.push(x);
//		s1.push(x);
//	}
//
//	void pop() {
//		if (s1.top() == s2.top())s2.pop();
//		s1.pop();
//	}
//
//	int top() {
//		return s1.top();
//	}
//
//	int getMin() {
//		return s2.top();
//	}
//	stack<int>s1,s2;
//};

//使用一个栈
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		min = INT_MAX;
	}

	void push(int x) {
		if (x <= min)//当最小值更替时，将当前最小值压入
		{
			s1.push(min);
			min = x;
		}
		s1.push(x);
	}

	void pop() {
		int t=s1.top();
		s1.pop();
		if (t == min){
			min = s1.top();
			s1.pop();
		}
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return min;
	}
	stack<int>s1;
	int min;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/

int main() {
	//test1
	MinStack minStack = MinStack();
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	int a=minStack.getMin();   //--> 返回 - 3.
	minStack.pop();
	int b=minStack.top();      //--> 返回 0.
	int c=minStack.getMin();   //--> 返回 - 2.

	cout << a << endl << b << endl<<c<<endl;//3,0,-2
	//test end
	system("pause");
	return 0;
}
