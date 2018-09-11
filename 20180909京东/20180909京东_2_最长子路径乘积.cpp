//����������https://blog.csdn.net/Ramay7/article/details/52103051

//��Ŀ����:
//A����n�����У����Ǽƻ��޽�n-1������Ϊ1�ĵ�·�����������У����й滮�Ѿ�������
//����ʹ��n�����л�����ͨ���ӳ���i������j���ҽ���һ��Ψһ·��
//��һ��ʩ���Ӽƻ��а����ε�·���޽�������Ҫ�������ε�·��������ͬ�ĳ���(����·���˵�)��
//���ǿ��Ի�õ����������ε�·���ȵĳ˻�������Ҫʹ��������󻯣�������ܻ�ö�������
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
const int MAX_N = 100010;

int n, total;
int head[MAX_N];
ll up[MAX_N], down[MAX_N], best[MAX_N];
ll predown[MAX_N], ppredown[MAX_N], sufdown[MAX_N], ssufdown[MAX_N];
ll prebest[MAX_N], sufbest[MAX_N];
vector<int> child;

struct Edge {
	int to, next;
}edge[MAX_N * 2];

inline void AddEdge(int from, int to)
{
	edge[total].to = to;
	edge[total].next = head[from];
	head[from] = total++;
}
//down[i]:��i��Ҷ�ӽڵ���·��,ddown:�γ�·��
//best[i]:i�����ڲ������,best���Ծ������ڵ�
void dfs(int u, int p)
{
	ll Max = 0, MMax = 0;
	int cnt = 0;
	for (int i = head[u]; i != -1; i = edge[i].next) {
		int v = edge[i].to;
		if (v == p) continue;
		dfs(v, u);
		cnt++;
		if (down[v] > Max) {
			MMax = Max;
			Max = down[v];
		}
		else if (down[v] > MMax) {
			MMax = down[v];
		}
		best[u] = max(best[u], best[v]);
	}
	if (cnt == 0) return;
	down[u] = Max + 1;
	if (cnt > 1) best[u] = max(best[u], Max + MMax + 2); //ϸ��
	else best[u] = max(best[u], Max + MMax + 1);  //ϸ��
												  //printf("down[%d] = %lld best[%d] = %lld\n", u, down[u], u, best[u]);
}

void solve()
{
	ll ans = 0;
	queue<pair<int, int> > que;
	que.push(make_pair(1, -1));
	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();
		int u = cur.first, p = cur.second;
		child.clear();
		child.push_back(0);
		for (int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if (v == p) continue;
			child.push_back(v);
		}
		int size = child.size();
		// ǰ׺down���ʹδ�,ǰ׺best���
		// predown��ppredown�������ֵܽڵ㵽���׵�·��
		prebest[0] = predown[0] = ppredown[0] = 0;
		for (int i = 1; i < size; ++i) {
			int v = child[i];
			prebest[i] = max(prebest[i - 1], best[v]);

			predown[i] = predown[i - 1], ppredown[i] = ppredown[i - 1];
			if (down[v] + 1 > predown[i]) {
				ppredown[i] = predown[i];
				predown[i] = down[v] + 1;
			}
			else if (down[v] + 1 > ppredown[i]) {
				ppredown[i] = down[v] + 1;
			}
		}

		sufdown[size] = ssufdown[size] = sufbest[size] = 0;
		for (int i = size - 1; i >= 1; --i) {
			int v = child[i];
			sufbest[i] = max(sufbest[i + 1], best[v]);

			sufdown[i] = sufdown[i + 1], ssufdown[i] = ssufdown[i + 1];
			if (down[v] + 1 > sufdown[i]) {
				ssufdown[i] = sufdown[i];
				sufdown[i] = down[v] + 1;
			}
			else if (down[v] + 1 > ssufdown[i]) {
				ssufdown[i] = down[v] + 1;
			}
		}
		//up[i]����i��i�ĸ��׵�·��
		for (int i = 1; i < size; ++i) {
			int v = child[i];
			ll outside = up[u] + max(predown[i - 1], sufdown[i + 1]);
			outside = max(outside, predown[i - 1] + ppredown[i - 1]);
			outside = max(outside, sufdown[i + 1] + ssufdown[i + 1]);
			outside = max(outside, predown[i - 1] + sufdown[i + 1]);
			outside = max(outside, prebest[i - 1]);
			outside = max(outside, sufbest[i + 1]);
			//printf("v = %d outside = %lld best[v] = %lld\n", v, outside, best[v]);
			ans = max(ans, outside * best[v]);
		}
		// predown/sufdown �������ֵܽڵ㵽���׽ڵ��·��
		// up[v]������v������u��·��
		for (int i = 1; i < size; ++i) {
			int v = child[i];
			up[v] = 1 + max(up[u], max(predown[i - 1], sufdown[i + 1]));
			que.push(make_pair(v, u));
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	while (~scanf("%d", &n)) {
		memset(head, -1, sizeof(head));
		total = 0;
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			AddEdge(u, v);
			AddEdge(v, u);
		}
		memset(down, 0, sizeof(down));
		memset(best, 0, sizeof(best));
		memset(up, 0, sizeof(up));
		dfs(1, -1);
		solve();//4
	}
	//��������
	/*6
	1 2
	2 3
    2 4
    5 4
    6 4*/
	//���Ϊ4
	system("pause");
	return 0;
}