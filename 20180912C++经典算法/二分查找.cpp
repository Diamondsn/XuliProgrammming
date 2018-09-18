#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//二分查找
//假设数组从小到大排列
int binary_search(int *arr, int item,int low, int high)
{
	int result = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == item)
		{
			result = mid;
			break;
		}
		else if (arr[mid] < item)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return result;
}

//二分法查找用vector存储的数据
int binarry_search(vector<int>& vec, int item)
{
	int result = -1;
	int low = 0; 
	int high = vec.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (vec[mid] == item)
		{
			result = mid;
			break;
		}
		else if (vec[mid] < item)
		{
			low = mid + 1;
		}
		else if (vec[mid] > item)
		{
			high = mid - 1;
		}
	}
	return result;
}
void main(){
	//test1
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int a=binary_search(arr, 10, 0, 8);
	//test2
	int b = binary_search(arr, 3, 0, 8);

	//使用数组进行二分搜索
	cout << "使用数组进行二分搜索" << endl;
	cout << a <<endl<< b << endl;

	//test3
	vector<int>vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int c=binarry_search(vec, 10);

	//test4
	int d=binarry_search(vec, 7);
	cout << "使用vector进行二分搜索" << endl;
	cout << c << endl << d << endl;
	//test4
	//test end
	system("pause");
}
