#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例: 
//给定如下二叉树，以及目标和 sum = 22，
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1
//返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int sum) {
	if (!root)
		return false;

	if (!root->left && !root->right && root->val == sum)
		return true;

	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
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
	TreeNode* t_4_1 = new TreeNode(4);
	TreeNode* t_8 = new TreeNode(8);
	TreeNode* t_11 = new TreeNode(11);
	TreeNode* t_13 = new TreeNode(13);
	TreeNode* t_4_2 = new TreeNode(4);
	TreeNode* t_7 = new TreeNode(7);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_1 = new TreeNode(1);

	t->left = t_4_1;
	t->right = t_8;
	t_4_1->left = t_11;
	t_8->left = t_13;
	t_8->right = t_4_2;
	t_11->left = t_7;
	t_11->right = t_2;
	t_4_2->right = t_1;

	bool a = hasPathSum(t,22);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}