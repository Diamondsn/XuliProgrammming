#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//�ڶ�άƽ���ϣ���һ�������˴�ԭ��(0, 0) ��ʼ�����������ƶ�˳���ж����������������ƶ����Ƿ���(0, 0) ��������
//
//�ƶ�˳�����ַ�����ʾ���ַ� move[i] ��ʾ��� i ���ƶ��������˵���Ч������ R���ң���L���󣩣�U���ϣ��� D���£��������������������ж����󷵻�ԭ�㣬�򷵻� true�����򣬷��� false��
//
//ע�⣺�����ˡ��泯���ķ����޹ؽ�Ҫ�� ��R�� ��ʼ��ʹ�����������ƶ�һ�Σ���L�� ��ʼ�������ƶ��ȡ����⣬����ÿ���ƶ������˵��ƶ�������ͬ��
//
//
//
//ʾ�� 1:
//
//����: "UD"
//��� : true
//���ͣ������������ƶ�һ�Σ�Ȼ�������ƶ�һ�Ρ����ж�����������ͬ�ķ��ȣ���������ջص�����ʼ��ԭ�㡣��ˣ����Ƿ��� true��
//	
//ʾ�� 2 :
//
//���� : "LL"
//��� : false
//���ͣ������������ƶ����Ρ�������λ��ԭ�����࣬��ԭ�������� ���ƶ��� �ľ��롣���Ƿ��� false����Ϊ�����ƶ�����ʱû�з���ԭ�㡣

bool judgeCircle(string moves) {
	int countR = 0, countL = 0, countU = 0,countD = 0;
	for (int i = 0; i < moves.length(); ++i)
	{
		if (moves[i] == 'R')
			countR++;
		else if (moves[i] == 'L')
			countL++;
		else if (moves[i] == 'U')
			countU++;
		else if (moves[i] == 'D')
			countD++;
	}
	if (countR == countL && countU == countD)
		return true;

	return false;
}

int main() {
	//test1
	bool b1 = judgeCircle("UD");
	bool b2 = judgeCircle("LL");

	cout << b1 << " ," << b2 << endl;
	//test end

	system("pause");
	return 0;
}