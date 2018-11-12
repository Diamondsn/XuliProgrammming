#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<unordered_set>
#include"time.h"
using namespace std;

//给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。
//
//注意：
//数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。
//
//示例 :
//
//int[] nums = new int[] {1, 2, 3, 3, 3};
//Solution solution = new Solution(nums);
//
//// pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
//solution.pick(3);
//
//// pick(1) 应该返回 0。因为只有nums[0]等于1。
//solution.pick(1);

//蓄水池抽样
class Solution {
public:
	Solution(vector<int> nums) {
		m_nums = nums;
		srand(time(NULL));
	}

	int pick(int target) {
		int res, m=1;
		for (int i=0; i < m_nums.size(); ++i){
			if (m_nums[i] == target){
				if (rand() % m == 0){//m是和target相同的数字个数
					res = i;
				}
				m++;
			}
		}
		return res;
	}
	vector<int>m_nums;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* int param_1 = obj.pick(target);
*/

void main(){
	//test1
	vector<int>nums = { 1, 2, 3, 3, 3 };
	Solution sol(nums);
	int a=sol.pick(3);
	int b = sol.pick(1);
	cout << a << endl << b << endl;
	//test end
	system("pause");
}
