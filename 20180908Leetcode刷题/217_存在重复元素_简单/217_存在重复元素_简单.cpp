#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

//给定一个整数数组，判断是否存在重复元素。
//
//如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
//
//示例 1:
//输入: [1,2,3,1]
//输出: true
//
//示例 2:
//输入: [1,2,3,4]
//输出: false
//
//示例 3:
//输入: [1,1,1,3,3,4,3,2,4,2]
//输出: true

bool containsDuplicate(vector<int>& nums) {
	vector<int>hash;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (find(hash.begin(), hash.end(), nums[i]) != hash.end())
			return true;
		else
			hash.push_back(nums[i]);
	}
	return false;
}

int main() {
	//test1
	vector<int>num = { 1,2,3,1 };
	bool a = containsDuplicate(num);

	//test2
	num = { 1,2,3,4 };
	bool b = containsDuplicate(num);

	//test3
	num = { 1,1,1,3,3,4,3,2,4,2 };
	bool c = containsDuplicate(num);

	cout << a << endl << b << endl << c << endl;
	//test end

	system("pause");
	return 0;
}