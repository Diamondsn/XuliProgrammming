#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//
//说明：不允许修改给定的链表。
//
//进阶：
//你是否可以不用额外空间解决此题？

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
		if (kuai == man) {
			kuai = head;
			while (kuai != man) {
				kuai = kuai->next;
				man = man->next;
			}
			return man;
		}
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
	l5->next = l2;
	ListNode* res = detectCycle(l1);
	cout << res->val << endl;
	//test end

	system("pause");
	return 0;
}