#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
//
//给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
//
//示例 1:
//输入: flowerbed = [1,0,0,0,1], n = 1
//输出: True
//
//示例 2:
//输入: flowerbed = [1,0,0,0,1], n = 2
//输出: False
//
//注意:
//数组内已种好的花不会违反种植规则。
//输入的数组长度范围为 [1, 20000]。
//n 是非负整数，且不会超过输入数组的大小。

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	int res = 0,i,j,temp=0;
	for (i = 0; i < flowerbed.size(); ++i){
		if (flowerbed[i] == 1)
			break;
	}
	if (i == flowerbed.size())//若全部为0
		return (flowerbed.size() % 2 == 0 ? flowerbed.size()/2:flowerbed.size()/2+1)>=n ;
	res += i / 2;
	for (j = flowerbed.size() - 1; j >= 0; --j){
		if (flowerbed[j] == 1)
			break;
	}
	res += (flowerbed.size() - 1 - j) / 2;
	if (res >= n)return true;
	for (int m = i; m <= j; ++m){
		if (flowerbed[m] == 1 && temp > 0){
			res += (temp % 2 == 0 ? temp / 2 - 1 : temp / 2);
			temp = 0;
		}
		else if (flowerbed[m] == 0)
			temp++;

		if (res >= n)
			return true;
	}
	return false;
}

int main() {
	//test1
	vector<int>nums = { 1, 0, 0, 0, 1 };
	bool a = canPlaceFlowers(nums,1);

	//test2
	bool b = canPlaceFlowers(nums,2);

	//test3
	nums = { 1, 0, 0, 0, 1, 0, 0 };
	bool c = canPlaceFlowers(nums, 2);

	//test4
	nums = { 0 };
	bool d = canPlaceFlowers(nums, 1);
	cout << a << endl << b << endl<<c<<endl<<d<<endl;
	//test end

	system("pause");
	return 0;
}