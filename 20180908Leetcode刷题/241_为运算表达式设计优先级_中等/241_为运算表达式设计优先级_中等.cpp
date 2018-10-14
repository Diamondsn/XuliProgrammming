#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;

//给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。
//
//示例 1:
//输入: "2-1-1"
//输出: [0, 2]
//解释: 
//((2-1)-1) = 0 
//(2-(1-1)) = 2
//
//示例 2:
//输入: "2*3-4*5"
//输出: [-34, -14, -10, -10, 10]
//解释: 
//(2*(3-(4*5))) = -34 
//((2*3)-(4*5)) = -14 
//((2*(3-4))*5) = -10 
//(2*((3-4)*5)) = -10 
//(((2*3)-4)*5) = 10

//初始思路:集中在第一个数字和第一个运算符上，但是优先级运算的本质最终只是由一个运算符链接
//正确思路:集中在运算符上，每一个运算符上左右两边的结果排列组合即为最终结果
//分治算法应该集中在如何简化为相似但规模更小的问题上
vector<int> diffWaysToCompute(string input) {
	vector<int>res;
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
			vector<int>left = diffWaysToCompute(input.substr(0, i));
			vector<int>right = diffWaysToCompute(input.substr(i + 1));
			for (int m = 0; m < left.size(); ++m) {
				for (int n = 0; n < right.size(); ++n) {
					if (input[i] == '+')
						res.push_back(left[m] + right[n]);
					else if (input[i] == '-')
						res.push_back(left[m] - right[n]);
					else if (input[i] == '*')
						res.push_back(left[m] * right[n]);
				}
			}
		}
	}
	if (res.size() == 0)
		res.push_back(stoi(input));//最终迭代时input里没有运算符
	return res;
}

int main() {
	//test1
	vector<int>res = diffWaysToCompute("2-1-1");
	for (int i = 0; i < res.size(); ++i)cout << res[i] << endl;

	//test2
	res = diffWaysToCompute("2*3-4*5");
	cout << "test2" << endl;
	for (int i = 0; i < res.size(); ++i)cout << res[i] << endl;
	//test end

	system("pause");
	return 0;
}