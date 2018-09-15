#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
//
//示例:
//输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
//输出: 2
//解释: 
//这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
//
//注意:
//3 <= points.length <= 50.
//不存在重复的点。
// -50 <= points[i][j] <= 50.
//结果误差值在 10^-6 以内都认为是正确答案。

//此题需用到给出三点坐标求出面积的公式
// 已知三个点为(x1, y1)，(x2, y2)，(x3, y3)
//面积为A = 1 / 2 * [x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)]
double largestTriangleArea(vector<vector<int>>& points) {
	double result=0.0;
	double area;
	for (int i = 0; i < points.size(); ++i)
	{
		for (int j = i + 1; j < points.size(); ++j)
		{
			for (int k = 0; k < points.size(); ++k)
			{
				area = 0.5*(abs(points[i][0] * (points[j][1] - points[k][1]) + points[j][0] * (points[k][1] - points[i][1]) + points[k][0] * (points[i][1] - points[j][1])));
				if (result < area)
					result = area;
			}
		}
	}
	return result;
}

int main() {
	//test1
	vector<vector<int>>points = { {0,0},{0,1},{1,0},{0,2},{2,0} };
	double d=largestTriangleArea(points);
	cout << d << endl;
	//test end
	system("pause");
	return 0;
}