#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdint.h>
#include<map>
using namespace std;

//在一排座位（ seats）中，1 代表有人坐在座位上，0 代表座位上是空的。
//
//至少有一个空座位，且至少有一人坐在座位上。
//
//亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。
//
//返回他到离他最近的人的最大距离。
//
//示例 1：
//输入：[1,0,0,0,1,0,1]
//输出：2
//解释：
//如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
//如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
//因此，他到离他最近的人的最大距离是 2 。 
//
//示例 2：
//输入：[1,0,0,0]
//输出：3
//解释： 
//如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
//这是可能的最大距离，所以答案是 3 。
//
//提示：
//1 <= seats.length <= 20000
//seats 中只含有 0 和 1，至少有一个 0，且至少有一个 1。

int maxDistToClosest(vector<int>& seats) {
	int i, j;
	for (i = 0; i < seats.size(); ++i) {
		if (seats[i] == 1)break;
	}
	for (j = seats.size() - 1; j >= 0; --j) {
		if (seats[j] == 1)break;
	}
	int res = max(i == 0 ? 1 : i, j == seats.size() - 1 ? 1 :(int) seats.size() - 1 - j);
	int temp = 0;
	while (i < j)
	{
		if (seats[i] == 1)
		{
			temp = 0;
		}
		else
			temp++;

		if ((temp % 2 == 0 ? temp / 2 : temp / 2 + 1) > res)
			res = (temp % 2 == 0 ? temp / 2 : temp / 2 + 1);
		i++;
	}
	return res;
}

int main() {
	//test1
	vector<int>nums = { 1,0,0,0,1,0,1 };
	int a = maxDistToClosest(nums);

    //test2
	nums = { 1,0,0,0 };
	int b = maxDistToClosest(nums);

	//test3
	nums = { 0,1,1,1,0,0,1,0,0 };
	int c = maxDistToClosest(nums);
	cout << a << endl << b << endl<<c<<endl;
	//test end

	system("pause");
	return 0;
}