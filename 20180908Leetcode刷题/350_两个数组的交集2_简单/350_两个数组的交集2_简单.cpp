#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include<set>
#include<map.>
using namespace std;

//给定两个数组，编写一个函数来计算它们的交集。
//
//示例 1:
//输入: nums1 = [1,2,2,1], nums2 = [2,2]
//输出: [2,2]
//
//示例 2:
//输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出: [4,9]
//
//说明：
//输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
//我们可以不考虑输出结果的顺序。
//
//进阶:
//如果给定的数组已经排好序呢？你将如何优化你的算法？
//如果 nums1 的大小比 nums2 小很多，哪种方法更优？
//如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int>res;
	if (nums1.size() == 0 || nums2.size() == 0)return res;
	sort(nums1.begin(),nums1.end());
	sort(nums2.begin(), nums2.end());
	int i = 0, j = 0;
	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] < nums2[j])++i;
		else if(nums1[i]>nums2[j])++j;
		else {
			res.push_back(nums1[i]);
			i++; j++;
		}
	}
	return res;
}

//问题1
//排序后可直接用双指针法进行轮询

//问题2
//使用双指针法进行轮询更快，因为当遍历玩nums1较短数组时已经得出结果

//问题3
//使用map计数法统计nums1长度较短每个元素出现的此处，再依次轮询nums2，若map中有该元素，则结果中
//加入该元素，用是map计数中-1,这样可加快速度

int main() {
	//test1
	vector<int>nums1 = { 1,2,2,1 }, nums2 = {2,2};
	vector<int>res1 = intersect(nums1, nums2);
	for (int i = 0; i < res1.size(); ++i)cout << res1[i] << endl;
	
	//test2
	nums1 = { 4,9,5 };
	nums2 = { 9,4,9,8,4 };
	vector<int>res = intersect(nums1, nums2);
	for (int i = 0; i < res.size();++i)cout<<res[i]<<endl;
	//test end

	system("pause");
	return 0;
}