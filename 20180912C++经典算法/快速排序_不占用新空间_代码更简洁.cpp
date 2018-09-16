#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<algorithm>
using namespace std;

//快速排序，代码更简洁
void Q_sort(int a[],int num)
{
	int i = 0;
	int j = num - 1;
	int k = a[0];//轴值必须为第一个
	if (num > 1)//只有1个就不用排序了
	{
		while (i != j)
		{
			for (; i < j; j--)
			{
				if (a[j] < k)
				{
					a[i] = a[j];
					break;
				}
			}
			for (; i < j; i++)
			{
				if (a[i] > k)
				{
					a[j] = a[i];
					break;
				}
			}
		}
		a[i] = k;

		Q_sort(a, i);
		Q_sort(a + i + 1, num - i - 1);
	}
}

void main() {
	//test 1
	int arr[10] = { 72,6,57,88,85,42,83,73,48,60 };
	Q_sort(arr, 10);//
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << endl;
	}
	//test end
	system("pause");
}
