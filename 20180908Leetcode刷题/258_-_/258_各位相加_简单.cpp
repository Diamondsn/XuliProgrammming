#include<iostream>
using namespace std;

//给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
//
//示例 :
//输入 : 38
//输出 : 2
// 
//解释 : 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
//
//进阶 :
//你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？

//各个位上相加的递归版本
int addDigits_digui(int num) {
	int result = 0;
	while (num)
	{
		result+=num % 10;
		num = num / 10;
	}
	if (result < 10)
		return result;
	else
		return addDigits_digui(result);
}

//各个位上相加的循环版本
int addDigits_xunhuan(int num) {
	int result;
	do{
		result = 0;
		while (num)
		{
			result += num % 10;
			num = num / 10;
		}
		num = result;
	} while (result >= 10);

	return result;
}

//各个位上相加的非递归版本
//通过枚举发现有规律, 即若数为9的倍数, 则结果为9, 若不是则各位相加的结果为对九取余.
//假设一个四位数num = ABCD；即num=A*1000+B*100+C*10+D;
//num=A+B+C+D+(A*999+B*99+C*9)
//这样左边的数就是各位数的和，而右边的数一直都能被9整除；如果A+B+C+D大于9了，则可以再次套用上面的公式，所以对9取余即可。
int addDigits_feidigui(int num) {
	if (num == 0) return 0;
	int result = num % 9;
	if (result == 0) return 9;
}

void main(){
	//test 1
	int m=addDigits_digui(38);

	//test 2
	int t = addDigits_xunhuan(38);

	//test 3
	int n = addDigits_feidigui(38);
	cout << m<<endl<<t<<endl<<n << endl;
	//test end
	system("pause");
}
