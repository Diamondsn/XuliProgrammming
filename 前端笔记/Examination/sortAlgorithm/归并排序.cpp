//归并排序
#include <iostream>
#include <vector>
using namespace std;
void MergeSort(vector<int> &a, vector<int> &temArray, int left, int right);
void Merge(vector<int> &a, vector<int> &tmpArray, int leftPos, int rightPos, int rightEnd);
void print(vector<int> &a);
int main() {
	vector<int> arr = { 5,4,3,1,2,6,7,9,8,0 };
	vector<int> tmpArr(arr.size());
	MergeSort(arr, tmpArr, 0, arr.size() - 1);
	print(arr);
	cin.get();
	return 0;
}
void MergeSort(vector<int> &a, vector<int> &tmpArray, int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		MergeSort(a, tmpArray, left, center);
		MergeSort(a, tmpArray, center + 1, right);
		Merge(a, tmpArray, left, center + 1, right);
	}
}
void Merge(vector<int> &a, vector<int> &tmpArray, int leftPos, int rightPos, int rightEnd) {
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int num = rightEnd - leftPos + 1;
	while (leftPos <= leftEnd && rightPos <= rightEnd)
		if (a[leftPos] >= a[rightPos])
			tmpArray[tmpPos++] = a[leftPos++];
		else
			tmpArray[tmpPos++] = a[rightPos++];
	while (leftPos <= leftEnd)
		tmpArray[tmpPos++] = a[leftPos++];
	while (rightPos <= rightEnd)
		tmpArray[tmpPos++] = a[rightPos++];
	for (int i = 0; i < num; ++i, --rightEnd)
		a[rightEnd] = tmpArray[rightEnd];
}
void print(vector<int> &a) {
	auto i = a.begin(), j = a.end();
	for (; i != j; i++)
		cout << *i;
}