#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。
//
//示例1:
//输入: 5
//输出: True
//解释: 1 * 1 + 2 * 2 = 5
// 
//示例2:
//输入: 3
//输出: False

bool judgeSquareSum(int c) {
	if (c < 0)return false;
	int left = 0, right = sqrt(c);
	while (left <= right){
		int temp = left*left + right*right;
		if (temp == c)
			return true;
		else if (temp > c)
			right--;
		else
			left++;
	}
	return false;
}

int main() {
	//test1
	bool a = judgeSquareSum(5);

	//test2
	bool b = judgeSquareSum(3);

	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}