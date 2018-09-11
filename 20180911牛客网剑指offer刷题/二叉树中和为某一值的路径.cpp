#include "stdafx.h"
#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//题目描述
//输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
//(注意: 在返回值的list中，数组长度大的数组靠前)
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

//快速排序
void kuaipai(vector<vector<int> >& vec)
{

}
//归并排序
void guibing(vector<vector<int> >& vec1, vector<vector<int> >& vec2, vector<vector<int> >& result)
{
	kuaipai(vec1);
	kuaipai(vec2);

}

vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	vector<vector<int> >result;
	vector<int> temp;
	if (root == NULL)
		return result;

	vector<vector<int> >left;
	vector<vector<int> >right;

	if (root->left)
		left=FindPath(root->left, expectNumber - root->val);
	if (root->right)
		right=FindPath(root->right, expectNumber - root->val);

	for (size_t i = 0; i < left.size(); ++i)
	{
		if (left[i].size() < 1)
			continue;

		left[i].push_back(left[i][left[i].size() - 1]);
		for (size_t j = left[i].size()-1; j >=1; --j)
		{
			left[i][j] = left[i][j - 1];
		}
		left[i][0] = root->val;
	}
	for (size_t i = 0; i < right.size(); ++i)
	{
		if (right[i].size() < 1)
			continue;

		right[i].push_back(right[i][right[i].size() - 1]);
		for (size_t j = right[i].size() - 1; j >= 1; --j)
		{
			right[i][j] = right[i][j - 1];
		}
		right[i][0] = root->val;
	}

	guibing(left, right, result);

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
	TreeNode* t = new TreeNode(5);
	TreeNode* t_1=new TreeNode(1);
	TreeNode* t_2 = new TreeNode(2);
	t->left = t_1;
	t->right = t_2;
	TreeNode* t_3 = new TreeNode(3);
	TreeNode* t_4 = new TreeNode(4);
	t_1->left = t_3;
	t_1->right = t_4;
	TreeNode* t_5 = new TreeNode(5);
	TreeNode* t_6 = new TreeNode(6);
	t_2->left = t_5;
	t_2->right = t_6;
	TreeNode* t_3_2 = new TreeNode(3);
	TreeNode* t_2_2 = new TreeNode(2);
	t_3->left = t_3_2;
	t_3->right = t_2_2;
	TreeNode* t_2_3 = new TreeNode(2);
	TreeNode* t_1_2 = new TreeNode(1);
	t_4->left = t_2_3;
	t_4->right = t_1_2;
	vector < vector<int> > result= FindPath(t,12);
	for (size_t i = 0; i < result.size(); ++i)
	{
		cout << "第" << i << "条路径为" << endl;
		for (size_t j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << "-";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}