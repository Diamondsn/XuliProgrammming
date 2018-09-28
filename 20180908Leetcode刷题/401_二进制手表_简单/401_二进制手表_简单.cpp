#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
using namespace std;

//二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。
//
//每个 LED 代表一个 0 或 1，最低位在右侧。
//
//例如，上面的二进制手表读取 “3:25”。
//
//给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
//
//案例:
//输入: n = 1
//返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//
//注意事项:
//输出的顺序没有要求。
//小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
//分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。

//pos代表有几个灯位，count代表需要亮几个灯
vector<int>helper(int pos,int count)
{
	vector<int>res;
	if (pos == 1 && count == 0)
	{
		res.push_back(0);
		return res;
	}
	else if (pos == 1 && count == 1)
	{
		res.push_back(1);
		return res;
	}

	vector<int>subres;
	if (count >= 1)
	{
		subres = helper(pos - 1, count - 1);//当前灯必亮
		for (int i = 0; i < subres.size(); ++i)
		{
			res.push_back(pow(2, pos - 1) + subres[i]);
		}
	}
	if (count < pos)
	{
		subres = helper(pos - 1, count);//当前灯不亮
		for (int i = 0; i < subres.size(); ++i)
		{
			res.push_back(subres[i]);
		}
	}
	return res;
}

vector<string>readBinaryWatch(int num) {
	vector<string> res;
	vector<int>hour, min;
	for (int i = 0; i <= num; ++i)
	{
		if (i <= 4 &&num - i <= 6){
			hour = helper(4,i);
			min = helper(6, num - i);
			for (int j = 0; j < hour.size(); ++j)
			{
				if (hour[j] >= 12)
					continue;
				for (int k = 0; k < min.size(); ++k)
				{
					if (min[k] >= 60)
						continue;
					stringstream ss;
					ss << hour[j];
					string hourstr=ss.str();
					ss.str("");//清空当前缓冲区
					ss << min[k];
					string minstr = ss.str().size() < 2 ? '0'+ss.str():ss.str() ;
					res.push_back(hourstr + ":" + minstr);
				}
			}
		}
	}
	return res;
}

int main() {
	//test1
	vector<string>vec = readBinaryWatch(2);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
	//test end
	system("pause");
	return 0;
}
