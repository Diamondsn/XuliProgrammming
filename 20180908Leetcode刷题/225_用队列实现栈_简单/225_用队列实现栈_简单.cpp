#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
using namespace std;

//使用队列实现栈的下列操作：
//
//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//
//注意 :
//你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
		cur = true;//1
	}

	/** Push element x onto stack. */
	void push(int x) {
		if (cur)
		{
			if (!q2.empty())
			{
				int temp = q2.front();
				q2.pop();
				q1.push(temp);
			}
			q1.push(x);
		}
		else{
			if (!q1.empty())
			{
				int temp = q1.front();
				q1.pop();
				q2.push(temp);
			}
			q2.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (empty())
			return -1;
		int t;
		if (cur)
		{
			while (q1.size() > 1)
			{
				int temp = q1.front();
				q1.pop(); 
				q2.push(temp);
			}
			t = q1.front();
			q1.pop();
		}
		else
		{
			while (q2.size() > 1)
			{
				int temp = q2.front();
				q2.pop();
				q1.push(temp);
			}
			t = q2.front();
			q2.pop();
		}
		cur = !cur;
		return t;
	}

	/** Get the top element. */
	int top() {
		if (empty())
			return -1;

		int t;
		if (cur)
		{
			cur = !cur;
			while (q1.size() > 1)
			{
				int temp = q1.front();
				q1.pop();
				q2.push(temp);
			}
			t = q1.front();
			q1.pop();
			q2.push(t);
			return t;
		}
		else
		{
			cur = !cur;
			while (q2.size() > 1)
			{
				int temp = q2.front();
				q2.pop();
				q1.push(temp);
			}
			t = q2.front();
			q2.pop();
			q1.push(t);
			return t;
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}
	queue<int> q1;
	queue<int> q2;
	bool cur;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack obj = new MyStack();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.top();
* bool param_4 = obj.empty();
*/

void main(){
	//test1
	MyStack obj = MyStack();
	obj.push(1);
	obj.push(2);
	int param_2 = obj.top();
	
	int param_4 = obj.pop();
	bool param_5 = obj.empty();
	cout << param_2  << endl << param_4 << endl<<param_5<<endl;
	//test end
	system("pause");
}
