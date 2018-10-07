#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
//
//注意：两个节点之间的路径长度由它们之间的边数表示。
//
//示例 1:
//输入:
//
//              5
//             / \
//            4   5
//           / \   \
//          1   1   5
//输出:
//2
//
//示例 2:
//输入:
//
//              1
//             / \
//            4   5
//           / \   \
//          4   4   5
//输出:
//2
//
//注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int longestUnivaluePath(TreeNode* root) {
	if (root == NULL)return 0;
	int left = 0, right = 0;
	if (root->left && root->left->val == root->val)
		left = longestUnivaluePath(root->left);
	if (root->right && root->right->val == root->val)
		right = longestUnivaluePath(root -> right);

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
	TreeNode* t = new TreeNode(5);
	TreeNode* t_4 = new TreeNode(4);
	TreeNode* t_5_1 = new TreeNode(5);
	TreeNode* t_1_1 = new TreeNode(1);
	TreeNode* t_1_2 = new TreeNode(1);
	TreeNode* t_5_2 = new TreeNode(5);

	t->left = t_4;
	t->right = t_5_1;
	t_4->left = t_1_1;
	t_4->right = t_1_2;
	t_5_1->right = t_5_2;

	int a = longestUnivaluePath(t);//2

	//test2
	TreeNode* n = new TreeNode(1);
	TreeNode* n_4_1 = new TreeNode(4);
	TreeNode* n_5_1 = new TreeNode(5);
	TreeNode* n_4_2 = new TreeNode(4);
	TreeNode* n_4_3 = new TreeNode(4);
	TreeNode* n_5_2 = new TreeNode(5);

	n->left = n_4_1;
	n->right = n_5_1;
	n_4_1->left = n_4_2;
	n_4_1->right = n_4_3;
	n_5_1->right = n_5_2;

	int b = longestUnivaluePath(n);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}