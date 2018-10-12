#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
using namespace std;

//有一个二维矩阵 A 其中每个元素的值为 0 或 1 。
//
//移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。
//
//在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
//
//返回尽可能高的分数。
//
//示例：
//输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
//输出：39
//解释：
//转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
//0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
//
//提示：
//1 <= A.length <= 20
//1 <= A[0].length <= 20
//A[i][j] 是 0 或 1

//此题采用贪心算法，如果移动或翻转一行或一列能使最后结果增大，则进行翻转
int matrixScore(vector<vector<int>>& A) {
	int res = 0;
	for (int i = 0; i < A.size(); ++i) {//行、列大小可能不等
		int temp = 0;
		for (int j = 0; j < A[i].size(); ++j)//翻转行
		{
			temp += A[i][j] * (int)pow(2, A[i].size() - 1 - j);
		}
		if (temp <(int)pow(2,A[i].size())-1 - temp)
		{
			res += ((int)pow(2, A[i].size()) - 1 - temp);
			for (int j = 0; j < A[i].size(); ++j)
				A[i][j] = !A[i][j];
		}
		else
			res += temp;
	}
	for (int i = 0; i < A[0].size(); ++i) {
		int temp = 0;
		for (int j = 0; j < A.size(); ++j)//翻转列
		{
			temp += A[j][i];
		}
		if (temp < A.size() - temp) {
			res += (A.size() - temp - temp)*(int)pow(2,A[0].size()-1-i);
			for (int j = 0; j < A.size(); ++j)
			{
				A[j][i]=!A[j][i];
			}
		}
	}
	return res;
}

int main() {
	//test1
	vector<vector<int>>A = { {0,0,1,1},{1,0,1,0},{1,1,0,0} };
	int a = matrixScore(A);

	//test2
	vector<vector<int>>B = { {0} };
	int b = matrixScore(B);
	cout << a << endl<<b<<endl;
	//test end

	system("pause");
	return 0;
}