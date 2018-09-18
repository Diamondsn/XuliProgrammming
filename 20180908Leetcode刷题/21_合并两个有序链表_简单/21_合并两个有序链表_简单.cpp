#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL && l2 == NULL)
		return NULL;
	if (l1 == NULL &&l2 != NULL)
		return l2;
	if (l1 != NULL && l2 == NULL)
		return l1;

	if (l1->val <= l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	if (l1->val > l2->val)
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

void ListBianli(ListNode* node)
{
	ListNode* temp = node;
	while (temp)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}
}

void main() {
	//test
	ListNode* l1 = new ListNode(1);
	ListNode* l1_2 = new ListNode(2);
	ListNode* l1_4 = new ListNode(4);
	l1->next = l1_2;
	l1_2->next = l1_4;

	ListNode* l2 = new ListNode(1);
	ListNode* l2_3 = new ListNode(3);
	ListNode* l2_4 = new ListNode(4);
	l2->next = l2_3;
	l2_3->next = l2_4;

	ListNode* m = mergeTwoLists(l1, l2);
	ListBianli(m);
	//test end
	system("pause");
}
