#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string add(string a, string b)
{
	if (a.length() == 0)
		return b;
	if (b.length() == 0)
		return a;
	a.length()<b.length() ? a.swap(b) : a.length();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int flag = 0;
	for (int i = 0; i<a.length(); i++)
	{
		int aInt = a[i] - '0';
		int bInt = 0;
		if (i<b.length())
			bInt = b[i] - '0';
		int result = aInt + bInt + flag;
		a[i] = result % 10 + '0';
		flag = result / 10;
	}
	if (flag != 0)
	{
		a = a + (char)(flag + '0');
	}
	reverse(a.begin(), a.end());
	return a;
}
string multiply(std::string strMultiplierA, char x)
{
	int b = x - '0';
	int flag = 0;
	for (int i = strMultiplierA.length() - 1; i >= 0; i--)
	{
		int a = strMultiplierA[i] - '0';
		int result = a*b + flag;
		strMultiplierA[i] = result % 10 + '0';
		flag = result / 10;
	}
	if (flag != 0)
		strMultiplierA = (char)(flag + '0') + strMultiplierA;
	while (strMultiplierA.length()>1 && strMultiplierA[0] == '0')
		strMultiplierA = strMultiplierA.substr(1, strMultiplierA.length());
	return strMultiplierA;
}

/*****************************************************************************
Prototype    : multiply
Description  : 两个任意长度的长整数相乘, 输出结果
Input Param  :
const std::string strMultiplierA  乘数A
const std::string strMultiplierB  乘数B
Output       :
std::string strRst            乘法结果
Return Value :
int                       0  正确
-1  异常
*****************************************************************************/
int multiply(const std::string strMultiplierA, const std::string strMultiplierB, std::string &strRst)
{

	/* 在这里实现功能 */
	if (strMultiplierA.length() <= 0 || strMultiplierB.length() <= 0)
		return -1;
	bool flag = false;//false"+"  true"-"
	string strA = strMultiplierA, strB = strMultiplierB;
	if (strMultiplierA[0] == '-')
	{
		flag = ~flag;
		strA = strMultiplierA.substr(1, strMultiplierA.length());
	}
	if (strMultiplierB[0] == '-')
	{
		flag == true ? flag = false : flag = true;
		strB = strMultiplierB.substr(1, strMultiplierB.length());
	}

	for (int i = strB.length() - 1; i >= 0; i--)
	{
		string result = multiply(strA, strB[i]);
		int j = i;
		while (++j<strB.length())
			result = result + "0";
		//	while(result.length()>1&&result[0]=='0')
		//		result=result.substr(1,result.length());
		strRst = add(strRst, result);
	}
	while (strRst.length()>1 && strRst[0] == '0')
		strRst = strRst.substr(1, strRst.length());
	if (flag == true && strRst != "0")
		strRst = '-' + strRst;
	return 0;
}

int main()
{
	std::string strResult = "";

	multiply("20000000000000000000","30000000000000000000",strResult);

	cout << strResult << endl;
	system("pause");
}
