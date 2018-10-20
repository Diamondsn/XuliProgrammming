#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
//示例:
//给定 1->2->3->4, 你应该返回 2->1->4->3.
//
//说明:
//你的算法只能使用常数的额外空间。
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
	if (!head)return NULL;
	if (!head->next)return head;
	ListNode* n = new ListNode(0);
	ListNode* prehead = n;
	n->next = head;
	ListNode* one = head;
	ListNode* two=head->next;
	ListNode* three;
	while (two) {
		three = two->next;
		n->next = two;
		two->next = one;
		n = one;
		one = three;
		if (one == NULL) {
			break;
		}
		two = one->next;
	}
	n->next = one;
	return prehead->next;
}

void LianBiaoBianLi(ListNode* root) {
	while (root) {
		cout << root->val << "->";
		root = root->next;
	}
	cout << endl;
}

void main() {
	//test
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode*l4 = new ListNode(4);
	//l1->next = l2;
	//l2->next = l3;
	l3->next = l4;
	ListNode* res=swapPairs(l1);
	LianBiaoBianLi(res);
	//test end
	system("pause");
}
