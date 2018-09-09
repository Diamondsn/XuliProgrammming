#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//����һ�����������ҳ��������ȡ�
//
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
//
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//
//ʾ����
//����������[3, 9, 20, null, null, 15, 7]��
//
//  3
// / \
//9  20
//   / \
//  15   7
//�������������� 3 ��

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
	if (root == NULL)
		return 0;

	int left = 0;
	int right = 0;
	if (root->left != NULL)
		left = maxDepth(root->left);

	if (root->right != NULL)
		right = maxDepth(root->right);

	int max=left;
	if (max < right)
		max = right;

	return max+1;
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
	//tree1
	TreeNode* t = new TreeNode(3);
	TreeNode* t_39 = new TreeNode(9);
	TreeNode* t_20 = new TreeNode(20);
	TreeNode* t_15 = new TreeNode(15);
	TreeNode* t_7 = new TreeNode(7);

	t->left = t_39;
	t->right = t_20;
	t_20->left = t_15;
	t_20->right = t_7;

	//�ϲ���t����
	cout << "tǰ�����" << endl;
	Qianxubianli(t);//3,9,20,15,7
	cout << endl;

	cout << "t�������" << endl;
	Zhongxubianli(t);//9,3,15,20,7
	cout << endl;

	cout << "t�������" << endl;
	Houxubianli(t);//9,15,7,20,3
	cout << endl;

	int a = maxDepth(t);//3
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}