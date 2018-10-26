#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
#include<map>
#include<set>
using namespace std;

//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//
//示例:
//输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (!l1)return l2;
	if (!l2)return l1;
	ListNode* newhead = l1->val <= l2->val ? l1 : l2;
	ListNode* pre = newhead;
	l1->val <= l2->val ? l1 = l1->next : l2 = l2->next;
	while (l1 || l2){
		if (!l1)
		{
			pre->next = l2;
			l2 = l2->next;
		}
		else if (!l2){
			pre->next = l1;
			l1 = l1->next;
		}
		else{
			pre->next = l1->val <= l2->val ? l1 : l2;
			l1->val <= l2->val ? l1 = l1->next : l2 = l2->next;
		}
		pre = pre->next;
	}
	return newhead;
}

/***************************/
//1解 逐条合并
/***************************/
//ListNode* mergeKLists(vector<ListNode*>& lists) {
//	if (lists.size() <= 0)return NULL;
//	if (lists.size() == 1)return lists[0];
//	ListNode* newhead = mergeTwoLists(lists[0], lists[1]);
//	for (int i = 2; i < lists.size(); ++i){
//		newhead = mergeTwoLists(newhead, lists[i]);
//	}
//	return newhead;
//}

/****************************/
//2解 两条合并一次,此种解法速度极快，呈对数级别
/****************************/
//ListNode* mergeKLists(vector<ListNode*>& lists){
//	if (lists.size() == 0)return NULL;
//	int start = 0, end = lists.size() - 1;
//	for (; end > 0;){
//		for (start = 0; start < end; ++start,--end){
//			lists[start] = mergeTwoLists(lists[start], lists[end]);
//		}
//	}
//	return lists[0];
//}

/***************************/
//3解 此种解法用到最小堆数据结构
/***************************/
//此比较函数需放在Solution类以外
struct cmp{
	bool operator()(ListNode* a, ListNode* b){
		return a->val>b->val;
	}
};

ListNode* mergeKLists(vector<ListNode*>& lists){
	priority_queue<ListNode*, vector<ListNode*>, cmp>q;
	for (int i = 0; i < lists.size(); ++i){
		if(lists[i])q.push(lists[i]);
	}
	ListNode* head = NULL, *pre = NULL, *tmp = NULL;
	while (!q.empty()){
		tmp = q.top();
		q.pop();
		if (!pre)head = tmp;
		else pre->next = tmp;
		pre = tmp;
		if (tmp->next)q.push(tmp->next);
	}
	return head;
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
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	l1->next = l4;
	l4->next = l5;

	ListNode* n1 = new ListNode(1);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	n1->next = n3;
	n3->next = n4;

	ListNode* d2 = new ListNode(2);
	ListNode* d6 = new ListNode(6);
	d2->next = d6;
	vector <ListNode*>lists= {l1, n1, d2};
	ListNode* newhead = mergeKLists(lists);
	LianBiaoBianli(newhead);
	//test end

	system("pause");
	return 0;
}