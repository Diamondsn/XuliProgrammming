#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
#include<set>
using namespace std;

//有两种特殊字符。第一种字符可以用一比特0来表示。第二种字符可以用两比特(10 或 11)来表示。
//
//现给一个由若干比特组成的字符串。问最后一个字符是否必定为一个一比特字符。给定的字符串总是由0结束。
//
//示例 1:
//输入: 
//bits = [1, 0, 0]
//输出: True
//解释: 
//唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
//
//示例 2:
//输入: 
//bits = [1, 1, 1, 0]
//输出: False
//
//解释: 
//唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。
//
//注意:
//1 <= len(bits) <= 1000.
//bits[i] 总是0 或 1.

bool isOneBitCharacter(vector<int>& bits) {
	if (bits.size() <= 1 || bits[bits.size() - 2] == 0)return true;
	int i = 0;
	for (; i < bits.size() - 1;){
		if (bits[i] == 1)i += 2;
		else i += 1;
	}
	return i == bits.size() - 1 ?true:false;
}

int main() {
	//test1
	vector<int>vec = { 1, 0, 0 };
	bool a = isOneBitCharacter(vec);

	//test2
	vec = { 1, 1, 1, 0 };
	bool b = isOneBitCharacter(vec);
	cout << a << endl << b << endl;
	//test end
	system("pause");
	return 0;
}
