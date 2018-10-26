#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//将两个有序链表合并为一个新的有序链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

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
	ListNode* l4 = new ListNode(4);
	l1->next = l2;
	l2->next = l4;

	ListNode* n1 = new ListNode(1);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	n1->next = n3;
	n3->next = n4;
	ListNode* newhead = mergeTwoLists(l1, n1);
	LianBiaoBianli(newhead);
	//test end

	system("pause");
	return 0;
}