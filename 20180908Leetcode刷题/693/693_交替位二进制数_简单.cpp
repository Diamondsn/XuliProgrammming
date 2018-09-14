#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。
//
//示例 1:
//输入 : 5
//输出 : True
//解释 :
//5的二进制数是 : 101
//
//示例 2 :
//输入 : 7
//输出 : False
//解释 :
//7的二进制数是 : 111
//
//示例 3 :
//输入 : 11
//输出 : False
//解释 :
//11的二进制数是 : 1011
//
//示例 4 :
//输入 : 10
//输出 : True
//解释 :
//10的二进制数是 : 1010

bool hasAlternatingBits(int n) {
	int flag = -1;
	for (int i = 31; i >= 0; --i)
	{
		int t=(n >> i) & 1;
		if (t == 1)
		{
			flag = i;
			break;
		}
	}

	if (flag == -1)
		return false;

	int m = n^(n>>1);

	if (m == pow(2,flag+1)-1)
		return true;
	else
		return false;
}

void main(){
	//test
	bool a = hasAlternatingBits(5);
	bool b = hasAlternatingBits(7);
	bool c = hasAlternatingBits(11);
	bool d = hasAlternatingBits(10);
	bool e = hasAlternatingBits(4);
	cout << a <<endl<< b <<endl<< c <<endl<< d << endl<<e<<endl;
	//test end
	system("pause");
}
