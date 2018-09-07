//指出程序功能
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include<algorithm>
#include <deque>
using namespace std;

int  tol = 0;
int ch[10 * 10 * 2][2];
void add(int x){
	int y, k = 0;
	for (int i = 6; i >= 0; i--) {
		y = x >> i & 1;//y为
		if (ch[k][y] == 0) ch[k][y] = ++tol;
		k = ch[k][y];
	}
}

int query(int x) {
	int cur = 0;
	int k = 0, y;
	for (int i = 6; i >= 0; --i) {
		y = x >> i & 1;
		if (ch[k][y ^ 1] != 0) {
			cur |= 1 << i;
			k = ch[k][y ^ 1];
		}
		else
		{
			k = ch[k][y];
		}
	}
	return cur;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n, x;
	memset(ch, 0, sizeof(ch));
	scanf_s("%d", &n);
	add(0);
	int ans = -1;
	for (int i = 1; i <= n; ++i){
		scanf_s("%d", &x);
		add(x);
		ans = max(ans, query(x));
	}
	cout << ans << endl;
	system("pause");
}