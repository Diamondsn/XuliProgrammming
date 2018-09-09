#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//���������������������㽫�����е�һ�����ǵ���һ����ʱ��������������һЩ�ڵ����ص���
//
//����Ҫ�����Ǻϲ�Ϊһ���µĶ��������ϲ��Ĺ�������������ڵ��ص�����ô�����ǵ�ֵ�����Ϊ�ڵ�ϲ������ֵ��
//����Ϊ NULL �Ľڵ㽫ֱ����Ϊ�¶������Ľڵ㡣
//
//ʾ�� 1:
//
//����:
//Tree 1                     Tree 2
//   1                         2
//  / \                       / \
// 3   2                     1   3
///                           \   \
//5                             4   7
//���:
//�ϲ������:
//   3
//  / \
// 4   5
/// \   \
//5   4   7
//
//ע��: �ϲ�������������ĸ��ڵ㿪ʼ��

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

	//t1����
	cout << "t1ǰ�����" << endl;
	Qianxubianli(t1);//1,3,5,2
	cout << endl;

	cout << "t1�������" << endl;
	Zhongxubianli(t1);//5,3,1,2
	cout << endl;

	cout << "t1�������" << endl;
	Houxubianli(t1);//5,3,2,1
	cout << endl;

	//t2����
	cout << "t2ǰ�����" << endl;
	Qianxubianli(t2);//2,1,4,3,7
	cout << endl;

	cout << "t2�������" << endl;
	Zhongxubianli(t2);//1,4,2,3,7
	cout << endl;

	cout << "t2�������" << endl;
	Houxubianli(t2);//4,1,7,3,2
	cout << endl;

	//�ϲ���
	TreeNode* t=mergeTrees(t1, t2);

	//�ϲ���t����
	cout << "tǰ�����" << endl;
	Qianxubianli(t);//3,4,5,4,5,7
	cout << endl;

	cout << "t�������" << endl;
	Zhongxubianli(t);//5,4,4,3,5,7
	cout << endl;

	cout << "t�������" << endl;
	Houxubianli(t);//5,4,4,7,5,3
	cout << endl;
	//test end

	system("pause");
	return 0;
}