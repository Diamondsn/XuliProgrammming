#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个字符串来代表一个学生的出勤纪录，这个纪录仅包含以下三个字符：
//
//'A' : Absent，缺勤
//'L' : Late，迟到
//'P' : Present，到场
//如果一个学生的出勤纪录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
//
//你需要根据这个学生的出勤纪录判断他是否会被奖赏。
//
//示例 1:
//输入: "PPALLP"
//输出: True
//
//示例 2:
//输入: "PPALLL"
//输出: False

bool checkRecord(string s) {
	if (s.size() < 1)
		return true;

	int a = 0,l = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'A')
			a++;
		else if (s[i] == 'L')
			l++;
		
		if (l != 0 && s[i] == 'P' || s[i] == 'A')
		{
			l = 0;
		}

		if (a > 1 || l > 2)
			return false;
	}
	return true;
}

int main() {
	//test1
	bool a = checkRecord("PPALLP");

	//test2
	bool b = checkRecord("PPALLL");
	cout << a << endl << b << endl;

	//test end

	system("pause");
	return 0;
}