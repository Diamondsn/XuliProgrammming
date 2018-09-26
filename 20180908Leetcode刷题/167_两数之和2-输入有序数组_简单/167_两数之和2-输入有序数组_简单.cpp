#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

//给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
//
//函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
//
//说明:
//返回的下标值（index1 和 index2）不是从零开始的。
//你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
//
//示例:
//输入: numbers = [2, 7, 11, 15], target = 9
//输出: [1,2]
//解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int>res;
	map<int, int>hash;

	for (int i = 0; i < numbers.size(); ++i)
	{
		if (hash.find(numbers[i]) == hash.end())
			hash.insert(pair<int, int>(target - numbers[i], i + 1));
		else
		{
			res.push_back(hash[numbers[i]]);
			res.push_back(i + 1);
			return res;
		}
	}
	return res;
}

int main() {
	//test1
	vector<int>numbers = { 2,7,11,15 };
	int target = 9;
	vector<int>res = twoSum(numbers, target);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}