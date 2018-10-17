#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
using namespace std;

//字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。
//S 已经根据某种规则进行了排序。我们要根据S中的字符顺序对T进行排序。
//更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。
//返回任意一种符合条件的字符串T。
//
//示例:
//输入:
//S = "cba"
//T = "abcd"
//输出: "cbad"
//解释: 
//S中出现了字符 "a", "b", "c", 所以 "a", "b", "c" 的顺序应该是 "c", "b", "a". 
//由于 "d" 没有在S中出现, 它可以放在T的任意位置. "dcba", "cdba", "cbda" 都是合法的输出。
//
//注意:
//S的最大长度为26，其中没有重复的字符。
//T的最大长度为200。
//S和T只包含小写字符。

string customSortString(string S, string T) {
	string res, temp;
	map<char, int>hash;
	for (int i = 0; i < S.size(); ++i){
		hash.insert(pair<char, int>(S[i], 0));//S中的字符都是不一样的
	}
	for (int i = 0; i < T.size(); ++i){
		if (hash.find(T[i]) == hash.end())
			temp += T[i];
		else
			hash[T[i]]++;
	}
	for (int i = 0; i < S.size(); ++i){
		int num = hash[S[i]];
		while (num){
			res += S[i];
			num--;
		}
	}
	return res + temp;
}

int main() {
	//test1
	string res=customSortString("cba", "abcd");
	cout << res << endl;
	//test end

	system("pause");
	return 0;
}