#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdint.h>
using namespace std;

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
//
//示例 1：
//输入：[1, 2, 3, 4, 5]
//输出：此列表中的结点 3 (序列化形式：[3, 4, 5])
//返回的结点值为 3 。(测评系统对该结点序列化表述是[3, 4, 5])。
//注意，我们返回了一个 ListNode 类型的对象 ans，这样：
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
//
//示例 2：
//输入：[1, 2, 3, 4, 5, 6]
//输出：此列表中的结点 4 (序列化形式：[4, 5, 6])
//由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
//
//提示：
//给定链表的结点数介于 1 和 100 之间。

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
	ListNode* kuai = head;
	ListNode* man = head;
	while (kuai && kuai->next)
	{
			kuai = kuai->next;
		if (kuai && kuai->next)
			kuai = kuai->next;

		if (man && man->next)
			man = man->next;
	}
	return man;
}

void ListNodeBianLi(ListNode* root)
{
	while (root)
	{
		cout << root->val << endl;
		root = root->next;
	}
}
void main() {
	//test1
	ListNode*n1 = new ListNode(1);
	ListNode*n2 = new ListNode(2);
	ListNode*n3 = new ListNode(3);
	ListNode*n4 = new ListNode(4);
	ListNode*n5 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	ListNode* result1 = middleNode(n1);

	ListNode*l1 = new ListNode(1);
	ListNode*l2 = new ListNode(2);
	ListNode*l3 = new ListNode(3);
	ListNode*l4 = new ListNode(4);
	ListNode*l5 = new ListNode(5);
	ListNode*l6 = new ListNode(6);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;

	ListNode* result2 = middleNode(l1);

	cout << "test1" << endl;
	ListNodeBianLi(result1);
	cout << "test2" << endl;
	ListNodeBianLi(result2);
	//test end
	system("pause");
}
