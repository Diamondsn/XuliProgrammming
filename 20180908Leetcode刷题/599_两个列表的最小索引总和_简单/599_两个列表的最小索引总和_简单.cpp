#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

//假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
//
//你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 
//如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。
//
//示例 1:
//输入:
//["Shogun", "Tapioca Express", "Burger King", "KFC"]
//["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
//输出: ["Shogun"]
//解释: 他们唯一共同喜爱的餐厅是“Shogun”。
//
//示例 2:
//输入:
//["Shogun", "Tapioca Express", "Burger King", "KFC"]
//["KFC", "Shogun", "Burger King"]
//输出: ["Shogun"]
//解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
//
//提示:
//两个列表的长度范围都在 [1, 1000]内。
//两个列表中的字符串的长度将在[1，30]的范围内。
//下标从0开始，到列表的长度减1。
//两个列表都没有重复的元素。

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
	vector<string>res;
	int min = INT_MAX;
	map<string, int>mymap;
	for (int i = 0; i < list1.size(); ++i)
	{
		if (mymap.find(list1[i]) == mymap.end())
			mymap.insert(pair<string, int>(list1[i], i));
	}
	for (int i = 0; i < list2.size(); ++i)
	{
		if (mymap.find(list2[i]) != mymap.end())
		{
			if (mymap[list2[i]] + i < min)
			{
				min = mymap[list2[i]] + i;
				res.clear();
				res.push_back(list2[i]);
			}
			else if (mymap[list2[i]] + i == min)
			{
				res.push_back(list2[i]);
			}
		}
	}
	return res;
}

int main() {
	//test1
	vector<string>list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string>list2 = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };
	vector<string>res= findRestaurant(list1,list2);
	cout << "test1" << endl;
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	cout << endl;
	//test2
	list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
	list2 = { "KFC", "Shogun", "Burger King" };
	res= findRestaurant(list1,list2);
	cout << "test2" << endl;
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}