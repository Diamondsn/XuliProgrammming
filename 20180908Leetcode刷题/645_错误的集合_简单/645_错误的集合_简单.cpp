#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdint.h>
#include<map>
using namespace std;

//集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，
//导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，
//导致集合丢失了一个整数并且有一个元素重复。
//
//给定一个数组 nums 代表了集合 S 发生错误后的结果。
//你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
//
//示例 1:
//输入: nums = [1,2,2,4]
//输出: [2,3]
//
//注意:
//给定数组的长度范围是 [2, 10000]。
//给定的数组是无序的。

vector<int> findErrorNums(vector<int>& nums) {
	int sum = 0;
	vector<int>res;
	map<int, int>hash;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (res.size()==0 && hash.find(nums[i]) == hash.end())
			hash.insert(pair<int, int>(nums[i], 1));
		else if (res.size()==0)
			res.push_back(nums[i]);
		sum += nums[i];
	}
	res.push_back(res[0] + (1 + nums.size())*nums.size() / 2-sum);
	return res;
}

void VectorBianLi(vector<int>& vec){
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
}

int main() {
	//test1
	vector<int>nums = { 1, 2, 2, 4 };
	vector<int>res = findErrorNums(nums);
	VectorBianLi(res);
	//test end

	system("pause");
	return 0;
}