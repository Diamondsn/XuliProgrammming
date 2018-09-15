#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//反转一个单链表。
//
//示例 :
//输入: 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
//	
//进阶 :
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//迭代
ListNode* reverseList_diedai(ListNode* head) {
	if (head == NULL)
		return NULL;
	
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* next = cur->next;
	cur->next = pre;
	while(next){

		pre = cur;
		cur = next;
		next = cur->next;

		cur->next = pre;
	}
	return cur;
}

//递归
ListNode* reverseList_digui(ListNode* head) {
	if (head == NULL)
		return NULL;

	if (head->next == NULL)
		return head;

	ListNode* newhead = reverseList_digui(head->next);
	

	ListNode* temp = newhead;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return newhead;
}

void ListNodeBianli(ListNode* head)
{
	while (head)
	{
		cout << head->val << endl;
		head = head->next;
	}
}

int main() {
	//test1
	ListNode* n = new ListNode(1);
	ListNode* n_2 = new ListNode(2);
	ListNode* n_3 = new ListNode(3);
	ListNode* n_4 = new ListNode(4);
	ListNode* n_5 = new ListNode(5);

	n->next = n_2;
	n_2->next = n_3;
	n_3->next = n_4;
	n_4->next = n_5;

	ListNode* diedai = reverseList_diedai(n);
	cout << "test1" << endl;
	ListNodeBianli(diedai);

	//test2
	ListNode* l = new ListNode(1);
	ListNode* l_2 = new ListNode(2);
	ListNode* l_3 = new ListNode(3);
	ListNode* l_4 = new ListNode(4);
	ListNode* l_5 = new ListNode(5);

	l->next = l_2;
	l_2->next = l_3;
	l_3->next = l_4;
	l_4->next = l_5;

	ListNode* digui = reverseList_digui(l);
	cout << "test2" << endl;
	ListNodeBianli(digui);

	//test end
	system("pause");
	return 0;
}