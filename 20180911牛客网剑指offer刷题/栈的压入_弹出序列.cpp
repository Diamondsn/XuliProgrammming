#include<string>
#include<vector>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

//题目描述
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是某栈的压入顺序，
//序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，
//但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	if (pushV.size() != popV.size())
		return false;

	stack<int> mystack;
	int j = 0;
	for (int i = 0; i < popV.size(); ++i)
	{
		while (!mystack.empty() && mystack.top() == popV[i])
		{
		    mystack.pop();
			i++;
        }
		if (j < pushV.size())
		{
			while (j<pushV.size() && popV[i] != pushV[j])
			{
				mystack.push(pushV[j]);
				j++;
			}
			j++;
		}
		else {
			if (!mystack.empty())
				return false;
			else
				return true;
		}
	}

	if (!mystack.empty())
		return false;
	else
		return true;
}

int main() {
	//test1
	vector<int> pushV = { 1,2,3,4,5 };
	vector<int> popV1 = { 4,5,3,2,1 };
	vector<int> popV2 = { 4,3,5,1,2 };
	bool a = IsPopOrder(pushV, popV1);//true
	bool b = IsPopOrder(pushV, popV2);//false
	cout << a << endl << b << endl;
	//test end

	//test2
	vector<int> pushV1;
	pushV1.push_back(1);
	vector<int> popV3;
	popV3.push_back(1);
	vector<int> popV4;
	popV4.push_back(2);
	bool c = IsPopOrder(pushV1, popV3);
	bool d = IsPopOrder(pushV1, popV4);
	cout << c << endl <<d<< endl;
	//test2 end
	system("pause");
	return 0;
}