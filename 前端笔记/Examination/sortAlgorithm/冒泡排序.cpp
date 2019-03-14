//冒泡排序
#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b);
void BubbleSort(vector<int> & a);
void print(vector<int> &a);
int main() {
	vector<int> arr= {3,5,4,8,7,6,1,2};
	BubbleSort(arr);
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
void BubbleSort(vector<int> &a) {
	int num = a.size();
	for (int i = 0;i<num-1; i++) {            //外层循环表示循环次数
		for (int k=0;k<num-1-i; k++) {
			if (a[k+1]>a[k])                 //内层循环中每次最小的数冒泡到队尾
				swap(a[k+1], a[k]);
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