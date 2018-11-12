#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<unordered_set>
#include"time.h"
using namespace std;

//给定一个整数 n, 返回从 1 到 n 的字典顺序。
//
//例如，
//
//给定 n = 1 3，返回[1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9] 。
//
//请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5, 000, 000。

//https://blog.csdn.net/jackzhang_123/article/details/78727180
//佩服，极为简洁，维护的迭代变量也少
vector<int> lexicalOrder(int n) {
	vector<int> res(n, 0);
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		res[i] = cur;
		if (cur * 10 <= n)
			cur *= 10;
		else
		{
			if (cur >= n)
				cur /= 10;
			cur += 1;
			while (cur % 10 == 0)
				cur /= 10;
		}
	}
	return res;
}

void main(){
	//test1
	vector<int>res = lexicalOrder(100);
	cout << "res个数为" << res.size() << endl;
	for (int i : res){
		cout << i << endl;
	}
	//test end
	system("pause");
}
