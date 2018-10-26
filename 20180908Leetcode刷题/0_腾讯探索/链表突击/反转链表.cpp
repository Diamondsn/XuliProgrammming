#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//反转一个单链表。
//
//示例:
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL
//
//进阶:
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//递归解法
//ListNode* reverseList(ListNode* head) {
//	if (!head || !head->next)return head;
//	ListNode* newhead = reverseList(head->next);
//	ListNode* temp = newhead;
//	while (temp->next){
//		temp = temp->next;
//	}
//	temp->next = head;
//	head->next = NULL;
//	return newhead;
//}

//迭代解法,可使用栈辅助，也可使用双指针
ListNode* reverseList(ListNode* head){
	if (!head)return head;
	ListNode*pre = NULL, *cur = head, *next;
	while (cur){
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
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
	ListNode* newhead = reverseList(l1);
	LianBiaoBianli(newhead);
	//test end

	system("pause");
	return 0;
}