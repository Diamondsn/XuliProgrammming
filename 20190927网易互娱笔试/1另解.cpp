#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int test(vector<pair<int, int>>&vec){
	int res = 0;
	map<pair<int, int>, int> mp;
	for (auto &p : vec)
	{
		int x1 = p.first;
		int y1 = p.second;
		for (auto &t : vec)
		{
			int x2 = t.first;
			int y2 = t.second;
			if ((x2 - x1) * (y2 - y1) <= 0)
			{
				int x3 = min(x1, x2);
				int y3 = min(y1, y2);
				if (mp.count({x3, y3}) == 0)
					mp[{x3, y3}] = 1;
			}
		}
		if (mp.count(p) == 0)
			mp[p] = 1;
	}
	res = mp.size();
	return res;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<pair<int, int>>vec;
		while (n--){
			int x, y;
			cin >> x >> y;
			vec.push_back(make_pair(x, y));
		}
		int res = test(vec);
		cout << res << endl;
	}
}

// 输入
// 5
// 4
// 1 1
// 2 2
// 3 3
// 4 4
// 4
// 1 4
// 2 3
// 3 2
// 4 1
// 4
// 2 1
// 1 2
// 3 1
// 1 3
// 5
// 1 5
// 5 1
// 5 5
// 1 1
// 5 5
// 5
// 1 3
// 1 4
// 1 2
// 1 1
// 1 5

//输出
// 4
// 10
// 5
// 4
// 5