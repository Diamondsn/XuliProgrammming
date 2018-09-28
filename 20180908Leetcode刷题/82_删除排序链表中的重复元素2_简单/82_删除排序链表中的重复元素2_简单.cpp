#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<deque>
using namespace std;

//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
//
//示例 1:
//输入: 1->2->3->3->4->4->5
//输出: 1->2->5
//
//示例 2:
//输入: 1->1->1->2->3
//输出: 2->3

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//此题参考了https://blog.csdn.net/qq_17550379/article/details/80668036
ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL)
		return NULL;
	
	ListNode* newhead = new ListNode(0);
	newhead->next = head;
	ListNode* prev = newhead;
	ListNode* cur = prev->next;
	while (cur){
		while (cur->next && cur->next->val == cur->val)cur = cur->next;
		if (cur != prev->next)prev->next = cur->next;
		else prev = cur;

		cur = cur->next;
	}
	return newhead->next;
}

void LianBiaoBianLi(ListNode* root)
{
	if (!root)
		return;
	if (root)
	{
		cout << root->val;
		root = root->next;
	}

	while (root)
	{
		cout << "->" << root->val;
		root = root->next;
	}
	cout << endl;
}

int main() {
	//test1
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(3);
	ListNode* l5 = new ListNode(4);
	ListNode* l6 = new ListNode(4);
	ListNode* l7 = new ListNode(5);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;

	ListNode* PNode = deleteDuplicates(l1);
	cout << "test1" << endl;
	LianBiaoBianLi(PNode);
	//test2
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(1);
	ListNode* n4 = new ListNode(2);
	ListNode* n5 = new ListNode(3);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	ListNode* node = deleteDuplicates(n1);
	cout << "test2" << endl;
	LianBiaoBianLi(node);
	//test end

	system("pause");
	return 0;
}