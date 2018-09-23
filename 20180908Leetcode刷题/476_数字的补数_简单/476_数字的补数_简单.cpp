#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。
//
//注意 :
//
//给定的整数保证在32位带符号整数的范围内。
//你可以假定二进制数不包含前导零位。
//示例 1 :
//输入 : 5
//输出 : 2
//解释 : 5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2。
//
//示例 2 :
//输入 : 1
//输出 : 0
//解释 : 1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0。

int findComplement(int num) {
	int flag = 0;
	int result = 0;
	for (int i = 31; i >= 0; --i)
	{
		int a = num >> i & 1;
		if (a == 1)
		{
			flag = 1;
		}
		if (flag && a == 0)
		{
			//求解2的n次方
			//1解，使用pow函数
			//result += pow(2,i);
			//2解,使用左移
			result += (1 << i);
		}
	}
	return result;
}

int main() {
	//test
	int a = findComplement(5);//2
	int b = findComplement(1);//0
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}