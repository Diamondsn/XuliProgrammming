#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//使用栈实现队列的下列操作：
//
//push(x) -- 将一个元素放入队列的尾部。
//pop() -- 从队列首部移除元素。
//peek() -- 返回队列首部的元素。
//empty() -- 返回队列是否为空。
//示例:
//
//MyQueue queue = new MyQueue();
//
//queue.push(1);
//queue.push(2);  
//queue.peek();  // 返回 1
//queue.pop();   // 返回 1
//queue.empty(); // 返回 false
//说明:
//
//你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
		
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		if (right.empty())
			left.push(x);
		else
		{
			while (!right.empty())
			{
				int temp = right.top();
				right.pop();
				left.push(temp);
			}
			left.push(x);
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (!right.empty()) {
			int temp=right.top();
			right.pop();
			return temp;
		}
		else
		{
			while (!left.empty())
			{
				int temp = left.top();
				left.pop();
				right.push(temp);
			}
			int t = right.top();
			right.pop();
			return t;
		}
	}

	/** Get the front element. */
	int peek() {
		if (!right.empty())
			return right.top();
		else
		{
			while (!left.empty())
			{
				int temp = left.top();
				left.pop();
				right.push(temp);
			}
			return right.top();
		}
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return left.empty() && right.empty();
	}
public:
	stack<int> left;
	stack<int> right;
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/

int main() {
	//test1
	MyQueue obj = MyQueue();
	obj.push(1);
	obj.push(2);

	int param_1 = obj.peek();//1
	int param_2 = obj.pop();//1
	bool param_3 = obj.empty();//false
	cout << param_1 << endl << param_2 << endl << param_3 << endl;
	//test end

	system("pause");
	return 0;
}