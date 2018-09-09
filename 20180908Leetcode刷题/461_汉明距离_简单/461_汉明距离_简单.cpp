#include "stdafx.h"
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

//两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
//
//给出两个整数 x 和 y，计算它们之间的汉明距离。
//
//注意：
//0 =< x, y < 2^31.
//
//示例:
//输入: x = 1, y = 4
//输出 : 2
//
//解释 :
//1   (0 0 0 1)
//4   (0 1 0 0)
//↑   ↑
//
//上面的箭头指出了对应二进制位不同的位置。

int hammingDistance(int x, int y) {
	int z = x^y;
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		int m = z >> i & 1;
		if (m)
			count++;
	}
	return count;
}

int main() {
	//test
	int a = hammingDistance(1, 4);//2
	int b = hammingDistance(1577962638, 1727613287);//16
	cout << a <<","<<b<< endl;
	//test end

	system("pause");
	return 0;
}