#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//给定一个链表，判断链表中是否有环。
//
//进阶：
//你能否不使用额外空间解决此题？

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
	if (!head)return false;
	ListNode* kuai = head;ListNode* man = head;
	while (kuai&&kuai->next) {
		kuai = kuai->next->next;
		man = man->next;
		if (kuai == man)return true;
	}
	return false;
}

void main() {
	//test
	ListNode* head = new ListNode(4);
	ListNode* n_5 = new ListNode(5);
	ListNode* n_1 = new ListNode(1);
	ListNode* n_9 = new ListNode(9);
	head->next = n_5;
	n_5->next = n_1;
	n_1->next = n_9;
	n_9->next = head;
	bool a = hasCycle(head);
	cout <<a << endl;
	//test end
	system("pause");
}
