#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//���������ѣ�������һ���� Nim��Ϸ����������һ��ʯͷ��ÿ�����������õ� 1 - 3 ��ʯͷ�� �õ����һ��ʯͷ���˾��ǻ�ʤ�ߡ�����Ϊ���֡�
//
//�����Ǵ����ˣ�ÿһ���������Ž⡣ ��дһ�����������ж����Ƿ�����ڸ���ʯͷ�����������Ӯ����Ϸ��
//
//ʾ�� :
//����: 4
//��� : false
//���� : ��������� 4 ��ʯͷ����ô����Զ����Ӯ�ñ�����
//��Ϊ���������� 1 �顢2 �� ���� 3 ��ʯͷ�����һ��ʯͷ���ǻᱻ����������ߡ�

bool canWinNim(int n) {
	int m = n % 4;
	if (m == 0)
		return false;
	else
		return true;
}

int main() {
	//test
	for (int i = 1; i <= 20; i++)
	{
		cout << canWinNim(i) << endl;
	}
	//test end

	system("pause");
	return 0;
}