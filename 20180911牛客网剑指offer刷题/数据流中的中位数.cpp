#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<set>
#include<deque>
using namespace std;

//题目描述
//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
//那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
//那么中位数就是所有数值排序之后中间两个数的平均值。
//我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

class Solution {
public:
	void Insert(int num)
	{

	}

	double GetMedian()
	{

	}

};

int main() {
	//test 1
	Solution sol = Solution();
	vector<int>num = {9,8,7,6,5,4,3,2,1};
	for (int i = 0; i < num.size(); ++i) {
		sol.Insert(num[i]);
		cout << sol.GetMedian()<<endl;
	}
	//test end
	system("pause");
	return 0;
}