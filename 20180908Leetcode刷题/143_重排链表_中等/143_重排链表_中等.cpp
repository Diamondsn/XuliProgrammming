#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<deque>
using namespace std;

//给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
//将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//示例 1:
//给定链表 1->2->3->4, 重新排列为 1->4->2->3.
//
//示例 2:
//给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void ListNodeBianli(ListNode* head)
{
	while (head)
	{
		cout << head->val << ",";
		head = head->next;
	}
	cout << endl;
}

void reorderList(ListNode* head) {

}

int main() {
	//test1
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	reorderList(l1);

	//test2
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	reorderList(n1);
	//test end

	system("pause");
	return 0;
}