#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
#include<set>
using namespace std;

//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明:
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//
//示例:
//输入:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//输出: [1,2,2,3,5,6]

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int cur = m + n - 1, i = m-1, j = n-1;
	while (j >= 0){
		nums1[cur--] = nums1[i] > nums2[j] ? nums1[i--]:nums2[j--];
	}
}

int main() {
	//test1
	/*vector<int>num1 = { 1, 2, 3, 0, 0, 0 };
	vector<int>num2 = { 2, 5, 6 };
	merge(num1, 3, num2, 3);

	for (int i = 0; i < num1.size(); ++i)
	{
		cout << num1[i] << endl;
	}*/
	//test2
	cout << "test2" << endl;
	vector<int>n1 = { 0, 0, 3, 0, 0, 0, 0, 0, 0 };
	vector<int>n2 = { -1, 1, 1, 1, 2, 3 };
	merge(n1, 3, n2, 6);
	for (int i = 0; i < n1.size(); ++i)
	{
		cout << n1[i] << endl;
	}
	//test end
	system("pause");
	return 0;
}
