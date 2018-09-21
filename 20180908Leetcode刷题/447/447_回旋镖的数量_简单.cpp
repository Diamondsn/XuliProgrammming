#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
using namespace std;

//给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，
//其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
//
//找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
//
//示例:
//输入:
//[[0,0],[1,0],[2,0]]
//输出:
//2
//
//解释:
//两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]

//O(n^3)时间复杂度
//int numberOfBoomerangs(vector<pair<int, int>>& points) {
//	int sum = 0;
//	for (int i = 0; i < points.size(); ++i)
//	{
//		for (int j = i+1; j < points.size(); ++j)
//		{
//			for (int k = j+1; k < points.size(); ++k)
//			{
//				if ((points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second)==
//					(points[i].first - points[k].first)*(points[i].first - points[k].first) + (points[i].second - points[k].second)*(points[i].second - points[k].second))
//					sum += 2;
//				if ((points[j].first - points[i].first)*(points[j].first - points[i].first) + (points[j].second - points[i].second)*(points[j].second - points[i].second) ==
//					(points[j].first - points[k].first)*(points[j].first - points[k].first) + (points[j].second - points[k].second)*(points[j].second - points[k].second))
//					sum += 2;
//				if ((points[k].first - points[j].first)*(points[k].first - points[j].first) + (points[k].second - points[j].second)*(points[k].second - points[j].second) ==
//					(points[k].first - points[i].first)*(points[k].first - points[i].first) + (points[k].second - points[i].second)*(points[k].second - points[i].second))
//					sum += 2;
//			}
//		}
//	}
//	return sum;
//}

//使用记录距离的方法即可，将两点的距离记录在map中，统计同样距离的点的个数，即可排列组合得出最后排列数目
//此方法的时间复杂度为O(n^2)，时间比暴力轮询短了许多
int numberOfBoomerangs(vector<pair<int, int>>& points) {
	int sum = 0;
	unordered_map<int, int> mymap;
	for (int i = 0; i < points.size(); ++i)
	{
		mymap.clear();
		for (int j = 0; j < points.size(); ++j)
		{
			if (i != j){
				int dis = ((points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second));
				mymap[dis] ++;
			}
		}
		for (auto it = mymap.begin(); it != mymap.end(); ++it)
		{
			if (it->second >= 2)
			{
				sum += (it->second)*(it->second - 1);
			}
		}
	}
	return sum;
}

int main() {
	//test1
	vector<pair<int, int>> points = { { 0, 0 }, { 1, 0 }, { 2, 0 } };
	int a = numberOfBoomerangs(points);
	cout << a << endl;

	//test end

	system("pause");
	return 0;
}
