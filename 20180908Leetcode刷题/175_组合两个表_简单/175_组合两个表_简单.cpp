#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//��1: Person
//+ ------------ - +-------- - +
//| ����           | ����      |
//+------------ -  +-------- - +
//| PersonId       | int       |
//| FirstName      | varchar   |
//| LastName       | varchar   |
//+------------ -  +-------- - +
//PersonId ���ϱ�����
//
//��2 : Address
//+ ------------ - +-------- - +
//| ����           | ����      |
//+------------ -  +-------- - +
//| AddressId      | int       |
//| PersonId       | int       |
//| City           | varchar   |
//| State          | varchar   |
//+------------ -  +-------- - +
//AddressId ���ϱ�����
//
//��дһ�� SQL ��ѯ���������������� person �Ƿ��е�ַ��Ϣ������Ҫ�������������ṩ person ��������Ϣ��
//
//FirstName, LastName, City, State

int main() {
	//test
	cout << "Write your MySQL query statement below" << endl;
	//test end
	system("pause");
	return 0;
}