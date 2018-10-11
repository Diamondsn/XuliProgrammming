#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//统计所有小于非负整数 n 的质数的数量。
//
//示例:
//输入: 10
//输出: 4
//解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

//判断是否是质数，只用判断整除从2到sqrt(n)(包含)的所有数
//int countPrimes(int n) {
//	if (n <= 2)return 0;
//	int res = 1;//2是质数
//	for(int i = 3; i < n; i+=2){//只考虑大于2的奇数
//		bool flag = true;
//		for (int j = 2; j <= sqrt(i); ++j){
//			if (i%j == 0){
//				flag = false;
//				break;
//			}
//		}
//		if (flag)
//		{
//			res++;
//		}
//	}
//	return res;
//}

//判断到n的质数
//优化1：只需考虑所有大于2的奇数
//优化2:判断一个数是不是质数，只需要判断它是不是能整除2到sqrt(n)的质数
//思路:用一个vector存储所有已求得质数，后续判断是不是质数时需要用到
int countPrimes(int n) {
	if (n <= 2)return 0;
	vector<int>vec = { 2 };
	for (int i = 3; i < n; i += 2){
		bool flag = true;
		for (int j = 0; vec[j]<=sqrt(i); ++j){//必须用<=，考虑i=9的情况
			if (i%vec[j] == 0){
				flag = false;
				break;
			}
		}
		if (flag)
		{
			vec.push_back(i);
		}
	}
	return vec.size();
}

int main() {
	//test1
	int a = countPrimes(10);

	//test2
	int b = countPrimes(499979);
	cout << a << endl<<b<<endl;
	//test end

	system("pause");
	return 0;
}