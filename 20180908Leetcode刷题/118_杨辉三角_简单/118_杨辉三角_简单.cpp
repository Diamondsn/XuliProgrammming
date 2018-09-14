#include<iostream>
#include<vector>
#include<stack>
#include<stdint.h>
using namespace std;

//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
//
//在杨辉三角中，每个数是它左上方和右上方的数的和。
//
//示例 :
//输入 : 5
//输出 :
//   [
//	   [1],
//	  [1, 1],
//	[1, 2, 1],
//   [1, 3, 3, 1],
// [1, 4, 6, 4, 1]
//   ]

vector<vector<int>> generate(int numRows) {
	vector<vector<int>>result;
	if (numRows == 0)
		return result;
	vector<int>temp;
	temp = { 1 };
	result.push_back(temp);
	if (numRows == 1)
		return result;

	temp = { 1, 1 };
	result.push_back(temp);
	if (numRows == 2)
		return result;

	for (int i = 3; i <= numRows; ++i)
	{
		temp.clear();
		for (int j = 0; j <i; ++j)
		{
			if (j == 0 || j == i-1)
			{
				temp.push_back(1);
				continue;
			}

			temp.push_back(result[i - 2][j - 1] + result[i - 2][j]);
		}
		result.push_back(temp);
	}
	return result;
}

void main(){
	//test1
	vector<vector<int>>result;
	result = generate(5);
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
