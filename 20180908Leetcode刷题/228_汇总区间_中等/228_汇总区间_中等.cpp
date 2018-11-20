#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<deque>
#include<functional>
using namespace std;

//给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
//
//示例 1:
//输入: [0,1,2,4,5,7]
//输出: ["0->2","4->5","7"]
//解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
//
//示例 2:
//输入: [0,2,3,4,6,8,9]
//输出: ["0","2->4","6","8->9"]
//解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。

vector<string> summaryRanges(vector<int>& nums) {
	if (nums.size()<=0)return{};
	int before = nums[0],after=nums[0];
	vector<string>res;
	for (int i = 1; i < nums.size(); ++i){
		if (nums[i] == after + 1){
			after = nums[i];
		}
		else{
			if (after == before){
				res.push_back(to_string(after));
			}
			else{
				res.push_back(to_string(before)+"->"+to_string(after));
			}
			before = nums[i];
			after = nums[i];
		}
	}
	if (after == before){
		res.push_back(to_string(after));
	}
	else{
		res.push_back(to_string(before) + "->" + to_string(after));
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 0, 1, 2, 4, 5, 7 };
	vector<string>res = summaryRanges(nums);
	for (string str : res){
		cout << str << endl;
	}

	//test2
	cout << endl << "test2" << endl;
	nums = { 0, 2, 3, 4, 6, 8, 9 };
	res = summaryRanges(nums);
	for (string str : res){
		cout << str << endl;
	}
	//test end

	system("pause");
	return 0;
}