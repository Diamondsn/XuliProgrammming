#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

//给定两个整数 n 和 k，你需要实现一个数组，这个数组包含从 1 到 n 的 n 个不同整数，同时满足以下条件：
//
//1、如果这个数组是 [a1, a2, a3, ... , an] ，那么数组 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数；.
//2、如果存在多种答案，你只需实现并返回其中任意一种.
//
//示例 1:
//输入: n = 3, k = 1
//输出: [1, 2, 3]
//解释: [1, 2, 3] 包含 3 个范围在 1-3 的不同整数， 并且 [1, 1] 中有且仅有 1 个不同整数 : 1
//
//示例 2:
//输入: n = 3, k = 2
//输出: [1, 3, 2]
//解释: [1, 3, 2] 包含 3 个范围在 1-3 的不同整数， 并且 [2, 1] 中有且仅有 2 个不同整数: 1 和 2
// 
//提示:
//n 和 k 满足条件 1 <= k < n <= 104.

//此题tricky
//思路:首先把绝对值差距最大的数放进去，指导k为1，后面升序排列
//具体实现上，设置双指针分别指向末尾
vector<int> constructArray(int n, int k) {
	vector<int>res;
	int i = 1, j = n;
	while (i <= j){
		if (k > 1)res.push_back(k-- % 2 ? i++ : j--);
		else res.push_back(i++);
	}
	return res;
}

int main() {
	//test1
	vector<int>res = constructArray(3, 1);
	for (int m : res)
		cout << m << ",";

	//test2
	cout << endl << "test2" << endl;
	res = constructArray(3, 2);
	for (int m : res)
		cout << m << ",";
	cout << endl;
	//test end
	system("pause");
	return 0;
}