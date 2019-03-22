#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<set>

using namespace std;



int main() {

	int n;
	cin >> n;
	vector<int>vec;
	for (int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		vec.push_back(temp);
		}

	for (int i = 1; i < n; ++i){
		int chazhi = abs(vec[0] - vec[i]);
		int shu = vec[0];
		for (int j = 1; j < i; ++j){
			int newchazhi = abs(vec[i] - vec[j]);
			if (newchazhi < chazhi){
				chazhi = newchazhi;
				shu = vec[j];
			}
		}
		cout << chazhi <<" "<< shu << endl;
	}
	
	system("pause");
	return 0;
}


