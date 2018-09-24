#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
using namespace std;

//如果数组是单调递增或单调递减的，那么它是单调的。
//
//如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。
//
//当给定的数组 A 是单调数组时返回 true，否则返回 false。
//
//示例 1：
//输入：[1,2,2,3]
//输出：true
//
//示例 2：
//输入：[6,5,4,4]
//输出：true
//
//示例 3：
//输入：[1,3,2]
//输出：false
//
//示例 4：
//输入：[1,2,4,5]
//输出：true
//
//示例 5：
//输入：[1,1,1]
//输出：true
//
//提示：
//1 <= A.length <= 50000
//-100000 <= A[i] <= 100000

bool isMonotonic(vector<int>& A) {
	if (A.size() == 0)
		return false;

	if (A.size() == 1)
		return true;
	int flag = 0;
	for (int i = 0; i < A.size()-1; ++i)
	{
		if (flag == 0 && A[i] > A[i + 1])
			flag = 1;
		else if (flag == 0 && A[i] < A[i + 1])
			flag = 2;

		if (flag == 1 && A[i] < A[i + 1])
			return false;
		if (flag == 2 && A[i] > A[i + 1])
			return false;
	}
	return true;
}

int main() {
	//test1
	vector<int>num = {1,2,2,3};
	bool a = isMonotonic(num);

	//test2
	num = { 6,5,4,4 };
	bool b = isMonotonic(num);

	//test3
	num = { 1,3,2 };
	bool c = isMonotonic(num);

	//test4
	num = { 1,2,4,5 };
	bool d = isMonotonic(num);

	//test5
	num = { 1,1,1 };
	bool e = isMonotonic(num);

	cout << a << endl << b << endl << c << endl << d << endl<<e<<endl;//
    //test end
	system("pause");
	return 0;
}
