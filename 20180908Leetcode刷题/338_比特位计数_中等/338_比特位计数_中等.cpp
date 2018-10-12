#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
using namespace std;

//给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
//
//示例 1:
//
//输入: 2
//输出: [0,1,1]
//示例 2:
//
//输入: 5
//输出: [0,1,1,2,1,2]
//进阶:
//
//给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
//要求算法的空间复杂度为O(n)。
//你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。

//此题方法为巧法，采用动态规划，但思路较难想到
//思路分析
//十进制数　　　　　　　　二进制数　　　　　　　　1的个数
//
//　　1　　　　　　　　　　　　1　　　　　　　　　　   1
//
//　　2　　　　　　　　　　　　10　　　　　　　　　　 1
//
//　　3　　　　　　　　　　　　11　　　　　　　　　　  2 
//
//　　4　　　　　　　　　　　　100　　　　　　　　　　1
//
//　　5　　　　　　　　　　　　101　　　　　　　　　　 2
//
//　　6　　　　　　　　　　　　110　　　　　　　　　　  2
//
//　　7　　　　　　　　　　　　111　　　　　　　　　　  3
//
//看上面的一系列数字的二进制中1的个数：
//只需考虑数的最末二进制位和最末位前的位
//最末以前的位有的1的数量已经求得，只需看该数的最末位是否是1

//注意:笨办法求解一个数的1的位数应该
//int count = 0;//count代表1的个数，即答案
//while (i) {//i为要求的数
//	i = i&(i - 1);//i-1会将右边第一位1变为0，右边第一位1后所有0变成1，&操作后直接消化掉最右一位1
//	count++;
//}

vector<int> countBits(int num) {
	vector<int>res(num+1,0);
	for (int i = 1; i <= num; ++i) {
		res[i] = res[i >> 1] + (i & 1);
	}
	return res;
}

int main() {
	//test1
	vector<int>res = countBits(2);
	for (int i = 0; i < res.size(); ++i)cout << res[i] << ",";
	cout << endl;

	//test2
	res = countBits(5);
	for (int i = 0; i < res.size(); ++i)cout << res[i] << ",";
	//test end

	system("pause");
	return 0;
}