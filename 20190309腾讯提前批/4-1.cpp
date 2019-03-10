#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<set>
using namespace std;

int main()
{
	int n, v;
	cin >> n >> v;
	vector<int>vec;
	int t1, t2;
	cin >> t1 >> t2;
	vec.push_back(t1 - 1);
	vec.push_back(t2 - t1 + 1);
	int last = t2;
	for (int i = 1; i < n; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		
		vec.push_back(temp1-last-1);
		vec.push_back(temp2-temp1+1);
		last = temp2;
	}

	return 0;
}