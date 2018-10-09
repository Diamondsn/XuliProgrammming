#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdint.h>
#include<map>
using namespace std;

//你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
//
//给定一个数字 n，找出可形成完整阶梯行的总行数。
//
//n 是一个非负整数，并且在32位有符号整型的范围内。
//
//示例 1:
//n = 5
//硬币可排列成以下几行:
//¤
//¤ ¤
//¤ ¤
//因为第三行不完整，所以返回2.
//
//示例 2:
//n = 8
//硬币可排列成以下几行:
//¤
//¤ ¤
//¤ ¤ ¤
//¤ ¤
//因为第四行不完整，所以返回3.

int arrangeCoins(int n) {
	if (n <= 0)return 0;
	int res = 1;
	while (n >= res){
		n -= res;
		res++;
	}
	return res-1;
}

int main() {
	//test1
	int a = arrangeCoins(6);

	//test2
	int b = arrangeCoins(8);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}