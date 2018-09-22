#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<sstream>
using namespace std;

//给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。
//
//(注：分数越高的选手，排名越靠前。)
//
//示例 1:
//输入: [5, 4, 3, 2, 1]
//输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
//解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
//余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
//
//提示:
//N 是一个正整数并且不会超过 10000。
//所有运动员的成绩都不相同。

//交换两值
void Swap(vector<int>& nums, int i, int j)
{
	if (i == j)
		return;

	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

//将所有值从大到小排序
void qsort(vector<int>& nums,int m,int n)
{
	if (n<=m)
		return;

	int pivot = nums[m], i = m-1, j =n;
	Swap(nums, m, n);
	do {
		while (j>m && nums[--j] < pivot);
		while (i<n &&nums[++i] > pivot);
		Swap(nums, i, j);
	} while (i < j);
	Swap(nums, i, j);
	Swap(nums, i, n);
	qsort(nums, m, i - 1);
	qsort(nums, i + 1, n);
}

vector<string> findRelativeRanks(vector<int>& nums) {
	vector<string>res;
	for (int i = 0; i < nums.size(); ++i)
	{
		res.push_back("");
	}
	map<int, int>mymap;
	for (int i = 0; i < nums.size(); ++i)
	{
		mymap.insert(pair<int, int>(nums[i], i));
	}
	qsort(nums,0,nums.size()-1);
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i == 0)
			res[mymap[nums[i]]] = "Gold Medal";
		else if(i==1)
			res[mymap[nums[i]]] = "Silver Medal";
		else if(i==2)
			res[mymap[nums[i]]] = "Bronze Medal";
		else
		{
			stringstream ss;
			ss << i + 1;
			string t = ss.str();
			res[mymap[nums[i]]] = t;
		}
	}

	return res;
}

int main() {
	//test1
	vector<int>nums = { 5,4,6,2,1 };

	//快排测试
	/*qsort(nums, 0, 4);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << endl;
	}*/

	vector<string>res = findRelativeRanks(nums);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}