#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<algorithm>
using namespace std;

//����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
//��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������
//ע���㲻���������Ʊǰ������Ʊ��
//
//ʾ�� 1:
//����: [7,1,5,3,6,4]
//���: 5
//����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
//     ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
//
//ʾ�� 2:
//����: [7,6,4,3,1]
//���: 0
//����: �����������, û�н������, �����������Ϊ 0��

//int maxProfit(vector<int>& prices) {
//	int max = 0;
//	for (int i = 0; i < prices.size(); ++i)
//	{
//		for (int j = i; j < prices.size(); ++j)
//		{
//			int t = prices[j] - prices[i];
//			if (t > max)
//				max = t;
//		}
//	}
//	return max;
//}

//��̬�滮
int maxProfit(vector<int>& prices) {
	if (prices.size() < 1)
		return 0;

	int min = prices[0];
	int max = 0;
	for (int i = 1; i < prices.size(); ++i)
	{
		if (max < prices[i] - min)
			max = prices[i] - min;

		if (min > prices[i])
			min = prices[i];
	}
	return max;
}

void main() {
	//test 1
	vector<int>vec = { 7,1,5,3,6,4 };
	int a = maxProfit(vec);
	cout << a << endl;
	//test end
	system("pause");
}
