#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<stack>
#include<queue>
#include<functional>
using namespace std;

//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，
//而不是第 k 个不同的元素。
//
//示例 1:
//输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
//
//示例 2:
//输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4
//
//说明:
//你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

//此种方法时间复杂度O(nlogn)，空间复杂度O(1)
//int findKthLargest(vector<int>& nums, int k) {
//	sort(nums.begin(), nums.end());
//	reverse(nums.begin(), nums.end());
//	return nums[k - 1];
//}

//struct greater{
//	bool operator()(int a,int b){
//		return a > b;
//	}
//};
//此种解法利用最小堆数据结构，时间复杂度O(nlogk),空间复杂度O(k)
//int findKthLargest(vector<int>& nums, int k) {
//	priority_queue<int, vector<int>, greater<int> >q;//greater<int>必须添加functional头文件
//	for (int n : nums){
//		q.push(n);
//		if (q.size() > k)
//			q.pop();
//	}
//	return q.top();
//}

//借鉴快排思想，选定轴值，将比轴值小的放在左边，比轴值大的放右边，如果轴值所在的位置正好是n-k处，则证明轴值是第K大的值
//时间复杂度O(n)，空间复杂度O(1)
//https://blog.csdn.net/lv1224/article/details/80112229
int getRes(vector<int> &nums, int k, int left, int right){
	int tmp = nums[left], n = nums.size(), tleft = left, tright = right;
	while (left<right){
		while (right>left&&nums[right]>tmp) right--;
		if (right>left){
			nums[left++] = nums[right];
		}
		while (left<right&&nums[left] <= tmp) left++;
		if (left<right) nums[right--] = nums[left];
	}
	nums[left] = tmp;
	if (left == n - k) return tmp;
	else if (left<n - k) return getRes(nums, k, left + 1, tright);
	else return getRes(nums, k, tleft, left - 1);
}
int findKthLargest(vector<int>& nums, int k) {
	int n = nums.size();
	return getRes(nums, k, 0, n - 1);
}

int main() {
	//test1
	vector<int>nums = { 3, 2, 1, 5, 6, 4 };
	int a = findKthLargest(nums,2);

	//test2
	nums = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
	int b = findKthLargest(nums,4);
	cout << a << endl<<b<<endl;
	//test end

	system("pause");
	return 0;
}