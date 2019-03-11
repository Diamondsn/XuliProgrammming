#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<set>
using namespace std;

//迷妹问题

int main()
{
	int n, v, start, end;
	while (cin >> n >> v){
		vector<pair<int, int>>fans;
		for (int i = 0; i < n; ++i){
			cin >> start >> end;
			fans.push_back(make_pair(start, end));
		}
		int maxEnd = fans.back().second + v;
		vector<int>road(maxEnd - 1, -1);
		for (auto iter = fans.begin(); iter != fans.end(); ++iter){
			start = iter->first;
			end = iter->second;
			for (int i = start; i < end; ++i)
				road[i] = 0;
		}
		vector<int>dp(fans.front().first + 1, -1);
		int curV = v;
		int i = 0;
		for (; i < road.size(); ++i){
			if (curV == 0)
				break;
			curV += road[i];
		}
		dp[0] = i;

		for (int i = 1; i < dp.size(); ++i){
			if (road[i - 1] == 0)
				dp[i] = dp[i - 1];
			else{
				int endPlace = dp[i - 1];

				while (road[endPlace++] == 0);
				dp[i] = endPlace;
			}
		}


		int ans = -1;
		for (int i = 0; i < dp.size(); ++i){
			ans = max(ans, dp[i] - i);
		}

		cout << ans << endl;
	}
	return 0;
}