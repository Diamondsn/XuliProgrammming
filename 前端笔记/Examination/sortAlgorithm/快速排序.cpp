//快速排序
#include <iostream>
#include <vector>
using namespace std;
void QuickSort(vector<int> &a);
void Merge(vector<int>::iterator a,vector<int>::iterator b, vector<int>::iterator c);
void print(vector<int> &a);
int main(){
	vector<int> arr = { 3,1,5,6,7,4,2,9,0,8};
	QuickSort(arr);
	print(arr);
	cin.get();
	return 0;
}
void QuickSort(vector<int> &a) {
	if (a.size() > 1) {
		vector<int> smaller;
		vector<int> same;
		vector<int> larger;
		int pivot = a[a.size() / 2];
		for (int &element : a) {
			if (element < pivot)
				smaller.push_back(element);
			else if (element > pivot)
				larger.push_back(element);
			else
				same.push_back(element);
		}
		QuickSort(smaller);
		QuickSort(larger);
		Merge(begin(smaller), end(smaller), begin(a));
		Merge(begin(same), end(same), begin(a) + smaller.size());
		Merge(begin(larger), end(larger), end(a) - larger.size());
	}
}
void Merge(vector<int>::iterator a, vector<int>::iterator b, vector<int>::iterator c)
{
	for (; a != b; a++, c++) {
		*c = *a;
	}
}
void print(vector<int> &a) {
	auto i = a.begin(), j = a.end();
	for (; i != j; i++)
		cout << *i;
}