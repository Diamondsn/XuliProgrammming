#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//给定一个链表，判断链表中是否有环。
//
//进阶：
//你能否不使用额外空间解决此题？

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {

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
	l5->next = l3;
	bool a=hasCycle(l1);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}