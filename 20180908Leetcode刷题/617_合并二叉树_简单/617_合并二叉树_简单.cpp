#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
//
//你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，
//否则不为 NULL 的节点将直接作为新二叉树的节点。
//
//示例 1:
//
//输入:
//Tree 1                     Tree 2
//   1                         2
//  / \                       / \
// 3   2                     1   3
///                           \   \
//5                             4   7
//输出:
//合并后的树:
//   3
//  / \
// 4   5
/// \   \
//5   4   7
//
//注意: 合并必须从两个树的根节点开始。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	if (t1 == NULL && t2 == NULL)
		return NULL;

	TreeNode* pNode=new TreeNode(0);
	if (t1 == NULL && t2 != NULL)
	{
		pNode->val = t2->val;
		pNode->left = mergeTrees(NULL, t2->left);
		pNode->right = mergeTrees(NULL, t2->right);
	}
	else if (t1 != NULL && t2 == NULL)
	{
		pNode->val = t1->val;
		pNode->left = mergeTrees(t1->left, NULL);
		pNode->right = mergeTrees(t1->right, NULL);
	}
	else
	{
		pNode->val = t1->val + t2->val;
		pNode->left = mergeTrees(t1->left, t2->left);
		pNode->right = mergeTrees(t1->right, t2->right);
	}
	return pNode;
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
	cout << pNode->val<<" ,";
}

int main() {
	//test1
	//tree1
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t1_3 = new TreeNode(3);
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_5 = new TreeNode(5);

	t1->left = t1_3;
	t1->right = t1_2;
	t1_3->left = t1_5;

	//tree2
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t2_1 = new TreeNode(1);
	TreeNode* t2_3 = new TreeNode(3);
	TreeNode* t2_4 = new TreeNode(4);
	TreeNode* t2_7 = new TreeNode(7);
	t2->left = t2_1;
	t2->right = t2_3;
	t2_1->right = t2_4;
	t2_3->right = t2_7;

	//t1遍历
	cout << "t1前序遍历" << endl;
	Qianxubianli(t1);//1,3,5,2
	cout << endl;

	cout << "t1中序遍历" << endl;
	Zhongxubianli(t1);//5,3,1,2
	cout << endl;

	cout << "t1后序遍历" << endl;
	Houxubianli(t1);//5,3,2,1
	cout << endl;

	//t2遍历
	cout << "t2前序遍历" << endl;
	Qianxubianli(t2);//2,1,4,3,7
	cout << endl;

	cout << "t2中序遍历" << endl;
	Zhongxubianli(t2);//1,4,2,3,7
	cout << endl;

	cout << "t2后序遍历" << endl;
	Houxubianli(t2);//4,1,7,3,2
	cout << endl;

	//合并树
	TreeNode* t=mergeTrees(t1, t2);

	//合并树t遍历
	cout << "t前序遍历" << endl;
	Qianxubianli(t);//3,4,5,4,5,7
	cout << endl;

	cout << "t中序遍历" << endl;
	Zhongxubianli(t);//5,4,4,3,5,7
	cout << endl;

	cout << "t后序遍历" << endl;
	Houxubianli(t);//5,4,4,7,5,3
	cout << endl;
	//test end

	system("pause");
	return 0;
}