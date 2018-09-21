#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//计算给定二叉树的所有左叶子之和。
//
//示例：
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root)
{
	if (!root)
		return false;

	if (!root->left && !root->right)
		return true;

	return false;
}
int sumOfLeftLeaves(TreeNode* root) {
	if (!root)
		return 0;
	int sum = 0;
	if (root->left && isLeaf(root->left))
		sum += root->left->val;

	sum += sumOfLeftLeaves(root->left);
	sum += sumOfLeftLeaves(root->right);
	return sum;
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

	t->left = t_9;
	t->right = t_20;
	t_20->left = t_15;
	t_20->right = t_7;

	int a = sumOfLeftLeaves(t);//24
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}