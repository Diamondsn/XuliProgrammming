#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
#include<stdint.h>
using namespace std;

//题目描述
//给定一个含有 n 个正数的数组 x。从点 (0,0) 开始，先向北移动 x[0] 米，然后向西移动 x[1] 米，向南移动 x[2] 米，向东移动 x[3] 米，持续移动。
//也就是说，每次移动后你的方位会发生逆时针变化。
//
//编写一个 O(1) 空间复杂度的一趟扫描算法，判断你所经过的路径是否相交。
//
//示例 1:
//输入: [2,1,1,2]
//?????
//?   ?
//???????>
//    ?
//输出: true 
//解释: 路径交叉了
//
//示例 2:
//输入: [1,2,3,4]
//????????
//?      ?
//?
//?
//?????????????>
//输出: false 
//解释: 路径没有相交
//
//示例 3:
//输入: [1,1,1,1]
//?????
//?   ?
//?????>
//输出: true 
//解释: 路径相交了

//解题思路https://blog.csdn.net/cc_fys/article/details/80802491
bool isSelfCrossing(vector<int>& x) {
	int n = x.size();
	if (n <= 3)
		return false;

	for (int i = 3; i < x.size(); ++i)
	{
		if (i >= 3 && x[i] >= x[i - 2] && x[i - 1] <= x[i - 3])
			return true;
		if (i >= 4 && x[i - 1] == x[i - 3] && x[i - 2] <= x[i] + x[i - 4])
			return true;
		if (i >= 5 &&x[i-4]<x[i-2]&&x[i-1]<x[i-3]&& x[i - 2] <= x[i] + x[i - 4] && x[i - 1] + x[i - 5] >= x[i - 3])
			return true;
	}
	return false;
}

void main(){
	//test1
	vector<int>x = { 2, 1, 1, 2 };
	bool a = isSelfCrossing(x);

	//test2
	x = { 1, 2, 3, 4 };
	bool b = isSelfCrossing(x);

	//test3
	x = { 1, 1, 1, 1 };
	bool c = isSelfCrossing(x);

	cout << a << endl << b << endl << c << endl;//1,0,1
	//test end
	system("pause");
}
