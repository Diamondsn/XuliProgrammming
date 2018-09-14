#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdint.h>
using namespace std;

//在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。
//
//给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。
//
//重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。
//
//如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
//
//示例 1:
//
//输入: 
//nums = 
//[[1,2],
// [3,4]]
//r = 1, c = 4
//输出: 
//[[1,2,3,4]]
//解释:
//行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
//示例 2:
//
//输入: 
//nums = 
//[[1,2],
// [3,4]]
//r = 2, c = 4
//输出: 
//[[1,2],
// [3,4]]
//解释:
//没有办法将 2 * 2 矩阵转化为 2 * 4 矩阵。 所以输出原矩阵。
//注意：
//
//给定矩阵的宽和高范围在 [1, 100]。
//给定的 r 和 c 都是正数。

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
	int oldrow = nums.size();
	int oldcol = nums[0].size();
	if (oldrow*oldcol != r*c)
	{
		return nums;
	}
	vector<int> temp;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums[i].size(); ++j)
		{
			temp.push_back(nums[i][j]);
		}
	}

	vector<vector<int>>result;
	vector<int>t;
	int flag = 0;
	for (int i = 0; i < r; ++i)
	{
		t.clear();
		for (int j = 0; j < c; ++j)
		{
			t.push_back(temp[flag++]);
		}
		result.push_back(t);
	}
	return result;
}

void main(){
	//test1
	vector<vector<int>> nums;
	vector<int> temp = { 1, 2 };
	nums.push_back(temp);
	temp = { 3, 4 };
	nums.push_back(temp);
	int r = 1, c = 4;
	vector<vector<int>>result = matrixReshape(nums,r,c);
	cout << "test1" << endl;
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			if (j == 0)
			{
				cout << result[i][j];
				continue;
			}
			cout << ","<<result[i][j];
		}
		cout << endl;
	}
	//test2
	cout << "test2" << endl;
	result = matrixReshape(nums, 2, 4);
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			if (j == 0)
			{
				cout << result[i][j];
				continue;
			}
			cout << "," << result[i][j];
		}
		cout << endl;
	}
	//test end
	system("pause");
}
