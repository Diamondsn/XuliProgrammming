#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<map>
#include<list>
using namespace std;

//假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，
//其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。
//
//注意：
//总人数少于1100人。
//
//示例
//输入:
//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//输出:
//[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

//排序原则:身高降序排列，在身高相同的情况下，k升序排列
//排序方法返回正值时，a在b的前面，返回负值，a在b的后面
//参考https://blog.csdn.net/Viewz/article/details/81412232
//bool paixu(pair<int, int>a, pair<int, int>b){
//	if (a.first == b.first)return a.second < b.second;
//	else return a.first > b.first;
//}
//
//vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
//	sort(people.begin(), people.end(), paixu);
//	vector<pair<int, int>>res(people.size());
//	for (int i = 0; i < people.size(); ++i){
//		res.insert(res.begin() + people[i].second, people[i]);
//	}
//	res.resize(people.size());
//	return res;
//}

//排序函数还可以这么写
//https://blog.csdn.net/w8253497062015/article/details/79946558
vector<pair<int, int>>reconstructQueue(vector<pair<int, int>>&people){
	sort(people.begin(), people.end(), [](pair<int, int>a, pair<int, int>b){
		return a.first > b.first || (a.first == b.first && a.second < b.second);
	});
	vector<pair<int, int>>res;
	for (pair<int,int>p:people){
		res.insert(res.begin() + p.second, p);
	}
	return res;
}


int main() {
	//test1
	vector<pair<int, int>>people = { {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2} };
	vector<pair<int, int>>res = reconstructQueue(people);
	for (pair<int, int>p : res){
		cout << p.first << "," << p.second << endl;
	}
	//test end

	system("pause");
	return 0;
}