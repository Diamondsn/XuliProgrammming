#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

//一个网站域名，如"discuss.leetcode.com"，包含了多个子域名。作为顶级域名，常用的有"com"，下一级则有"leetcode.com"，最低的一级为"discuss.leetcode.com"。当我们访问域名"discuss.leetcode.com"时，也同时访问了其父域名"leetcode.com"以及顶级域名 "com"。
//
//给定一个带访问次数和域名的组合，要求分别计算每个域名被访问的次数。其格式为访问次数 + 空格 + 地址，例如："9001 discuss.leetcode.com"。
//
//接下来会给出一组访问次数和域名组合的列表cpdomains 。要求解析出所有域名的访问次数，输出格式和输入格式相同，不限定先后顺序。
//
//示例 1:
//输入:
//["9001 discuss.leetcode.com"]
//输出 :
//["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
// 
//说明 :
//例子中仅包含一个网站域名："discuss.leetcode.com"。按照前文假设，子域名"leetcode.com"和"com"都会被访问，所以它们都被访问了9001次。
//	   
//示例 2
//输入 :
//["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
//输出 :
//["901 mail.com", "50 yahoo.com", "900 google.mail.com", "5 wiki.org", "5 org", "1 intel.mail.com", "951 com"]
//说明 :
//按照假设，会访问"google.mail.com" 900次，"yahoo.com" 50次，"intel.mail.com" 1次，"wiki.org" 5次。
//而对于父域名，会访问"mail.com" 900 + 1 = 901次，"com" 900 + 50 + 1 = 951次，和 "org" 5 次。
//			 
//注意事项：
//cpdomains 的长度小于 100。
//每个域名的长度小于100。
//每个域名地址包含一个或两个"."符号。
// 输入中任意一个域名的访问次数都小于10000。

vector<string> subdomainVisits(vector<string>& cpdomains) {
	map<string, int> mymap;
	string str;
	int n = 0;
	for (int i = 0; i < cpdomains.size(); ++i)
	{
		str = cpdomains[i];
		n=atoi(str.substr(0, str.find(" ")).c_str());
		str = str.substr(str.find(" ") + 1);
		while (str.compare("")!=0)
		{
			auto iter = mymap.find(str);
			if (iter == mymap.end())
				mymap.insert(pair<string,int>(str,n));
			else
				(*iter).second += n;

			auto m= str.find(".");
			if (m != -1)
			{
				str = str.substr(m + 1);
			}
			else
				str = "";
		}
	}
	vector<string> result;
	string s;
	for (auto iter = mymap.begin(); iter != mymap.end(); ++iter)
	{
		s = "";
		s += to_string((iter->second)) + " " + (iter->first);
		result.push_back(s);
	}
	return result;
}

int main() {
	//test
	vector<string> vec1 = { "9001 discuss.leetcode.com" };
	vec1 = subdomainVisits(vec1);
	cout << "test1" << endl;
	for (int i = 0; i < vec1.size(); ++i)
	{
		cout << vec1[i] << endl;
	}
	cout << "test2" << endl;
	vector<string> vec2 = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
	vec2 = subdomainVisits(vec2);
	for (int i = 0; i < vec2.size(); ++i)
	{
		cout << vec2[i] << endl;
	}

	//test end
	system("pause");
	return 0;
}