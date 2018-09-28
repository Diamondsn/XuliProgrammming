#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
using namespace std;

/********************************/
//归并排序时间复杂度
//
//最佳 :O(nLogn)
//平均 :O(nLogn)
//最差 :O(nLogn);
/********************************/

vector<int> merge(vector<int>& nums1, vector<int>& nums2)
{
	vector<int>res;
	int i1 = 0, i2 = 0;
	for (; i1 != nums1.size() || i2 != nums2.size();)
	{
		if (i2 == nums2.size() || nums1[i1] < nums2[i2])
		{
			res.push_back(nums1[i1]);
			i1++;
		}
		else if (i1 == nums1.size() || nums1[i1] >= nums2[i2])
		{
			res.push_back(nums2[i2]);
			i2++;
		}
	}
	return res;
}

//归并排序
vector<int> merge_sort(vector<int>& nums)
{
	vector<int>res;
	if (nums.size() == 0)
		return res;
	int left = 0, right = nums.size();
	if (right-left==1)
	{
		res.push_back(nums[0]);
		return res;
	}
	vector<int>leftvec, rightvec;
	int mid = (left + right) / 2;
	for (int i = 0; i < mid; ++i)
		leftvec.push_back(nums[i]);
	for (int j = mid; j < right; ++j)
		rightvec.push_back(nums[j]);

	vector<int>leftres = merge_sort(leftvec);
	vector<int>rightres = merge_sort(rightvec);

	res = merge(leftres,rightres);
	return res;
}

int main() {
	//test1
	vector<int>nums = { 10, 9, 8, 7, 6,5,4,3,2,1 };
	vector<int>res=merge_sort(nums);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}

	//test end
	system("pause");
	return 0;
}
