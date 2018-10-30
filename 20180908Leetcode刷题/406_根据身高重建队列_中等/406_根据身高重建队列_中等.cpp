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

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {


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