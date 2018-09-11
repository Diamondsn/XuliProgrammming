#include "stdafx.h"
#include<string>
#include<vector>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

//��Ŀ����
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳��
//����4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
//��4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

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