#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;

//给定一个没有重复数字的序列，返回其所有可能的全排列。
//
//示例:
//输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//]

//调用下一个枚举的库函数，属于作弊方法
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());//必须排序
	//函数next_permutation()是按照字典序产生排列的，并且是从数组中当前的字典序开始依次增大直至到最大字典序。
	do {
		res.push_back(nums);
	} while (next_permutation(nums.begin(), nums.end()));//最终不会变为它自己原来本身，所以用do-while循环
	return res;
}

//vector<vector<int>> permute(vector<int>& nums) {
//	vector<vector<int>>res,tempres;
//	if (nums.size() == 1)
//	{
//		res.push_back(nums);
//		return res;
//	}
//	for (int i=0; i < nums.size(); ++i) {
//		vector<int> temp = nums;
//		temp.erase(temp.begin() + i);
//		tempres = permute(temp);
//		for (int j = 0; j < tempres.size(); ++j) {
//			tempres[j].insert(tempres[j].begin(), nums[i]);
//			res.push_back(tempres[j]);
//		}
//	}
//	return res;
//}

int main() {
	//test1
	vector<int>nums = {0,-1,1};
	vector<vector<int>>res = permute(nums);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j<res[i].size(); ++j) {
			cout << res[i][j] << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}