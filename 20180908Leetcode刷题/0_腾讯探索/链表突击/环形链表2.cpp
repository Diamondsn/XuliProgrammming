#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//
//˵�����������޸ĸ���������
//
//���ף�
//���Ƿ���Բ��ö���ռ������⣿

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
	ListNode* kuai = head, *man = head;
	while(kuai&&kuai->next)
	{
		kuai = kuai->next->next;
		man = man->next;
		if (kuai)
	}
	return NULL;
}

void LianBiaoBianli(ListNode* head){
	while (head){
		cout << head->val << "->";
		head = head->next;
	}
}

int main() {
	//test1
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l5;
	ListNode* res = detectCycle(l1);
	cout << res->val << endl;
	//test end

	system("pause");
	return 0;
}