﻿#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，
//它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
//
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
//示例：
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

}

void LianBiaoBianli(ListNode* head){
	while (head){
		cout << head->val << "->";
		head = head->next;
	}
}

int main() {
	//test1
	ListNode* l2 = new ListNode(2);
	ListNode* l4 = new ListNode(4);
	ListNode* l3 = new ListNode(3);
	l2->next = l4;
	l4->next = l3;

	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n4 = new ListNode(4);
	n5->next = n6;
	n6->next = n4;
	ListNode* newhead = addTwoNumbers(l2,n5);
	LianBiaoBianli(newhead);
	//test end

	system("pause");
	return 0;
}