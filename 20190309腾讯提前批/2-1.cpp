#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<set>
#include<vector>
using namespace std;

void myadd(vector<int>&vec,int num)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		if (num < vec[i]){
			vec.insert(vec.begin() + i, num);
			return;
		}
	}
	vec.push_back(num);
	return;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>addnum;
	vector<int>getnum;
	vector<int>myvec;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		addnum.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		int temp2;
		cin >> temp2;
		getnum.push_back(temp2);
	}
	int getcishu = 1;
	int addcishu = 0;
	for (int i = 0; i < m; i++)
	{
		for (; addcishu < getnum[i]; addcishu++)
		{
			myadd(myvec, addnum[addcishu]);
		}
	}

	return 0;
}