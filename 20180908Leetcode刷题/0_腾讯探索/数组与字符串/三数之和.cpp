#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
//使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
//例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//满足要求的三元组集合为：
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]

//hash是引用传递
//h是值传递，只一轮有效，不能全局共享
//以下方法超出时间限制
//void dfs(vector<vector<int>>&res, vector<int>&path, set<pair<int,int>> &hash,set<int> h,vector<int>& nums,int cur,int count,int target){
//	if (count == 3 && target == 0){
//		res.push_back(path);
//	}
//	else if (count >= 3)
//		return;
//	else{
//		for (int i = cur; i < nums.size() - 2+ count; ++i){
//			if (path.size() == 1){
//				if (hash.find(pair<int,int>(path[0],nums[i])) != hash.end())
//					continue;
//				else
//					hash.insert(pair<int,int>(path[0],nums[i]));
//			}
//			else if (path.size() == 2){
//				if (h.find(nums[i]) != h.end())
//					continue;
//				else
//					h.insert(nums[i]);
//			}
//			path.push_back(nums[i]);
//			dfs(res, path,hash,h, nums,i + 1, count + 1, target- nums[i]);
//			path.pop_back();
//		}
//	}
//}
//
//vector<vector<int>> threeSum(vector<int>& nums) {
//	vector<int>path;
//	vector<vector<int>>res;
//	if (nums.size() < 3)return res;//加判断
//	set<pair<int,int>>hash;//此set作用是防止答案中包括重复的三元组，先排序，记录所有插入的前两个值
//	set<int>h;//防止在前两个值固定的情况下搜索第三个数出现两个相同的
//	sort(nums.begin(), nums.end());
//	dfs(res, path, hash,h,nums, 0, 0, 0);
//	return res;
//}

//https://www.cnblogs.com/wmx24/p/8989800.html
//更快速的思路:首先对数组进行排序，对第一个值轮训，轮询到正数时停止，因为后面的数都是正数，不可能相加为负数
//对于第一个值锁定的情况下，设立双指针对后面的数进行前后轮询，当两数相加为第一个数的负数时存入解，但仍需去重
vector<vector<int>> threeSum(vector<int>& nums){
	vector<vector<int>>res;
	if (nums.size() < 3)return res;
	sort(nums.begin(), nums.end());
	vector<int>vec;
	int sum=-1;//第一道去重,防止两个相同的第一个数进入循环
	for (int i = 0; i < nums.size() - 2; ++i){
		if (nums[i]>0)
			break;
		if (sum == -nums[i])
			continue;
		vec.push_back(nums[i]);
		sum = -nums[i];
		int l = i + 1, r = nums.size() - 1;
		int quchong = nums[l] - 1;//赋初值，第二次去重
		while (l < r){
			if (nums[l] + nums[r] == sum){
				if (quchong != nums[l]){
					vec.push_back(nums[l]);
					vec.push_back(nums[r]);
					res.push_back(vec);
					vec.pop_back();
					vec.pop_back();
					quchong = nums[l];//循环时赋上一个左边值
				}
				l++; r--;
			}
			else if (nums[l] + nums[r] < sum)
				l++;
			else if (nums[l] + nums[r] > sum)
				r--;
		}
		vec.pop_back();
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 0,0,0,0 };
	vector<vector<int>>res = threeSum(nums);
	for (vector<int>vec : res){
		for (int t : vec){
			cout << t << ",";
		}
		cout << endl;
	}

	//test2
	cout << endl << "test2" << endl;
	nums = { -1, 0, 1, 2, -1, -4 };
	res = threeSum(nums);
	for (vector<int>vec : res){
		for (int t : vec){
			cout << t << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}