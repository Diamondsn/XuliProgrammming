#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//不占用新空间的选择排序算法
//使用的内部交换函数
void swap(int *arr, int m, int n)
{
	if (m == n)
		return;

	int temp = arr[m];
	arr[m] = arr[n];
	arr[n] = temp;
}

//不占用新空间的使用数组的选择排序算法
void Select_sort(int *arr, int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		int lowindex = i;
		for (int j = i; j < n; j++)
		{
			if (arr[lowindex]>arr[j])
				lowindex = j;
		}
		swap(arr, i, lowindex);
	}
}

//不占用新空间的使用vector的选择排序算法
//使用的内部交换函数
void Swap(vector<int>& vec, int i, int j)
{
	if (i == j)
		return;

	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

//不占用新空间的使用vector的选择排序算法
void Select_sort(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		int lowindex = i;
		for (int j = i; j < vec.size(); ++j)
		{
			if (vec[lowindex]>vec[j])
				lowindex = j;
		}
		Swap(vec, lowindex, i);
	}
}
void main(){
	//test1
	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	Select_sort(arr, 10);

	cout << "test1" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//test2
	vector<int>vector = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	Select_sort(vector);

	cout << "test2" << endl;
	for (int i = 0; i < vector.size(); ++i)
	{
		cout << vector[i] << endl;
	}
	//test end
	system("pause");
}
