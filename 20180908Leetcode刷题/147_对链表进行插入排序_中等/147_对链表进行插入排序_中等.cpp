#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;


//对链表进行插入排序。
//
//动画链接 : https ://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif
//
//插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
//每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
//
//插入排序算法：
//插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//重复直到所有输入数据插入完为止。
//
//示例 1：
//输入: 4->2->1->3
//输出: 1->2->3->4
//
//示例 2：
//输入: -1->5->3->4->0
//输出: -1->0->3->4->5

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void ListNodeBianli(ListNode* head)
{
	while (head)
	{
		cout << head->val << ",";
		head = head->next;
	}
	cout << endl;
}

ListNode* insertionSortList(ListNode* head) {

}

int main() {
	//test1
	ListNode* l4 = new ListNode(4);
	ListNode* l2 = new ListNode(2);
	ListNode* l1 = new ListNode(1);
	ListNode* l3 = new ListNode(3);
	l4->next = l2;
	l2->next = l1;
	l1->next = l3;

	ListNode* res = insertionSortList(l4);
	ListNodeBianli(res);

	//test2
	cout << "test2" << endl;
	ListNode* n1 = new ListNode(-1);
	ListNode* n5 = new ListNode(5);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n0 = new ListNode(0);
	n1->next = n5;
	n5->next = n3;
	n3->next = n4;
	n4->next = n0;
	ListNode* res1 = insertionSortList(n1);
	ListNodeBianli(res1);
	//test end
	system("pause");
	return 0;
}