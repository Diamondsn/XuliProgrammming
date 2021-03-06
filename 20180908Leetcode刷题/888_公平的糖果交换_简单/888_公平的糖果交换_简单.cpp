﻿#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
using namespace std;

//爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 块糖的大小，B[j] 是鲍勃拥有的第 j 块糖的大小。
//
//因为他们是朋友，所以他们想交换一个糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）
//
//返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。
//
//如果有多个答案，你可以返回其中任何一个。保证答案存在。
//
//示例 1：
//输入：A = [1,1], B = [2,2]
//输出：[1,2]
//
//示例 2：
//输入：A = [1,2], B = [2,3]
//输出：[1,2]
//
//示例 3：
//输入：A = [2], B = [1,3]
//输出：[2,3]
//
//示例 4：
//输入：A = [1,2,5], B = [2,4]
//输出：[5,4]
//
//提示：
//1 <= A.length <= 10000
//1 <= B.length <= 10000
//1 <= A[i] <= 100000
//1 <= B[i] <= 100000
//保证爱丽丝与鲍勃的糖果总量不同。
//答案肯定存在。

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
	vector<int>res;
	int sum1 = 0,sum2=0,sum=0;
	for (int i = 0; i < A.size(); ++i)sum1+=A[i];
	for (int i = 0; i < B.size(); ++i)sum2+=B[i];
	sum =(sum1+sum2)/2;
	for (int i = 0; i < A.size(); ++i) {
		auto it = find(B.begin(), B.end(), A[i] + sum - sum1);
		if (it != B.end()) {
			res.push_back(A[i]);
			res.push_back(*it);
			break;
		}
	}
	return res;
}

void main() {
	//test1
	vector<int>A = { 1,1 };
	vector<int>B = { 2,2 };
	vector<int>res = fairCandySwap(A, B);
	cout <<endl<< "test1" << endl;
	for (int i = 0; i < res.size(); ++i)cout << res[i] << endl;

	//test2
	A = { 1,2 };
	B = { 2,3 };
	res = fairCandySwap(A, B);
	cout <<endl<< "test2" << endl;
	for (int i = 0; i < res.size(); ++i)cout << res[i] << endl;

	//test3
	A = { 2 };
	B = { 1,3 };
	res = fairCandySwap(A, B);
	cout <<endl<< "test3" << endl;
	for (int i = 0; i < res.size(); ++i)cout << res[i] << endl;

	//test4
	A = { 1,2,5 };
	B = { 2,4 };
	res = fairCandySwap(A, B);
	cout << endl << "test4" << endl;
	for (int i = 0; i < res.size(); ++i)cout << res[i] << endl;

	//test end
	system("pause");
}
