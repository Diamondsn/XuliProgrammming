#include "stdafx.h"
#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//题目描述
//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
//示例：
//给定二叉树[3, 9, 20, null, null, 15, 7]，
//
//  3
// / \
//9  20
//   / \
//  15   7
//打印3,9,20,15,7

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> result;
	if (root == NULL)
		return result;
	
	deque<TreeNode*> mydeque;
	mydeque.push_back(root);
	while (!mydeque.empty())
	{
		TreeNode* pNode= mydeque.front();
		result.push_back(pNode->val);
		if (pNode->left)
			mydeque.push_back(pNode->left);
		if (pNode->right)
			mydeque.push_back(pNode->right);

		mydeque.pop_front();
	}
	return result;
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
	//test
	TreeNode* t = new TreeNode(3);
	TreeNode* t_39 = new TreeNode(9);
	TreeNode* t_20 = new TreeNode(20);
	TreeNode* t_15 = new TreeNode(15);
	TreeNode* t_7 = new TreeNode(7);

	t->left = t_39;
	t->right = t_20;
	t_20->left = t_15;
	t_20->right = t_7;

	vector<int> vec=PrintFromTopToBottom(t);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}