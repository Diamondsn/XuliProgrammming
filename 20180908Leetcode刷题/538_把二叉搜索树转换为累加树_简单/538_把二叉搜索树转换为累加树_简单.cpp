#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，
//使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
//例如：
//
//输入: 二叉搜索树:
//              5
//            /   \
//           2     13
//
//输出: 转换为累加树:
//             18
//            /   \
//          20     13


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void convert(TreeNode* root, int& sum)
{
	if (!root)
		return;
	convert(root->right, sum);
	root->val += sum;
	sum = root->val;
	convert(root->left, sum);
}

//注意:此题采用的是二叉搜索树
TreeNode* convertBST(TreeNode* root) {
	int sum = 0;
	convert(root, sum);
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
	TreeNode* n = new TreeNode(5);
	TreeNode* n_2 = new TreeNode(2);
	TreeNode* n_13 = new TreeNode(13);
	TreeNode* n_1 = new TreeNode(1);
	TreeNode* n_3 = new TreeNode(3);
	n->left = n_2;
	n->right = n_13;

	TreeNode* pNode = convertBST(n);
	Qianxubianli(pNode);//18,20,13

	//test2
	TreeNode* t = new TreeNode(2);
	TreeNode* t_0 = new TreeNode(0);
	TreeNode* t_3 = new TreeNode(3);
	TreeNode* t_4 = new TreeNode(-4);
	TreeNode* t_1 = new TreeNode(1);
	t->left = t_0;
	t->right = t_3;
	t_0->left = t_4;
	t_0->right = t_1;


	TreeNode* pNode1=convertBST(t);
	Qianxubianli(pNode1);//5,6,2,6,3

	//test end

	system("pause");
	return 0;
}
