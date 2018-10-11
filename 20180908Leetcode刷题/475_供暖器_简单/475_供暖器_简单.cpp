#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
//
//现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。
//
//所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。
//
//说明:
//给出的房屋和供暖器的数目是非负数且不会超过 25000。
//给出的房屋和供暖器的位置均是非负数且不会超过10^9。
//只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
//所有供暖器都遵循你的半径标准，加热的半径也一样。
//
//示例 1:
//输入: [1,2,3],[2]
//输出: 1
//解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
//
//示例 2:
//输入: [1,2,3,4],[1,4]
//输出: 1
//解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。

//得到houses中与m的绝对值之差最小的数，保证m不与houses中的任何一个数相同
int getNearest(vector<int>& heaters, int m){
	int left = 0, right = heaters.size() - 1;
	while (left <= right){
		int mid = (left + right / 2);
		if (heaters[mid] > m)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

int findRadius(vector<int>& houses, vector<int>& heaters) {
	int res = 0;
	map<int, int>hash;
	for (int i = 0; i < heaters.size(); ++i){
		if (hash.find(heaters[i]) == hash.end())
			hash.insert(pair<int, int>(heaters[i], 0));
	}
	sort(heaters.begin(), heaters.end());
	for (int i = 0; i < houses.size(); ++i){
		if (hash.find(houses[i]) != hash.end()){
			int temp = getNearest(heaters, houses[i]);
			if (abs(temp - houses[i]) > hash[temp])hash[temp] = abs(temp - houses[i]);
		}
	}
	for (auto it = hash.begin(); it != hash.end(); ++it)
		if (it->second > res)
			res = it->second;
	return res;
}

int main() {
	//test map order
	map<int,int>hash;//会根据字典顺序排序，使用调试工具查看insert操作完毕后的hash；
	for (int i = 100; i >=0; --i){
		hash.insert(pair<int, int>(i, 0));
	}
	//test getNearest()函数
	vector<int>nums = { 1, 10, 15, 20, 30, 40 };
	int m = getNearest(nums,0);

	system("pause");

	//test1
	vector<int>houses = { 1, 2, 3 }, heaters = {2};
	int a = findRadius(houses, heaters);

	//test2
	houses = { 1, 2, 3, 4 };
	heaters = { 1, 4 };
	int b = findRadius(houses, heaters);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}