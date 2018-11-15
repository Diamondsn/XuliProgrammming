#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdint.h>
using namespace std;

//给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
//
//每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
//
//这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
//
//返回一个符合上述规则的链表的列表。
//
//举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
//
//示例 1：
//输入: 
//root = [1, 2, 3], k = 5
//输出: [[1],[2],[3],[],[]]
//解释:
//输入输出各部分都应该是链表，而不是数组。
//例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且 root.next.next.next = null。
//第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
//最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。
//
//示例 2：
//输入: 
//root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
//输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
//解释:
//输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
//
//提示:
//
//root 的长度范围：[0, 1000].
//输入的每个节点的大小范围：[0, 999].
//k 的取值范围：[1, 50].

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode*> splitListToParts(ListNode* root, int k) {
	int num = 0;
	ListNode* temp = root;
	while (temp){
		num++;
		temp = temp->next;
	}
	vector<ListNode*>res(k,NULL);
	if (num == 0)
	{
		res.resize(k, NULL);
		return res;
	}
	vector<int>nums(k, num/k);
	for (int i=0; i < num%k; ++i){
		nums[i]++;
	}
	ListNode* prev = NULL,*cur=root;
	for (int i = 0; i < nums.size(); ++i){
		if (nums[i] == 0)
			break;
		res[i] = cur;
		while (nums[i]){
			prev = cur;
			cur = cur->next;
			nums[i]--;
		}
		prev->next = NULL;
	}
	return res;
}

void ListNodeBianLi(ListNode* root)
{
	if (!root)
	{
		cout << endl;
		return;
	}
	cout << root->val;
	root = root->next;
	while (root)
	{
		cout <<"->"<< root->val;
		root = root->next;
	}
	cout << endl;
}

void main() {
	//test1
	ListNode* l = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	l->next = l2;
	l2->next = l3;
	vector<ListNode*>res = splitListToParts(l,5);
	for (ListNode* node : res)
		ListNodeBianLi(node);

	//test2
	ListNode* n = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n7 = new ListNode(7);
	ListNode* n8 = new ListNode(8);
	ListNode* n9 = new ListNode(9);
	ListNode* n10 = new ListNode(10);
	n->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;
	n9->next = n10;
	vector<ListNode*>res1 = splitListToParts(n, 3);
	for (ListNode* node : res1)
		ListNodeBianLi(node);
	//test end
	system("pause");
}
