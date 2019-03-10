#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<set>
using namespace std;

int huan(vector<int>&vec, int s, int m,int& suoyin)
{
	if (vec.size() == 1)
		return vec[0];
	suoyin = (s + 1 + m) % vec.size();
	int result = vec[suoyin];
	vec.erase(vec.begin() + suoyin);
	suoyin = suoyin%vec.size();
	return result;
}

int main() {
	//test1
	int n, s, m;
	cin >> n >> s >> m;
	vector<int>vec(n);
	vector<int>res;
	for (int i = 0; i < n; ++i){
		vec[i] = i + 1;
	}
	int count = n;
	
	int suoyin = s;
	for (int i = 0; i < n; ++i)
	{
		int secondsuoyin;
		int temp = huan(vec, suoyin, m, secondsuoyin);
		res.push_back(temp);
	}
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	//test end
	return 0;
}