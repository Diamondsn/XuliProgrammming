#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<deque>
using namespace std;

//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//
//示例 1:
//输入: 1->1->2
//输出: 1->2
//
//示例 2:
//输入: 1->1->2->3->3
//输出: 1->2->3

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL)
		return NULL;
	ListNode* current = head;
	while (current)
	{
		if (current->next && current->next->val == current->val)
		{
			ListNode* pNode = current->next;
			current->next = current->next->next;
			delete pNode;
		}
		else 
		{
			current = current->next;
		}
	}
	return head;
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
		cout << "->"<<root->val;
		root = root->next;
	}
	cout << endl;
}

int main() {
	//test1
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(1);
	ListNode* l3 = new ListNode(2);
	l1->next = l2;
	l2->next = l3;

	ListNode* PNode = deleteDuplicates(l1);
	cout << "test1" << endl;
	LianBiaoBianLi(PNode);
	//test2
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(3);
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