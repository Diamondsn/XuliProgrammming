#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//输入: 1->2->3->4->5->NULL, k = 2
//输出: 4->5->1->2->3->NULL
//解释:
//向右旋转 1 步: 5->1->2->3->4->NULL
//向右旋转 2 步: 4->5->1->2->3->NULL
//
//示例 2:
//输入: 0->1->2->NULL, k = 4
//输出: 2->0->1->NULL
//解释:
//向右旋转 1 步: 2->0->1->NULL
//向右旋转 2 步: 1->2->0->NULL
//向右旋转 3 步: 0->1->2->NULL
//向右旋转 4 步: 2->0->1->NULL

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//首先设立双指针，当快指针移动k步，移动中已经到达尾部，则根据k对长度的取余重新双指针
//双指针，只需调整分界处的指针指向
ListNode* rotateRight(ListNode* head, int k) {
	if (!head || k == 0)return head;
	int count = 0;
	ListNode* kuai=head, *man=head;
	while (kuai->next && count < k){
		kuai = kuai->next;
		count++;
	}
	if (count < k){
		k = k % (count + 1);
		if (k == 0)return head;
		kuai = head;
		count = 0;
		while (count<k){
			kuai = kuai->next;
			count++;
		}
	}
	while (kuai->next){
		kuai = kuai->next;
		man = man->next;
	}
	ListNode* newhead = man->next;
	man->next = NULL;
	kuai->next = head;
	return newhead;
}

//另解，只需一个指针，可用一个指针遍历到尾部，得到链表长度，k取余，将尾部指向头部，同时继续往下遍历长度-k步，得到新的头结点
//ListNode* rotateRight(ListNode* head, int k) {
//	if (head == NULL){
//		return head;
//	}
//	else if (head->next == NULL){
//		return head;
//	}
//	ListNode* p;
//	p = head;
//	int point = 0;
//	while (head->next){
//		point++;
//		head = head->next;
//	}
//	k = k % (point + 1);
//	head->next = p;
//	// head = head->next;
//	for (int i = 0; i<point - k; i++){
//		p = p->next;
//	}
//	head = p->next;
//	p->next = NULL;
//	return head;
//}

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
	ListNode* newhead = rotateRight(l1, 2);
	LianBiaoBianli(newhead);

	//test2
	cout << endl << "test2" << endl;
	ListNode* n0 = new ListNode(0);
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	n0->next = n1;
	n1->next = n2;
	ListNode* newhead1 = rotateRight(n0,4);
	LianBiaoBianli(newhead1);
	//test end

	system("pause");
	return 0;
}