#include <list>
#include <iostream>
#include <vector>
using namespace std;

//小Q有一个由n个整数组成的一个圆环，现在要从中取出m个数。因为未知的原
//因，当取走一个数字就不能取跟它相邻的数组(相邻数字不能同时取)。小Q想知
//道能取出的最大和是多少，希望你能帮帮他

//输入描述:
//第一行包含两个正整数n,m。
//第二行为n个整数Ai，表示圆环中的数。
//m<n<=200000;-1000<=A1<=1000
//输出描述:
//输出一个整数，表示最大和。如果无解，则输出"Error!"，不含引号
//
//示例1
//输入
//8 4
//8 5 6 2 3 4 8 9
//输出
//25


//计算单向链表非相邻元素最大和
int getlargest(vector<int>nums, int n)
{
	if (nums.size() == (2 * n - 1))
	{
		int sum = 0;
		for (size_t i = 0; i < nums.size(); i += 2)
		{
			sum += nums[i];
		}
		return sum;
	}
	else if (nums.size() == (2 * n))
	{
		int sum1 = 0, sum2 = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (i & 1)
				sum2 += nums[i];
			else
				sum1 += nums[i];
		}
		return sum1 > sum2 ? sum1 : sum2;
	}
	if (n == 1)
	{
		int sum = nums[0];
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > sum)
				sum = nums[i];
		}
		return sum;
	}

	//若不选第一个
	int first = nums.front();
	nums.erase(nums.begin());
	int sum1 = getlargest(nums, n);
	//若选中第一个
	nums.erase(nums.begin());
	int sum2 = first + getlargest(nums, n - 1);
	return sum1 > sum2 ? sum1 : sum2;
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		if (m < (2 * n))
			cout << "Error" << endl;
		else
		{
			vector<int>nums;
			while (m--)
			{
				int t;
				cin >> t;
				nums.push_back(t);
			}
			//若不选第一个元素，从此处将环剪断
			int first = nums.front();
			nums.erase(nums.begin());
			int sum1 = getlargest(nums, n);
			//若选择第一个元素，则从两侧两个元素旁剪断
			nums.erase(nums.begin());
			nums.erase(--nums.end());
			int sum2 = first + getlargest(nums, n - 1);

			cout << (sum1 > sum2 ? sum1 : sum2) << endl;
		}

	}
	system("pause");
}