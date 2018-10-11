#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//你需要找到由两个 n 位数的乘积组成的最大回文数。
//
//由于结果会很大，你只需返回最大回文数 mod 1337得到的结果。
//
//示例:
//输入: 2
//输出: 987
//解释: 99 x 91 = 9009, 9009 % 1337 = 987
//
//说明:
//n 的取值范围为 [1,8]。

//先确定n位数的范围，然后遍历这个区间的数字。
//当n>1时，两个n位数乘积的最大回文数一定是2n位的。
//所以将当前数字的前半段反转后拼接到后面，组成一个回文数
int largestPalindrome(int n) {
	int upper = pow(10, n) - 1, lower = upper / 10;
	for (int i = upper; i > lower; --i){
		string s = to_string(i);
		string m = s + string(s.rbegin(), s.rend());
		long num = stol(m);
		for (long p = upper; p*p > num; --p){
			if (num%p == 0)
				return num % 1337;
		}
	}
	return 9;//当n=1时，答案为9
}

int main() {
	//test1
	int a = largestPalindrome(2);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}