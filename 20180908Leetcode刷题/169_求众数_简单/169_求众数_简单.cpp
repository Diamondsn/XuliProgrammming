#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<algorithm>
using namespace std;

//给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
//
//你可以假设数组是非空的，并且给定的数组总是存在众数。
//
//示例 1:
//输入: [3,2,3]
//输出: 3
//
//示例 2:
//输入: [2,2,1,1,1,2,2]
//输出: 2

//排序所需复杂度过高
//int majorityElement(vector<int>& nums) {
//	sort(nums.begin(), nums.end());
//	return nums[nums.size() / 2];
//}

//使用摩尔投票法：在每一轮投票过程中，从数组中找出一对不同的元素，将其从数组中删除。循环执行这一操作，直到无法再进行投票，如果数组为空，则没有任何元素出现的次数超过该数组长度的一半（无绝对众数）。如果只存在一种元素，那么这个元素则可能为绝对众数。 在编写算法的过程中，我们可以直接按照数组原来的顺序进行投票，删除。
//
//具体方法：
//
//假设number为当前阶段中超过半数的元素（候选数），count用来记录number元素出现的次数
//①一开始number为数组的第一个数，count的值为1。因为一个元素的数组，唯一的那个元素一定是绝对众数；
//②遍历数列nums，假设当前遍历的数为nums[i]；
//③如果nums[i] = number，则count++；
//④如果nums[i] != number，则需要把候选数number和当前数nums[i]同时删除，只用将count--，这样相当于忽略了nums[i]并且删除了一个候选数number。因为for循环i++后，nums[i]就会自动更新，故而不用考虑nums[i]的删除；
//⑤若count = 0，则需要重新选择候选数（表示前一阶段没有出现次数超过n / 2的元素）。假设众数绝对存在，那么绝对众数一定在剩余的数组中。故而，number为当前元素，count = 1；
//⑥若count>0，则number可能为候选数。

int majorityElement(vector<int>& nums) {
	int count=0;
	int number;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (count == 0)
		{
			number = nums[i];
			count = 1;
		}
		else if (number != nums[i])
		{
			count--;
		}
		else {
			count++;
		}
	}
	return number;
}

void main() {
	//test 1
	vector<int>nums1 = { 3,2,3 };
	vector<int>nums2 = { 2,2,1,1,1,2,2 };
	int a = majorityElement(nums1);
	int b = majorityElement(nums2);
	cout << a << endl << b << endl;
	//test end
	system("pause");
}
