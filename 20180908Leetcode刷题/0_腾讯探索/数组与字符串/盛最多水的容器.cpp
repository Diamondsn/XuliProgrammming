#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
//在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//
//说明：你不能倾斜容器，且 n 的值至少为 2。
//
//图片链接
//https ://leetcode-cn.com/explore/interview/card/tencent/221/array-and-strings/903/
//图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
//
//示例:
//输入: [1,8,6,2,5,4,8,3,7]
//输出: 49

//暴力求解法
//int maxArea(vector<int>& height) {
//	int max = min(height[0], height[1]);
//	for (int i = 0; i < height.size() - 1; ++i){
//		for (int j = i + 1; j < height.size(); ++j){
//			if ((j - i)*min(height[i], height[j])>max)
//				max = (j - i)*min(height[i], height[j]);
//		}
//	}
//	return max;
//}

//使用双指针法，移动指针的策略是哪边高度小移哪边，因为高度最小的那边是决定面积的重要因素
int maxArea(vector<int>& height) {
	int res = 0,left=0,right=height.size()-1;
	while (left < right){
		res = max(res, min(height[left], height[right])*(right - left));
		height[left] < height[right] ? ++left : --right;
	}
	return res;
}

int main() {
	//test1
	vector<int>height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int a = maxArea(height);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}