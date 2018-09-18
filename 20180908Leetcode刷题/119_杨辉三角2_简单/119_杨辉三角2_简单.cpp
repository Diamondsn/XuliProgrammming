#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
//
//在杨辉三角中，每个数是它左上方和右上方的数的和。
//
//示例:
//输入: 3
//输出: [1,3,3,1]
//
//进阶：
//你可以优化你的算法到 O(k) 空间复杂度吗？

//思路:
//在长度为k的数组内部，从杨辉三角的第一行开始依次计算到第k行的最终结果。
//代码中i的值是第k行，j是第j个数。j从i开始，是因为第i行共有i + 1个数字，
//从后往前计算，避免了第i - 1行计算结果被覆盖丢失。

//杨辉三角可以看成是一行行的数组
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
vector<int> getRow(int rowIndex) {
	vector<int>res;
	res.push_back(1);
	for (int i = 1; i <= rowIndex; ++i)
	{
		res.push_back(0);
	}
	for (int i = 1; i <= rowIndex; ++i)
	{
		for (int j = i; j >=1; --j)
		{
			res[j] = res[j] + res[j - 1];
		}
	}
	return res;
}

void main(){
	//test1
	vector<int> res = getRow(3);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << ",";
	}
	cout << endl;
	//test end
	system("pause");
}
