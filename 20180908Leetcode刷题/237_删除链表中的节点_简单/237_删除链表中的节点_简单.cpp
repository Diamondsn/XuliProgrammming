#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
//
//现有一个链表 -- head = [4, 5, 1, 9]，它可以表示为:
//
//4 -> 5 -> 1 -> 9
//示例 1 :
//输入 : head = [4, 5, 1, 9], node = 5
//输出 : [4, 1, 9]
//解释 : 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
//	
//示例 2 :
//输入 : head = [4, 5, 1, 9], node = 1
//输出 : [4, 5, 9]
//解释 : 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
//	
//说明 :
//链表至少包含两个节点。
//链表中所有节点的值都是唯一的。
//给定的节点为非末尾节点并且一定是链表中的一个有效节点。
//不要从你的函数中返回任何结果。

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}

//class Solution {
//public:
//	void deleteNode(ListNode* node) {
//		if (this->head->val == node->val)
//		{
//			this->head->val = this->head->next->val;
//			this->head->next = this->head->next->next;
//			//head = head->next;//直接修改指针不能传到函数外
//			return;
//		}
//
//		ListNode* temp = this->head;
//		while (temp != NULL && temp->next != NULL && temp->next->val != node->val)
//		{
//			temp = temp->next;
//		}
//		temp->next = temp->next->next;
//	}
//
//	ListNode* head;
//};
void ListBianli(ListNode* node)
{
	ListNode* temp = node;
	while (temp)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}
}
void main() {
	//test
	ListNode* head = new ListNode(4);
	ListNode* n_5 = new ListNode(5);
	ListNode* n_1 = new ListNode(1);
	ListNode* n_9 = new ListNode(9);
	head->next = n_5;
	n_5->next = n_1;
	n_1->next = n_9;

	//此为solution类中有成员函数版本
	/*Solution s;
	s.head = head;
	s.deleteNode(n_5);

	ListBianli(s.head);*/

	//正解

	//test end
	system("pause");
}
