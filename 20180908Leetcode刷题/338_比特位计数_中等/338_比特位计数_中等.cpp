#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
using namespace std;

//给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
//
//示例 1:
//
//输入: 2
//输出: [0,1,1]
//示例 2:
//
//输入: 5
//输出: [0,1,1,2,1,2]
//进阶:
//
//给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
//要求算法的空间复杂度为O(n)。
//你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>>res, sub;
	vector<int>temp;
	res.push_back(temp);
	if (nums.size() == 0)
		return res;
	if (nums.size() == 1)
	{
		temp.push_back(nums[0]);
		res.push_back(temp);
		return res;
	}

	vector<int>copy = nums;
	copy.erase(copy.begin());
	sub = subsets(copy);
	for (int i = 0; i < sub.size(); ++i) {
		temp = sub[i];
		temp.insert(temp.begin(), nums[0]);
		res.push_back(temp);
		if (sub[i].size() > 0)
			res.push_back(sub[i]);
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 1,2,3 };
	vector<vector<int>>res = subsets(nums);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}