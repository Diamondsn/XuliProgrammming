#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
//示例:
//输入: [0,1,0,3,12]
//输出: [1,3,12,0,0]
//
//说明:
//必须在原数组上操作，不能拷贝额外的数组。
//尽量减少操作次数。

void moveZeroes(vector<int>& nums) {
	int wei_0 = -1;//标记是0的位置
	for (int i = 0; i < nums.size(); ++i)
	{
		if (wei_0==-1 && nums[i] == 0)
		{
			wei_0 = i;
		}
		if (nums[i] != 0 && wei_0!=-1 && wei_0<i)
		{
			nums[wei_0] = nums[i];
			nums[i] = 0;
			for (int j = wei_0+1; j < nums.size(); ++j)
			{
				if (nums[j] == 0)
				{
					wei_0 = j;
					break;
				}
			}
		}
	}
}

void main(){
	//test1
	vector<int>vector = { 0, 1, 0, 3, 12 };
	moveZeroes(vector);
	for (int i = 0; i < vector.size(); ++i)
	{
		cout << vector[i] << ",";
	}
	cout << endl;
	//test end
	system("pause");
}
