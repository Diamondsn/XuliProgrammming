#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<time.h>
using namespace std;

//给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。
//
//进阶:
//如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？
//
//示例:
//// 初始化一个单链表 [1,2,3].
//ListNode head = new ListNode(1);
//head.next = new ListNode(2);
//head.next.next = new ListNode(3);
//Solution solution = new Solution(head);
//
//// getRandom()方法应随机返回1,2,3中的一个，保证每个元素被返回的概率相等。
//solution.getRandom();

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

//此题解法
//初解时不使用vector等额外存储空间计数
//2解是用存储空间存储之后常数时间取值
//class Solution {
//public:
//	/** @param head The linked list's head.
//	Note that the head is guaranteed to be not null, so it contains at least one node. */
//	Solution(ListNode* head) {
//		srand((unsigned)time(NULL));
//		m_head = head;
//		count = 0;
//		while (head){
//			count++;
//			head = head->next;
//		}
//	}
//
//	/** Returns a random node's value. */
//	int getRandom() {
//		int randnum = rand() % count;
//		ListNode* head = m_head;
//		while (randnum){
//			head=head->next;
//			randnum--;
//		}
//		return head->val;
//	}
//	int count;
//	ListNode* m_head;
//};


//进阶情况下当链表非常长无法存储所有数据在现有数据结构总
//同时也不能对链表中长度进行计算
//这时应该使用水塘抽样思想，也就是维护一个数，i从2开始，如果随机数能整除i则替换结果值，这种思想相当于维护一个大小为1的水塘
class Solution{
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		srand((unsigned)time(NULL));
		m_head = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		ListNode* head = m_head;
		int i = 2, res = head->val;
		head=head->next;
		while(head){
			if (rand() % i == 0)res = head->val;
			++i;
			head=head->next;
		}
		return res;
	}
	ListNode* m_head;
};


/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/

int main() {
	//test1
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	Solution* sol = new Solution(head);
	//以下统计概率;
	int m1 = 0, m2 = 0, m3 = 0,t;
	for (int i = 0; i < 30000; ++i){
		t = sol->getRandom();
		if (t == 1)m1++;
		else if (t == 2)m2++;
		else if (t == 3)m3++;
	}
	cout << (float)m1 / 30000.0 << endl << (float)m2 / 30000.0 << endl << (float)m3 / 30000.0 << endl;
	//test end
	system("pause");
	return 0;
}