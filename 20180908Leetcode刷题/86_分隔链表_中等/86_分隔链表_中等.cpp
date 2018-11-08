#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
using namespace std;

//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//
//你应当保留两个分区中每个节点的初始相对位置。
//
//示例:
//输入: head = 1->4->3->2->5->2, x = 3
//输出: 1->2->2->4->3->5

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
ListNode* partition(ListNode* head, int x) {
	ListNode* left = new ListNode(0),*leftcur=left;
	ListNode* right = new ListNode(0), *rightcur = right;
	while (head){
		if (head->val < x){
			leftcur->next = head;
			leftcur = head;
		}
		else{
			rightcur->next = head;
			rightcur = head;
		}
		head = head->next;
	}
	rightcur->next = NULL;
	leftcur->next = right->next;
	return left->next;
}

int main() {
	//test1
	ListNode* head = new ListNode(1);
	ListNode* l4 = new ListNode(4);
	ListNode* l3 = new ListNode(3);
	ListNode* l2 = new ListNode(2);
	ListNode* l5 = new ListNode(5);
	ListNode* l2_2 = new ListNode(2);
	head->next = l4;
	l4->next = l3;
	l3->next = l2;
	l2->next = l5;
	l5->next = l2_2;
	ListNode* newhead = partition(head,3);
	LianBiaoBianLi(newhead);
	//test end
	system("pause");
	return 0;
}