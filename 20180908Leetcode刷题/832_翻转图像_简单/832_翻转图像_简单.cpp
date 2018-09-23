#include<string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。
//
//水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转[1, 1, 0] 的结果是[0, 1, 1]。
//
//反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转[0, 1, 1] 的结果是[1, 0, 0]。
//
//示例 1:
//
//输入: [[1, 1, 0], [1, 0, 1], [0, 0, 0]]
//输出 : [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
//解释 : 首先翻转每一行 : [[0, 1, 1], [1, 0, 1], [0, 0, 0]]；
//然后反转图片 : [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
//	
//示例 2 :
//
//输入 : [[1, 1, 0, 0], [1, 0, 0, 1], [0, 1, 1, 1], [1, 0, 1, 0]]
//输出 : [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]
//解释 : 首先翻转每一行 : [[0, 0, 1, 1], [1, 0, 0, 1], [1, 1, 1, 0], [0, 1, 0, 1]]；
//然后反转图片 : [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]
//	
//说明 :
//
//1 <= A.length = A[0].length <= 20
//0 <= A[i][j] <= 1

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	for (int i = 0; i < A.size(); ++i)
	{
		reverse(A[i].begin(), A[i].end());
		for (int j = 0; j < A[i].size(); ++j)
		{
			A[i][j] = (int)(!A[i][j]);
		}
	}
	return A;
}

int main() {
	//test1
	vector<vector<int>>A;
	vector<int> temp = { 1,1,0 };
	A.push_back(temp);
	temp = { 1,0,1 };
	A.push_back(temp);
	temp = { 0,0,0 };
	A.push_back(temp);
	
	vector<vector<int>>B = flipAndInvertImage(A);
	
	for (int i = 0; i < B.size(); ++i)
	{
		for(int j = 0; j < B[i].size(); ++j)
		{
			if (j == 0)
				cout << B[i][j];
			else if (j == B[i].size() - 1)
				cout <<" ,"<< B[i][j] << endl;
			else
				cout << " ," << B[i][j];
		}
	}

	//test2
	A.clear();
	temp = { 1,1,0,0 };
	A.push_back(temp);
	temp = { 1,0,0,1 };
	A.push_back(temp);
	temp = { 0,1,1,1 };
	A.push_back(temp);
	temp = { 1,0,1,0 };
	A.push_back(temp);

	B.clear();
	B= flipAndInvertImage(A);

	for (int i = 0; i < B.size(); ++i)
	{
		for (int j = 0; j < B[i].size(); ++j)
		{
			if (j == 0)
				cout << B[i][j];
			else if (j == B[i].size() - 1)
				cout << " ," << B[i][j] << endl;
			else
				cout << " ," << B[i][j];
		}
	}
	//test end

	system("pause");
	return 0;
}