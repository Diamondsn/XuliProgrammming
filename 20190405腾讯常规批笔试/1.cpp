#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<set>
#include<algorithm>
using namespace std;

void test(vector<int>vec){
	int max = vec.size();
	int curmax = max;
	vector<int>v;
	for (int i = 0; i < vec.size(); ++i){
		v.push_back(vec[i]);
		if (vec[i] == curmax){
			sort(v.begin(), v.end());
			cout << v[v.size() - 1];
			v.erase(v.end() - 1);
			curmax--;
			while (v.size()>0 && v[v.size() - 1] == curmax){
				cout <<"s"<<v[v.size() - 1];
				v.erase(v.end() - 1);
				curmax--;
			}
		}
		 cout << endl;
	}
}
int main(){
	int t;
	cin >> t;
	vector<vector<int>>vec;
	for (int i = 0; i < t; ++i){
		int n;
		cin >> n;
		vector<int>v;
		for (int j = 0; j < n; ++j){
			int num;
			cin >> num;
			v.push_back(num);
		}
		vec.push_back(v);
	}
	for (int k = 0; k < vec.size(); ++k){
		test(vec[k]);
	}
	system("pause");
	return 0;
}


//int main(){
//	int n, k;
//	cin >> n >> k;
//	if (n < k)
//	{
//		cout << 0 << endl;
//	}
//	else
//	{
//		cout << (1 + (n - k)*(n - k)) * 2 << endl;
//	}
//	return 0;
//}

//int main(){
//	int t;
//	cin >> t;
//	for ()
//	system("pause");
//	return 0;
//}