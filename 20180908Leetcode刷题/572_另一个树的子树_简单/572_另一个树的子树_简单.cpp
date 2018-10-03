#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
//
//示例 1:
//给定的树 s:
//     3
//    / \
//   4   5
//  / \
// 1   2
//给定的树 t：
//
//   4 
//  / \
// 1   2
//返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
//
//示例 2:
//给定的树 s：
//
//     3
//    / \
//   4   5
//  / \
// 1   2
//    /
//   0
//给定的树 t：
//
//   4
//  / \
// 1   2
//返回 false。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSame(TreeNode* s, TreeNode* t) {
	if (!s && !t)return true;
	if (!s || !t)return false;
	if (s->val != t->val)return false;
	if (!isSame(s->left, t->left) || !isSame(s->right, t->right))return false;
	return true;
}

bool isSubtree(TreeNode* s, TreeNode* t) {
	if (!s && !t)return true;
	if (s == NULL)return false;
	if (s && s->val == t->val && isSame(s, t))return true;
	if (isSubtree(s->left, t) || isSubtree(s->right, t))return true;
	return false;
}

void Qianxubianli(TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	cout << pNode->val << " ,";
	Qianxubianli(pNode->left);
	Qianxubianli(pNode->right);
}

void Zhongxubianli(TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	Zhongxubianli(pNode->left);
	cout << pNode->val << " ,";
	Zhongxubianli(pNode->right);
}

void Houxubianli(TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	Houxubianli(pNode->left);
	Houxubianli(pNode->right);
	cout << pNode->val << " ,";
}

int main() {
	//test1
	TreeNode* n = new TreeNode(3);
	TreeNode* n_4 = new TreeNode(4);
	TreeNode* n_5 = new TreeNode(5);
	TreeNode* n_1 = new TreeNode(1);
	TreeNode* n_2 = new TreeNode(2);
	n->left = n_4;
	n->right = n_5;
	n_4->left = n_1;
	n_4->right = n_2;

	TreeNode* t = new TreeNode(4);
	TreeNode* t_1 = new TreeNode(1);
	TreeNode* t_2 = new TreeNode(2);
	t->left = t_1;
	t->right = t_2;

	bool a = isSubtree(n, t);

	//test2
	TreeNode* n_0 = new TreeNode(0);
	n_2->left = n_0;
	bool b = isSubtree(n, t);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}
