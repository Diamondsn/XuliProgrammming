#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
using namespace std;

//给定一个表示分数加减运算表达式的字符串，你需要返回一个字符串形式的计算结果。 
//这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，
//你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2 应该被转换为 2/1。
//
//示例 1:
//输入:"-1/2+1/2"
//输出: "0/1"
//
//示例 2:
//输入:"-1/2+1/2+1/3"
//输出: "1/3"
//
//示例 3:
//输入:"1/3-1/2"
//输出: "-1/6"
//
//示例 4:
//输入:"5/3+1/3"
//输出: "2/1"
//
//说明:
//输入和输出字符串只包含 '0' 到 '9' 的数字，以及 '/', '+' 和 '-'。 
//输入和输出分数格式均为 ±分子/分母。如果输入的第一个分数或者输出的分数是正数，
//则 '+' 会被省略掉。
//输入只包含合法的最简分数，每个分数的分子与分母的范围是  [1,10]。 
//如果分母是1，意味着这个分数实际上是一个整数。
//输入的分数个数范围是 [1,10]。
//最终结果的分子与分母保证是 32 位整数范围内的有效整数。

//辗转相除法求解最大公约数
int zuidagongyueshu(int a, int b){
	while (b != 0){
		int temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

string fractionAddition(string expression) {
	int n = 0, d = 1, index=0, i, j;
	if (expression[0] != '-')
		expression = "+" + expression;
	while (index < expression.size()){
		for (i=index+1; i < expression.size() && expression[i] != '/'; i++);
		for (j=i+1; j < expression.size() && expression[j] != '+'&&expression[j] != '-'; ++j);
		int nn = stoi(expression.substr(index + 1,i - index - 1));
		int dd = stoi(expression.substr(i + 1, j - i - 1));
		/*int gongyueshu = zuidagongyueshu(dd, d);
		n = n*dd/gongyueshu + (expression[index] == '-' ? -1 : 1)*nn*d/gongyueshu;
		d = d*dd/gongyueshu;*/

		n = n*dd + (expression[index] == '-' ? -1 : 1)*nn*d;
		d = d*dd;
		int gongyueshu = zuidagongyueshu(abs(n), d);
		n = n / gongyueshu;
		d = d / gongyueshu;
		index = j;
	}
	int gongyueshu2 = zuidagongyueshu(abs(n), d);
	return to_string(n / gongyueshu2) + "/" + to_string(d / gongyueshu2);
}

int main() {
	//test1
	string a = "-1/2+1/2";
	string ans1 = fractionAddition(a);

	//test2
	a = "-1/2+1/2+1/3";
	string ans2 = fractionAddition(a);

	//test3
	a = "1/3-1/2";
	string ans3 = fractionAddition(a);

	//test4
	a = "5/3+1/3";
	string ans4 = fractionAddition(a);
	cout << ans1 << endl << ans2 << endl << ans3 << endl << ans4<<endl;
	//test end
	system("pause");
	return 0;
}