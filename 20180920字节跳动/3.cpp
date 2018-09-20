#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

//vector<string> test(vector<string>& vec)
//{
//	int len = vec.size();
//	vector<string> res;
//	for (int i = 0; i < len; i++)
//	{
//		res.push_back("");
//	}
//	int s = 0;
//	int flag = 0;
//	map<string, int>mymap;
//	vector<string>temp;
//	vector<int>suoyin;
//	while (flag<len)
//	{
//		s++;
//		mymap.clear();
//		for (int i = 0; i < vec.size(); ++i)
//		{
//			if (find(suoyin.begin(), suoyin.end(), i) == suoyin.end())
//			{
//				if (mymap.find(vec[i].substr(0, s)) == mymap.end())
//				{
//					mymap.insert(pair<string, int>(vec[i].substr(0, s), i));
//				}
//				else
//				{
//					mymap[vec[i].substr(0, s)] = -1;
//				}
//			}
//		}
//		if (mymap.size() > 0)
//		{
//			for (auto it = mymap.begin(); it !=mymap.end(); ++it)
//			{
//				if(it->second!=-1)	
//				{
//					suoyin.push_back(it->second);
//					res[it->second] = it->first;
//				    flag++;
//				}
//			}
//		}
//	}
//	return res;
//}

//k为第几个字符
bool findword(vector<vector<char>>& vec, vector<vector<bool>> flag,string str, int i, int j,int k)
{
	flag[i][j] = true;
	if (k==str.size()-1)
		return true;

	if (i - 1 >= 0)
	{

	}

	

	return res;
}
vector<string> test(vector<vector<char>>& vec, vector<string>& word)
{
	vector<string>res;
	vector<char> w;
	for (int i = 0; i < word.size(); ++i)
	{
		w.push_back(word[i][0]);
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec[i].size(); ++j)
		{
			for (int k = 0; k < w.size(); ++i)
			{
				if (w[k] == vec[i][j])
				{
					vector<vector<bool>> flag;
					for (int i = 0; i < vec.size(); ++i)
					{
						vector<bool>temp;
						for (int j = 0; j < vec[i].size(); ++j)
						{
							temp.push_back(false);
						}
						flag.push_back(temp);
					}

					if (findword(vec,flag, word[k], i, j,0))
						res.push_back(word[k]);
				}
			}
		}
	}
	return res;
}

void main() {
	/*vector<string>vec = {"bytedance","toutiaohao","toutiaoapp","iesaweme","iestiktok"};
	vector<string> res=test(vec);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}*/
	vector<vector<char>> vec = {
		{'p','a','b','h','m'},
	{'f','h','e','c','p'},
	{'c','i','l','l','h'},
	{'b','g','h','o','n'},
	{'h','x','c','m','l'} };
	vector<string>word = { "hello","help","high" };

	system("pause");
}
