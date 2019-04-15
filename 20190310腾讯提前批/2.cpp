

#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<set>

using namespace std;

int getMin(int time1, int time2, int time3) {
	int min = time1;
	if (min > time2) {
		min = time2;
	}
	if (min > time3) {
		min = time3;
	}
	return min;
}

int compute(vector<int>&height, bool b, int now, int has) {
	if (now >= height.size() - 1) {
		return has;
	}
	if (b) {//可以跳
		//选择跳1
		int time1 = compute(height, false, now + 1, has);
		//选择跳2
		int time2 = compute(height, false, now + 2, has);
		//爬
		int time3 = compute(height, true, now + 1, height[now + 1] + has);
		int min = getMin(time1, time2, time3);
		return min;
	}
	else {//只能爬
		return compute(height, true, now + 1, height[now + 1] + has);
	}
}



int main() {
		
		int n;
		cin >> n;
		vector<int>height(n + 1);
		height.push_back(0);
		for (int i = 0; i < n; ++i){
			int temp;
			cin >> temp;
			height.push_back(temp);
		}

		
		int minTime = compute(height, true, 0, 0);
		cout << minTime << endl;
		system("pause");
		return 0;
	}


