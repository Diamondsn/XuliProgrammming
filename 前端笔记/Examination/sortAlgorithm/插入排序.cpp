//插入排序
#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b);
void InsertSort(vector<int> & a);
void print(vector<int> &a);
int main() {
	vector<int> arr = { 3,5,4,8,7,6,1,2,};
	InsertSort(arr);
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
/*void InsertSort(vector<int> &a) {
	int num = a.size();
	for (int i = 1; i<num; i++) {
		for (int k = i-1; k>=0; k--) {
			if (a[i] > a[k]) {
				swap(a[i], a[k]);
				i = k;
			}
		}
	}
}*/
void InsertSort(vector<int> &a) {
	int num = a.size();
	for (int i = 1; i < num; i++) {      //第一数不变，遍历其余的数组元素
		for (int k = i - 1; k >= 0; k--) {
			if (a[k + 1] > a[k])         // 找到每个元素相对于它前面元素合适的位置
				swap(a[k + 1], a[k]);
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