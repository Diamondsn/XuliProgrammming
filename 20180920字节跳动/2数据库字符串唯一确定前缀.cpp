#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

//题目描述:
//数据库里的每条数据可以抽象成一个仅由小写字母构成的字符串。
//现在相对于这些字符串建立前缀表示，产生的表示可以唯一确定一条
//数据且产生前缀表示的总字符数最少。
//输入数据确保没有一个字符串是另一个字符串的前缀。
//例如:对于两个字符串:
//abcdefg
//abccfeg
//我们乐意取这样的前缀作为每一个字符串的标识:
//abcd
//abcc
//并可以方便的证明，这种前缀表示的方式总字符数最少。

//输入描述
//输入文件的第一行包含一个正整数N，表示字符串的数目。之后N行，每行
//一个字符串，表示单词。

//示例1
//输入
//5
//bytedance
//toutiaohao
//toutiaoapp
//iesaweme
//iestiktok
//输出
//b
//toutiaoh
//toutiaoa
//iesa
//iest

vector<string> test(vector<string>& vec)
{
	int len = vec.size();
	vector<string> res;
	for (int i = 0; i < len; i++)
	{
		res.push_back("");
	}
	int s = 0;
	int flag = 0;
	map<string, int>mymap;
	vector<string>temp;
	vector<int>suoyin;
	while (flag<len)
	{
		s++;
		mymap.clear();
		for (int i = 0; i < vec.size(); ++i)
		{
			if (find(suoyin.begin(), suoyin.end(), i) == suoyin.end())
			{
				if (mymap.find(vec[i].substr(0, s)) == mymap.end())
				{
					mymap.insert(pair<string, int>(vec[i].substr(0, s), i));
				}
				else
				{
					mymap[vec[i].substr(0, s)] = -1;
				}
			}
		}
		if (mymap.size() > 0)
		{
			for (auto it = mymap.begin(); it !=mymap.end(); ++it)
			{
				if(it->second!=-1)	
				{
					suoyin.push_back(it->second);
					res[it->second] = it->first;
				    flag++;
				}
			}
		}
	}
	return res;
}

void main() {
	vector<string>vec = {"bytedance","toutiaohao","toutiaoapp","iesaweme","iestiktok"};
	vector<string> res=test(vec);
	for (int i = 0; i < res.size(); ++i)
	{
	cout << res[i] << endl;
	}
	system("pause");
}