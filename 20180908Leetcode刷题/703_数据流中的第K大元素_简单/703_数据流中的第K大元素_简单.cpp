#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。
//
//你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。
//每次调用 KthLargest.add，返回当前数据流中第K大的元素。
//
//示例:
//int k = 3;
//int[] arr = [4,5,8,2];
//KthLargest kthLargest = new KthLargest(3, arr);
//kthLargest.add(3);   // returns 4
//kthLargest.add(5);   // returns 5
//kthLargest.add(10);  // returns 5
//kthLargest.add(9);   // returns 8
//kthLargest.add(4);   // returns 8
//
//说明: 
//你可以假设 nums 的长度≥ k-1 且k ≥ 1。

class KthLargest {
public:
	KthLargest(int k, vector<int> nums) {
		m = k;
		data = nums;
		sort(data.begin(), data.end());
		reverse(data.begin(), data.end());
	}

	int add(int val) {
		if (data.size() == 0){ data.push_back(val); }
		else{
			if (val < (*--data.end()))
				data.push_back(val);
			else{
				for (auto it = data.begin(); it != data.end(); ++it)
				{
					if (*it <= val){
						data.insert(it, val);
						break;
					}
				}
			}
		}
		return data[m-1];
	}
	vector<int>data;
	int m;
};

/**
* Your KthLargest object will be instantiated and called as such:
* KthLargest obj = new KthLargest(k, nums);
* int param_1 = obj.add(val);
*/

int main() {
	//test1
	vector<int>arr = { 4, 5, 8, 2 };
	KthLargest kthLargest = KthLargest(3, arr);
	int a=kthLargest.add(3);   // returns 4
	int b=kthLargest.add(5);   // returns 5
	int c = kthLargest.add(10);  // returns 5
	int d = kthLargest.add(9);   // returns 8
	int e = kthLargest.add(4);   // returns 8
	cout << a << endl << b << endl << c << endl << d << endl << e << endl;
	//test end

	system("pause");
	return 0;
}