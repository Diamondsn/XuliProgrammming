#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//有1000只水桶，其中有且只有一桶装的含有毒药，其余装的都是水。它们从外观看起来都一样。如果小猪喝了毒药，它会在15分钟内死去。
//
//问题来了，如果需要你在一小时内，弄清楚哪只水桶含有毒药，你最少需要多少只猪？
//
//回答这个问题，并为下列的进阶问题编写一个通用算法。
//
//进阶:
//
//假设有 n 只水桶，猪饮水中毒后会在 m 分钟内死亡，你需要多少猪（x）就能在 p 分钟内找出“有毒”水桶？n只水桶里有且仅有一只有毒的桶。

//先看1只小猪，60分钟的话，它最多可以判断出 60/15+1 = 5只水桶中的毒药桶。
//每隔十五分钟喝一次水，喝四次，如果幸运的话活了下来，就是最后一桶。
//
//再接着看2只小猪，60分钟，它最后可以判断出25只水桶，可以这样：
//
//00     01     02     03      04
//
//10     11     12     13      14
//
//20     21     22     23      24
//
//30     31     32     33      34
//
//40     41     42     43      44
//
//将桶像上面摆放，第一只猪猪喝掉第一二三四五混合后的水，每隔15分钟喝一次，
//这样如果不幸运，在x行被毒死了，则证明毒药在第x行，幸运活下来的话，则毒药在第五行；
//在第一只猪猪和的同时让第二只猪猪喝第一二三四列混合后的水，如果在y列被毒死，则毒药在第y列，
//如果活下来，则毒药在第五列。这样第一只猪猪判断出了横坐标x，第二只猪猪判断出来纵坐标y，则可以知道哪桶水有毒。
//
//以此类推，1只小猪5^1,  2只小猪5^2，  3只小猪5^3,  4只小猪5^4  ，5只小猪5^5……
//
//本文来自 Pi_dan 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/qq_38595487/article/details/81435247?utm_source=copy 

//结果相当于求minutesToTest / minutesToDie + 1为基数的最少能用多少位来表达buckets。
//
//本文来自 quekai01 的CSDN 博客 ，全文地址请点击：https ://blog.csdn.net/quekai01/article/details/82694082?utm_source=copy 

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
	if (buckets == 1)
		return 0;

	int times = minutesToTest / minutesToDie+1;
	int res = 1;
	while (pow(times, res) < buckets)
		res++;

	return res;
}

int main() {
	//test1
	int a = poorPigs(1000, 15, 60);
	cout << a << endl;

	//test end

	system("pause");
	return 0;
}