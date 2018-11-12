#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<unordered_set>
#include"time.h"
using namespace std;

//给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
//
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
//进阶:
//如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
//
//示例:
//输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出: 7 -> 8 -> 0 -> 7

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	stack<ListNode*>s1, s2;
	while (l1){
		s1.push(l1);
		l1 = l1->next;
	}
	while (l2){
		s2.push(l2);
		l2 = l2->next;
	}
	int jinwei = 0;
	ListNode* res=NULL,*cur=NULL;
	while (!s1.empty() || !s2.empty()){
		ListNode* n1 = new ListNode(0),*n2=new ListNode(0);
		if (!s1.empty())
		{
			n1 = s1.top();
			s1.pop();
		}
		if (!s2.empty()){
			n2 = s2.top();
			s2.pop();
		}
		res = new ListNode((n1->val + n2->val + jinwei)%10);
		jinwei = (n1->val + n2->val + jinwei) / 10;
		res->next = cur;
		cur = res;
	}
	if (jinwei){
		res = new ListNode(jinwei);
		res->next = cur;
	}
	return res;
}

void main(){
	//test1
	ListNode*l7 = new ListNode(7);
	ListNode* l2 = new ListNode(2);
	ListNode* l4 = new ListNode(4);
	ListNode* l3 = new ListNode(3);
	l7->next = l2;
	l2->next = l4;
	l4->next = l3;

	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n4 = new ListNode(4);
	n5->next = n6;
	n6->next = n4;

	ListNode* res = addTwoNumbers(l7, n5);
	LianBiaoBianLi(res);

	//test end
	system("pause");
}
