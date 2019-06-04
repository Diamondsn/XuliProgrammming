/*
小v负责一次活动礼品采购，每一款礼品的受欢迎程度（热度值）各不相同。现给出总金额以及
各礼品的单价和热度值，且每个礼品只采购一个，如何购买可以使得所有礼品的总热度值最高。
输入：
第一行是一个正整数，表示总金额（不大于1000）
第二行是一个长度为n的正整数数组，表示礼品单价（n不大于100）
第三行是一个长度为n的正整数数组，表示对应礼品热度值
输出：
一个正整数，表示可获得的最高热度值

样例输入：1000
         200 600 100 180 300 450
         6 10 3 4 5 8
样例输出：21
*/

//author:徐力

#include <iostream>
using namespace std;
#define ARRAY_MAX 1000

void inner(int prices[], int vals[], int len, int total, int cur, int sum, int &max){
	if (cur >= len || total <= 0){
		if (sum > max){
			max = sum;
		}
	}
	else{
		inner(prices, vals, len, total, cur + 1, sum, max);

		if (total >= prices[cur]){
			inner(prices, vals, len, total - prices[cur], cur + 1, sum + vals[cur], max);
		}
	}
}
int findBest(int prices[], int vals[], int len, int total){
	int max = INT_MIN;
	int sum = 0;
	inner(prices, vals, len, total, 0, sum, max);

	return max;
}
int main(void){
	int total = 0, vMax = 0, index = 0, i = 0;
	int prices[ARRAY_MAX] = { 0 };
	int vals[ARRAY_MAX] = { 0 };

	cin >> total;

	do{
		cin >> prices[index++];
	} while (cin.get() != '\n');
	do{
		cin >> vals[i++];
	} while (cin.get() != '\n');

	vMax = findBest(prices, vals, index, total);
	cout << vMax << endl;
	system("pause");
}