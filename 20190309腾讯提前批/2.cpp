#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<set>
using namespace std;
int m;
void getlast(vector<int>& a, int s){
	if (a.size() == 1){
		cout << a[0] << endl;
	}
	else
	{
		cout << a[(s + m - 1) % a.size()] << endl;
		a.erase(a.begin() + (unsigned int)(s + m - 1) % a.size());
		getlast(a, (s + m - 1) % a.size());
	}
}
int main()
{
	int n, s;
	cin >> n;
	cin >> s;
	cin >> m;
	vector<int>array(n, 0);
	for (int i = 0; i < array.size(); ++i){
		array[i] = i + 1;
	}
	getlast(array, (s - 1) % array.size());
	return 0;
}