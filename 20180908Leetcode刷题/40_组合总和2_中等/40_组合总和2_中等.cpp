#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的每个数字在每个组合中只能使用一次。
//
//说明：
//所有数字（包括目标数）都是正整数。
//解集不能包含重复的组合。 
//
//示例 1:
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
//
//示例 2:
//输入: candidates = [2,5,2,1,2], target = 5,
//所求解集为:
//[
//  [1,2,2],
//  [5]
//]

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

}

int main() {
	//test1
	vector<int>candidates = { 10, 1, 2, 7, 6, 1, 5 };
	vector<vector<int>>res = combinationSum2(candidates, 8);
	for (vector<int>vec : res)
	{
		for (int m : vec)
			cout << m << ",";
		cout << endl;
	}

	//test2
	cout << "test2" << endl;
	res = combinationSum2(candidates, 5);
	for (vector<int>vec : res){
		for (int m : vec)
			cout << m << ",";
		cout << endl;
	}
	//test end
	system("pause");
	return 0;
}