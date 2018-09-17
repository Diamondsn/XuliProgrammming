#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//请判断一个链表是否为回文链表。
//
//示例 1:
//
//输入: 1->2
//输出: false
//
//示例 2:
//输入: 1->2->2->1
//输出: true
//
//进阶：
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
	if (head == NULL)
		return true;

	//首先找到最中间的指针
	ListNode* kuai=head;
	ListNode* man=head;
	while (kuai && kuai->next)
	{
		kuai = kuai->next->next;
		man = man->next;
	}

	ListNode* middle = man;

	//反转后续链表
	ListNode* prev = NULL;
	ListNode* cur = middle;
	ListNode* next = cur->next;
	while (next)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		next = cur->next;
	}
	cur->next = prev;

	while (head && cur)
	{
		if (head->val != cur->val)
			return false;

		head = head->next;
		cur = cur->next;
	}
	return true;
}

void output(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
}

void main(){
	//test1
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	l1->next = l2;
	cout << "l1序列为" << endl;
	output(l1);
	bool a = isPalindrome(l1);

	//test2
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(1);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	cout << "l2序列为" << endl;
	output(n1);
	bool b = isPalindrome(n1);
	cout << "结果" << endl;
	cout <<a << b << endl;
	//test end
	system("pause");
}
