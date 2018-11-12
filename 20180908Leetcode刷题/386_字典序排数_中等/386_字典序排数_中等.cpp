#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<unordered_set>
#include"time.h"
using namespace std;

//在本问题中, 树指的是一个连通且无环的无向图。
//
//输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。
//
//结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。
//
//返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。
//
//示例 1：
//输入: [[1,2], [1,3], [2,3]]
//输出: [2,3]
//解释: 给定的无向图为:
//  1
// / \
//2 - 3
//
//示例 2：
//输入: [[1,2], [2,3], [3,4], [1,4], [1,5]]
//输出: [1,4]
//解释: 给定的无向图为:
//5 - 1 - 2
//    |   |
//    4 - 3
//
//注意:
//输入的二维数组大小在 3 到 1000。
//二维数组中的整数在1到N之间，其中N是输入数组的大小。

//此题使用并查集，也就是集合的查找与合并，构建邻接表表示联通关系
//以下采用方法较多
//https://www.cnblogs.com/grandyang/p/7628977.html
//以下虽采用并查集，但数组大小明显缩小
//https://blog.csdn.net/gl486546/article/details/79780126


//法1:采用较小的空间
//int find(int num, vector<int>&biao){
//	return num == biao[num] ? num : biao[num] = find(biao[num],biao);
//}
//
//vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//	vector<int>biao(edges.size() + 1);
//	for (int i =1; i < biao.size(); ++i){
//		biao[i] = i;
//	}
//	for (vector<int>edge : edges){
//		int res1 = find(edge[0], biao);
//		int res2 = find(edge[1], biao);
//		if (res1 == res2)return edge;
//		biao[res1] = res2;
//	}
//	return{};
//}

//采用并查集的另解
int find(int num, vector<int>& biao){
	while (biao[num] != -1){
		num = biao[num];
	}
	return num;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	vector<int>biao(edges.size() + 1, -1);
	for (vector<int> edge : edges){
		int res1 = find(edge[0], biao);
		int res2 = find(edge[1], biao);
		if (res1 == res2)return edge;
		biao[res1] = res2;
	}
	return{};
}

void main(){
	//test1
	vector<vector<int>>edges = { { 1, 2 }, { 1, 3 }, { 2, 3 } };
	vector<int>res1 = findRedundantConnection(edges);
	cout << "test1" << endl;
	for (int m : res1)
		cout << m << endl;

	//test2
	cout << "test2" << endl;
	edges = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 4 }, { 1, 5 } };
	res1 = findRedundantConnection(edges);
	for (int m : res1)
		cout << m << endl;
	//test end
	system("pause");
}
