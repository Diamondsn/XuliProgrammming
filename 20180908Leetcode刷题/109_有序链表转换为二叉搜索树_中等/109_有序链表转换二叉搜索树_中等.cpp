#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;

//给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
//
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//
//示例:
//给定的有序链表： [-10, -3, 0, 5, 9],
//一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

TreeNode* sortedListToBST(ListNode* head) {
	if (head == NULL)return NULL;
	ListNode* man = head;
	ListNode* kuai = head;
	ListNode* pre = NULL;
	while (kuai&&kuai->next)
	{
		kuai = kuai->next->next;
		pre = man;
		man = man->next;
	}
	TreeNode* root = new TreeNode(man->val);
	ListNode* lefthead = man==head?NULL:head;
	if (man!=head)
	     pre->next = NULL;
	ListNode* righthead = man->next;
	root->left = sortedListToBST(lefthead);
	root->right = sortedListToBST(righthead);
	return root;
}

void Qianxubianli(TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	cout << pNode->val << ",";
	Qianxubianli(pNode->left);
	Qianxubianli(pNode->right);
}

void Zhongxubianli(TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	Zhongxubianli(pNode->left);
	cout << pNode->val << ",";
	Zhongxubianli(pNode->right);
}

void Houxubianli(TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	Houxubianli(pNode->left);
	Houxubianli(pNode->right);
	cout << pNode->val << ",";
}

void LianBiaoBianLi(ListNode* root) {
	while (root) {
		cout << root->val << "->";
		root = root->next;
	}
}

int main() {
	//test1
	ListNode* l = new ListNode(-10);
	ListNode* l3 = new ListNode(-3);
	ListNode* l0 = new ListNode(0);
	ListNode* l5 = new ListNode(5);
	ListNode* l9 = new ListNode(9);
	l->next = l3;
	l3->next = l0;
	l0->next = l5;
	l5->next = l9;
	TreeNode* res = sortedListToBST(l);
	Zhongxubianli(res);//中序遍历结果应与链表值序列相同
	//test end

	system("pause");
	return 0;
}