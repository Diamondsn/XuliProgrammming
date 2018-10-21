#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<set>
#include<deque>
using namespace std;

//题目描述
//给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
//例如，如果输入数组{ 2,3,4,2,6,2,5,1 }及滑动窗口的大小3，那么一共存在6个滑动窗口，
//他们的最大值分别为{ 4,4,6,6,6,5 }； 针对数组{ 2,3,4,2,6,2,5,1 }的滑动窗口有以下6个：
//{ [2,3,4],2,6,2,5,1 }，{ 2,[3,4,2],6,2,5,1 }，{ 2,3,[4,2,6],2,5,1 }，{ 2,3,4,[2,6,2],5,1 }，
//{ 2,3,4,2,[6,2,5],1 }，{ 2,3,4,2,6,[2,5,1] }。

//思路:用双端队列，O(n)的时间复杂度和空间复杂度
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int>res;
	deque<int>mydeque;//存储索引，同时索引映射的值是从大到小排列的
	for (int i = 0; i < num.size(); ++i) {
		while (mydeque.size() && num[mydeque.back()] < num[i])mydeque.pop_back();//从后往前剔除比他小的数
		while (mydeque.size() && i - mydeque.front() + 1 > size)mydeque.pop_front();//第一个数超出了窗口，删除
		mydeque.push_back(i);
		if (i >= size-1)res.push_back(num[mydeque.front()]);//当轮询到窗口右端的值才输出
	}
	return res;
}

int main() {
	//test 1
	vector<int>num = { 2,3,4,2,6,2,5,1 };
	int size = 1;
	vector<int>res = maxInWindows(num, size);
	for (int t : res) {
		cout << t << ",";
	}
	cout << endl;
	//test end
	system("pause");
	return 0;
}