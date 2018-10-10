#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdint.h>
#include<map>
using namespace std;

//给定一个整数数组和一个整数 k, 你需要在数组里找到不同的 k-diff 数对。这里将 k-diff 数对定义为一个整数对 (i, j), 其中 i 和 j 都是数组中的数字，且两数之差的绝对值是 k.
//
//示例 1:
//输入: [3, 1, 4, 1, 5], k = 2
//输出: 2
//解释: 数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
//尽管数组中有两个1，但我们只应返回不同的数对的数量。
//
//示例 2:
//输入:[1, 2, 3, 4, 5], k = 1
//输出: 4
//解释: 数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
//
//示例 3:
//输入: [1, 3, 1, 5, 4], k = 0
//输出: 1
//解释: 数组中只有一个 0-diff 数对，(1, 1)。
//
//注意:
//数对 (i, j) 和数对 (j, i) 被算作同一数对。
//数组的长度不超过10,000。
//所有输入的整数的范围在 [-1e7, 1e7]。

int findPairs(vector<int>& nums, int k) {
	if (k < 0)
		return 0;//两数之差的绝对值不可能为负数
	int res = 0;
	sort(nums.begin(), nums.end());
	map<int, bool>hash;
	for (int i = 0; i < nums.size(); ++i) {
		if(hash.find(nums[i])!=hash.end() && hash[nums[i]]==false){
			hash[nums[i]] = true;
			res++;
		}
		if (hash.find(nums[i] + k) == hash.end())
			hash.insert(pair<int, bool>(nums[i] + k, false));
		
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 3,1,4,1,5 };
	int a = findPairs(nums, 2);

	//test2
	nums = { 1,2,3,4,5 };
	int b = findPairs(nums, 1);

	//test2
	nums = { 1,3,1,5,4 };
	int c = findPairs(nums, 0);
	cout << a << endl << b << endl << c << endl;
	//test end

	system("pause");
	return 0;
}