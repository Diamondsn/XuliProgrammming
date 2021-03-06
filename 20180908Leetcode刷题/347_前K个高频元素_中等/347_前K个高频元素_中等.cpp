﻿#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<time.h>
#include<map>
#include<unordered_map>
#include<functional>
using namespace std;

//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//
//示例 1:
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
//
//示例 2:
//输入: nums = [1], k = 1
//输出: [1]
//
//说明：
//你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
//你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

bool mygreater(pair<int, int>a, pair<int, int>b){
	return a.second > b.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
	map<int, int>hash;
	for (int i : nums){
		hash[i]++;
	}
	//也可建立优先级队列，默认是大根堆
	vector<pair<int, int>>vec;
	for (auto it = hash.begin(); it != hash.end(); ++it){
		vec.push_back(pair<int,int>(it->first, it->second));
	}
	sort(vec.begin(), vec.end(), mygreater);
	vector<int>res;
	for (int i = 0; i < k;i++){
		res.push_back(vec[i].first);
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 1, 1, 1, 2, 2, 3 };
	vector<int>res1 = topKFrequent(nums, 2);
	for (int t : res1){
		cout << t << endl;
	}

	//test2
	cout << "test2" << endl;
	nums = { 1 };
	vector<int>res2 = topKFrequent(nums, 1);
	for (int t : res2)
	{
		cout << t << endl;
	}
	//test end
	system("pause");
	return 0;
}