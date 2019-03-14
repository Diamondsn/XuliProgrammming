//选择排序
#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b);
void SelectSort(vector<int> & a);
void print(vector<int> &a);
int main() {
	vector<int> arr = { 3,5,4,8,7,6,1,2 };
	SelectSort(arr);
	print(arr);
	cin.get();
	return 0;
}
void swap(int &a, int &b) {
		int temp;
		temp = b;
		b = a;
		a = temp;
}
void SelectSort(vector<int> &a) {
	int num = a.size();
	for (int i = 0; i<num - 1; i++) {      //遍历整个数组，且假设性的设当前值为最大值
		int max = i;
		for (int k = i+1; k<num; k++) {    //比较剩余数和当前值的大小，找出正真的最大值
			if (a[k] > a[max])
				max = k;
		}
		if (max != i) {                   //将最大值置前
			swap(a[max], a[i]);
		}
	}
}
void print(vector<int> &a) {
	auto i = a.begin();
	auto j = a.end();
	for (; i != j; i++) {
		cout << *i;
	}
}