#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
using namespace std;

//根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。如果之后都不会升高，请输入 0 来代替。
//
//例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
//
//提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的都是 [30, 100] 范围内的整数。

//该方法超时，搜索时间过长
//vector<int> dailyTemperatures(vector<int>& temperatures) {
//	map<int, int>hash;//第一个存索引，第二个存数字；
//	vector<int>res(temperatures.size(),0);
//	for (int i = 0; i < temperatures.size(); ++i){
//		for (auto it = hash.begin(); it != hash.end();){
//			if (it->second < temperatures[i]){
//				res[it->first] = i - it->first;
//				it = hash.erase(it);
//			}
//			else
//				it++;
//		}
//		hash.insert(pair<int, int>(i, temperatures[i]));
//	}
//	return res;
//}

//使用最小栈有两种方式
//从前往后遍历数组。当当前数大于栈顶元素时，栈pop，同时计算出索引插值
//https://blog.csdn.net/jackzhang_123/article/details/78894769
//vector<int>dailyTemperatures(vector<int>& temperatures){
//	vector<int>res(temperatures.size(),0);
//	stack<int>mystack;//栈顶元素最小
//	for (int i = 0; i < temperatures.size(); ++i){
//		while (!mystack.empty() && temperatures[i] > temperatures[mystack.top()]){
//			res[mystack.top()] = i - mystack.top();
//			mystack.pop();
//		}
//		mystack.push(i);
//	}
//	return res;
//}

//使用最小栈的第二种方式，从后往前遍历
//https://blog.csdn.net/yudianxia/article/details/79303394
vector<int>dailyTemperatures(vector<int>& temperatures){
	vector<int>res;
	stack<int>mystack;
	for (int i = (int)temperatures.size() - 1; i >= 0; --i){
		while (!mystack.empty() && temperatures[i] > temperatures[mystack.top()]){
			mystack.pop();
		}
		res.insert(res.begin(), mystack.empty() ? 0 : mystack.top() - i);
		mystack.push(i);
	}
	return res;
}

int main() {
	//test1
	vector<int>temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int>res = dailyTemperatures(temperatures);
	for (int i : res)cout << i << endl;
	//test end
	system("pause");
	return 0;
}