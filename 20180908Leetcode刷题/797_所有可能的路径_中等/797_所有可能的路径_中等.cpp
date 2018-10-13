#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给一个有 n 个结点的有向无环图，找到所有从 0 到 n-1 的路径并输出（不要求按顺序）
//
//二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点（译者注：有向图是有方向的，即规定了a→b你就不能从b→a）空就是没有下一个结点了。
//
//示例:
//输入: [[1,2], [3], [3], []] 
//输出: [[0,1,3],[0,2,3]] 
//解释: 图是这样的:
//0--->1
//|    |
//v    v
//2--->3
//这有两条路: 0 -> 1 -> 3 和 0 -> 2 -> 3.
//
//提示:
//结点的数字会在范围 [2, 15] 内。
//你可以把路径以任意顺序输出，但在路径内的结点的顺序必须保证。

vector<vector<int>>dfscore(vector<vector<int>>& graph, int cur, int target) {
	vector<vector<int>>res;
	vector<int>temp;
	for (int i = 0; i < graph[cur].size(); ++i) {
		if (graph[cur][i] == target) {
			vector<int>temp;
			temp.push_back(target);
			res.push_back(temp);
		}
		else {
			vector<vector<int>>t = dfscore(graph, graph[cur][i], target);
			if (t.size() > 0) {
				for (int j = 0; j < t.size(); ++j) {
					if (t[j].size() >= 0)
					{
						t[j].insert(t[j].begin(), graph[cur][i]);
						res.push_back(t[j]);
					}
				}
			}
		}
	}
	return res;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	vector<vector<int>>res;
	res = dfscore(graph, 0, graph.size() - 1);
	for (int i = 0; i < res.size(); ++i) {
		if (res[i].size() > 0)
			res[i].insert(res[i].begin(), 0);
	}
	return res;
}

int main() {
	//test1
	vector<vector<int>>graph, res;
	graph = { {1,2},{3},{3},{} };//此处代表0能到1,2;1能到3;2能到3,;3不能到任何一个节点
	res = allPathsSourceTarget(graph);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			if(j==0)
			    cout << res[i][j];
			else
				cout << "->"<<res[i][j];
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}