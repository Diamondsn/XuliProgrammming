#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<time.h>
#include<map>
#include<unordered_map>
#include<functional>
using namespace std;

//给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
//请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
//
//请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
//
//示例 1:
//输入: 1->2->3->4->5->NULL
//输出: 1->3->5->2->4->NULL
//
//示例 2:
//输入: 2->1->3->5->6->4->7->NULL 
//输出: 2->3->6->7->1->5->4->NULL
//
//说明:
//应当保持奇数节点和偶数节点的相对顺序。
//链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void LianBiaoBianLi(ListNode* head){
	while (head){
		cout << head->val << "->";
		head = head->next;
	}
	cout << endl;
}

ListNode* oddEvenList(ListNode* head) {

}

int main() {
	//test1
	ListNode* l = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	l->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	ListNode* res1 = oddEvenList(l);
	LianBiaoBianLi(res1);
	
	//test2
	cout << "test2" << endl;
	ListNode* n = new ListNode(2);
	ListNode* n1 = new ListNode(1);
	ListNode* n3 = new ListNode(3);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n4 = new ListNode(4);
	ListNode* n7 = new ListNode(7);
	n->next = n1;
	n1->next = n3;
	n3->next = n5;
	n5->next = n6;
	n6->next = n4;
	n4->next = n7;
	ListNode* res2 = oddEvenList(n);
	LianBiaoBianLi(res2);
	//test end
	system("pause");
	return 0;
}