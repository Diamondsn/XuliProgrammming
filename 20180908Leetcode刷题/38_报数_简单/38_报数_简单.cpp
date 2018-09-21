#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//报数序列是指一个整照其中的整数的顺序进数序列，按行报数，得到下一个数。其前五项如下：
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 被读作  "one 1"  ("一个一") , 即 11。
//11 被读作 "two 1s" ("两个一"）, 即 21。
//21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
//
//给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
//
//注意：整数顺序将表示为一个字符串。
//
//示例 1:
//输入: 1
//输出: "1"
//
//示例 2:
//输入: 4
//输出: "1211"

string countAndSay(int n) {

}

int main() {
	//test1
	string a = countAndSay(1);

	//test2
	string b = countAndSay(4);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}