#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//给定二叉树 [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回它的最小深度  2.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
	if (root == NULL)return 0;
	if (root->left == NULL && root->right == NULL)return 1;
	int min, left=INT_MAX, right=INT_MAX;
	if(root->left)
	left = minDepth(root->left);
	if(root->right)
	right = minDepth(root->right);
	min = left < right?left + 1 : right + 1;
	return min;
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
	TreeNode* t = new TreeNode(3);
	TreeNode* t_9 = new TreeNode(9);
	TreeNode* t_20 = new TreeNode(20);
	TreeNode* t_15 = new TreeNode(15);
	TreeNode* t_7 = new TreeNode(7);
	t ->left=t_9;
	t->right = t_20;
	t_20->left = t_15;
	t_20->right = t_7;

	int a = minDepth(t);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}