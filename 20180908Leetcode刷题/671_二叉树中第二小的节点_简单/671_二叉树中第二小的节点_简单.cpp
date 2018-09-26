#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<deque>
using namespace std;

//给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
//
//给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
//
//示例 1:
//输入: 
//    2
//   / \
//  2   5
//     / \
//    5   7
//输出: 5
//说明: 最小的值是 2 ，第二小的值是 5 。
//
//示例 2:
//输入: 
//    2
//   / \
//  2   2
//输出: -1
//
//说明: 最小的值是 2, 但是不存在第二小的值。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findSecondMinimumValue(TreeNode* root) {
	if (!root)
		return -1;
	int min = root->val,res=INT_MAX;
	deque<TreeNode*>mydeque;
	mydeque.push_back(root);
	while (!mydeque.empty())
	{
		TreeNode* pNode = mydeque.front();
		mydeque.pop_front();

		if (pNode->val > min && pNode->val < res)
		{
			res = pNode->val;
		}
		if (pNode->left)
			mydeque.push_back(pNode->left);
		if (pNode->right)
			mydeque.push_back(pNode->right);
	}
	if (res == INT_MAX)
		return -1;
	else
		return res;
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
	TreeNode* t = new TreeNode(2);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_5_1 = new TreeNode(5);
	TreeNode* t_5_2 = new TreeNode(5);
	TreeNode* t_7 = new TreeNode(7);

	t->left = t_2;
	t->right = t_5_1;
	t_5_1->left = t_5_2;
	t_5_1->right = t_7;

	int a = findSecondMinimumValue(t);

	//test2
	TreeNode* n = new TreeNode(2);
	TreeNode* n_2_1 = new TreeNode(2);
	TreeNode* n_2_2 = new TreeNode(2);
	n->left = n_2_1;
	n->right = n_2_2;

	int b = findSecondMinimumValue(n);
	cout << a << endl<<b<<endl;
	//test end

	system("pause");
	return 0;
}