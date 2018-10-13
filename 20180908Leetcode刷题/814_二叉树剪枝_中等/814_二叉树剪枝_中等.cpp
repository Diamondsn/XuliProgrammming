#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。
//
//返回移除了所有不包含 1 的子树的原二叉树。
//
//( 节点 X 的子树为 X 本身，以及所有 X 的后代。)
//
//示例1:
//输入: [1,null,0,0,1]
//输出: [1,null,0,null,1]
// 
//解释: 
//只有红色节点满足条件“所有不包含 1 的子树”。
//右图为返回的答案。
//
//示例2:
//输入: [1,0,1,0,0,0,1]
//输出: [1,null,1,null,1]
//
//示例3:
//输入: [1,1,0,1,1,0,1,0]
//输出: [1,1,0,1,1,null,1]
//
//说明:
//给定的二叉树最多有 100 个节点。
//每个节点的值只会为 0 或 1 。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isOnlyContain0(TreeNode* root) {
	if (root && root->val==1)return false;
	if (!root)return true;
	if (isOnlyContain0(root->left) && isOnlyContain0(root->right))
		return true;
	return false;
}

TreeNode* pruneTree(TreeNode* root) {
	if (isOnlyContain0(root))return NULL;
	if (isOnlyContain0(root->left))
		root->left = NULL;
	else
		pruneTree(root->left);
	if (isOnlyContain0(root->right))
		root->right = NULL;
	else
		pruneTree(root->right);

	return root;
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
	TreeNode* n = new TreeNode(1);
	TreeNode* n_0_1 = new TreeNode(0);
	TreeNode* n_0_2 = new TreeNode(0);
	TreeNode* n_1 = new TreeNode(1);
	n->right = n_0_1;
	n_0_1->left = n_0_2;
	n_0_1->right = n_1;

	TreeNode* res1 = pruneTree(n);
	Qianxubianli(res1);

	//test2
	cout << endl << "test2" << endl;
	TreeNode* t = new TreeNode(1);
	TreeNode* t_0_1 = new TreeNode(0);
	TreeNode* t_0_2 = new TreeNode(0);
	TreeNode* t_0_3 = new TreeNode(0);
	TreeNode* t_1_1 = new TreeNode(1);
	TreeNode* t_0_4 = new TreeNode(0);
	TreeNode* t_1_2 = new TreeNode(1);
	t->left = t_0_1;
	t->right = t_1_1;
	t_0_1->left = t_0_2;
	t_0_1->right = t_0_3;
	t_1_1->left = t_0_4;
	t_1_1->right = t_1_2;
	TreeNode* res2 = pruneTree(t);
	Qianxubianli(res2);

	//test3
	cout << endl << "test3" << endl;
	TreeNode* tree = new TreeNode(1);
	TreeNode* tree_1_1 = new TreeNode(1);
	TreeNode* tree_0_1 = new TreeNode(0);
	TreeNode* tree_1_2 = new TreeNode(1);
	TreeNode* tree_1_3 = new TreeNode(1);
	TreeNode* tree_0_2 = new TreeNode(0);
	TreeNode* tree_1_4 = new TreeNode(1);
	TreeNode* tree_0_3 = new TreeNode(0);
	tree->left = tree_1_1;
	tree->right = tree_0_1;
	tree_1_1->left = tree_1_2;
	tree_1_1->right = tree_1_3;
	tree_0_1->left = tree_0_2;
	tree_0_1->right = tree_1_4;
	tree_1_2->left = tree_0_3;
	TreeNode* res3 = pruneTree(tree);
	Qianxubianli(res3);
	//test end

	system("pause");
	return 0;
}