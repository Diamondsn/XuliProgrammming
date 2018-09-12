#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//http://www.cnblogs.com/wmx24/p/9064134.html
//大位数字符串表示数字，计算乘积
string multiply(string num1, string num2) {
        int l1=num1.size(),l2=num2.size();
        string res(l1+l2,'0');
        if(l1==0||l2==0)
            return "";
        for(int i=l1-1;i>=0;i--){
            int add=0;
            for(int j=l2-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=res[i+j+1]+add+mul%10-'0';
                res[i+j+1]='0'+sum%10;
                add=mul/10+sum/10;
            }
            res[i]+=add;
        }
        for(int i=0;i<l1+l2;i++)
            if(res[i]!='0')
                return res.substr(i);
        return "0";
}

int main()
{
	std::string strResult = "";

	strResult=multiply("20000000000000000000","30000000000000000000");
	//结果:600000000000000000000000000000000000000
	cout << strResult << endl;
	system("pause");
}
