#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//编写一个算法来判断一个数是不是“快乐数”。
//
//一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
//
//示例: 
//输入: 19
//输出: true
//解释: 
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1

bool isHappy(int n) {
	if (n <= 0)
		return false;

	vector<int>vec;
	int sum = 0;
	while ((find(vec.begin(), vec.end(), sum) == vec.end()) && (sum != 1))//前面这部分需要括号
	{
		vec.push_back(n);
		sum = 0;
		while (n > 0)
		{
			int temp = n % 10;
			n /= 10;
			sum += temp*temp;
		}
		n = sum;
	}
	if (sum == 1)
		return true;
	else
		return false;
}

void main() {
	//test
	/*bool a = isHappy(19);
	cout << a << endl;*/
	
	//test1
	bool b = isHappy(2);
	cout << b << endl;
	//test end
	system("pause");
}
