#include<iostream>
#include<vector>
#include<stack>
#include<stdint.h>
#include<unordered_map>
using namespace std;

//给定两个数组，编写一个函数来计算它们的交集。
//
//示例 1:
//输入: nums1 = [1,2,2,1], nums2 = [2,2]
//输出: [2]
//
//示例 2:
//输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出: [9,4]
//
//说明:
//输出结果中的每个元素一定是唯一的。
//我们可以不考虑输出结果的顺序。

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, bool> myhash;
	vector<int>res;
	for (int i = 0; i < nums1.size(); ++i)
	{
		myhash[nums1[i]] = true;
	}
	for (int i = 0; i < nums2.size(); ++i)
	{
		if (myhash[nums2[i]] == true && find(res.begin(),res.end(),nums2[i])==res.end())
			res.push_back(nums2[i]);
	}
	return res;
}

void outputvector(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		if (i == 0)
			cout << vec[i];
		else
		   cout << "," << vec[i];
	}
	cout<<endl;
}
void main() {
	//test1
	vector<int>num1 = { 1,2,2,1 };
	vector<int>num2 = { 2,2 };
	vector<int>res1 = intersection(num1, num2);
	cout << "test1" << endl;
	outputvector(res1);

	//test2
	num1 = { 4,9,5 };
	num2 = { 9,4,9,8,4 };
	vector<int>res2 = intersection(num1, num2);
	cout << "test2" << endl;
	outputvector(res2);
	//test end
	system("pause");
}
