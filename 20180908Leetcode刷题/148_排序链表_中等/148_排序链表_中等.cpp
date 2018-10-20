#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
//
//示例 1:
//输入: 4->2->1->3
//输出: 1->2->3->4
//
//示例 2:
//输入: -1->5->3->4->0
//输出: -1->0->3->4->5

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* head) {
	if (!head || !head->next)return head;
	ListNode* pivot = head,*lefthead=NULL,*left=NULL,*righthead=NULL,*right=NULL,*temp,*newhead;
	head = head->next;
	while (head) {
		if (head->val <= pivot->val)
		{
			if (lefthead == NULL) {
				lefthead = head;
				left = head;
			}
			else
			{
				left->next = head;
				left = left->next;
			}
		}
		else {
			if (righthead == NULL) {
				righthead = head;
				right = head;
			}
			else {
				right->next = head;
				right = right->next;
			}
		}
		temp= head->next;
		head->next = NULL;
		head = temp;
	}
	ListNode* leftres = sortList(lefthead);
	ListNode* rightres = sortList(righthead);
	if (!leftres) {
		newhead = pivot;
	}
	else {
		newhead = leftres;
		temp = leftres;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = pivot;
	}

	pivot->next = rightres;
	return newhead;
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
	ListNode* l4 = new ListNode(4);
	ListNode* l2 = new ListNode(2);
	ListNode* l1 = new ListNode(1);
	ListNode*l3= new ListNode(3);
	l4->next = l2;
	l2->next = l1;
	l1->next = l3;
	ListNode* res = sortList(l4);
	LianBiaoBianLi(res);

	//test2
	cout << "test2" << endl;
	ListNode* n1 = new ListNode(-1);
	ListNode* n5 = new ListNode(5);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n0 = new ListNode(0);
	n1->next = n5;
	n5->next = n3;
	n3->next = n4;
	n4->next = n0;
	ListNode* res1 = sortList(n1);
	LianBiaoBianLi(res1);
	//test end
	system("pause");
}
