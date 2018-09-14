#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdint.h>
using namespace std;

//给定一个正整数 N，找到并返回 N 的二进制表示中两个连续的 1 之间的最长距离。 
//如果没有两个连续的 1，返回 0 。
//
//示例 1：
//输入：22
//输出：2
//解释：
//22 的二进制是 0b10110 。
//在 22 的二进制表示中，有三个 1，组成两对连续的 1 。
//第一对连续的 1 中，两个 1 之间的距离为 2 。
//第二对连续的 1 中，两个 1 之间的距离为 1 。
//答案取两个距离之中最大的，也就是 2 。
//
//示例 2：
//输入：5
//输出：2
//解释：
//5 的二进制是 0b101。
//
//示例 3：
//输入：6
//输出：1
//解释：
//6 的二进制是 0b110。
//
//示例 4：
//输入：8
//输出：0
//解释：
//8 的二进制是 0b1000。
//在 8 的二进制表示中没有连续的 1，所以返回 0 。
//
//提示：
//1 <= N <= 10^9

int binaryGap_1(int N) {
	int result;
	vector<int> vec;
	for (int i = 31; i >= 0; --i)
	{
		int temp = (N >> i) & 1;
		if (temp == 1)
			vec.push_back(i);
	}
	if (vec.size() <= 1)
		result = 0;
	else
	{
		int max = 0;
		for (int i = 0; i < vec.size(); ++i)
		{
			if (i == vec.size() - 1)
				continue;

			if (max < abs(vec[i] - vec[i + 1]))
				max = abs(vec[i] - vec[i + 1]);
		}
		result=max;
	}

	return result;
}

//另解,不存储所有为1的位，只存储最后一个为1的位和差值;
int binaryGap(int N)
{
	int result = 0;
	int last = -1;
	for (int i = 0; i < 32; ++i)
	{
		if ((N >> i) & 1 > 0)
		{
			if (last >= 0)
				result = result < (abs(i - last)) ? abs(i - last) :result ;
			last = i;
		}
	}
	return result;
}

void main() {
	//test1
	int a = binaryGap(22);
	int b = binaryGap(5);
	int c = binaryGap(6);
	int d = binaryGap(8);
	cout << a<<endl << b<<endl << c << endl<<d<<endl;//2 2 1 0
	//test end
	system("pause");
}
