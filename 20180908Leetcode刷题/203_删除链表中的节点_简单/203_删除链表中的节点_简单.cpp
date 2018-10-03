#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//删除链表中等于给定值 val 的所有节点。
//
//示例:
//输入: 1->2->6->3->4->5->6, val = 6
//输出: 1->2->3->4->5

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void ListNodeBianli(ListNode* head)
{
	while (head)
	{
		cout << head->val << endl;
		head = head->next;
	}
}

ListNode* removeElements(ListNode* head, int val) {
	if (head == NULL)
		return head;
	ListNode* newhead = new ListNode(0);
	newhead->next = head;
	ListNode* prev = newhead;
	ListNode* cur = prev->next;
	while (cur) {
		if (cur->val == val)
			prev->next = cur->next;
		else
			prev = cur;
		cur = cur->next;
	}
	return newhead->next;
}

int main() {
	//test1
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(6);
	ListNode* l4 = new ListNode(3);
	ListNode* l5 = new ListNode(4);
	ListNode* l6 = new ListNode(5);
	ListNode* l7 = new ListNode(6);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	ListNode* res = removeElements(l1, 6);
	ListNodeBianli(res);
	//test end
	system("pause");
	return 0;
}