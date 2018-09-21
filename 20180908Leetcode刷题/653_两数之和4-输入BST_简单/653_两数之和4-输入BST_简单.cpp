#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
#include<map>
#include<stack>
using namespace std;

//给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
//
//案例 1:
//输入: 
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 9
//输出: True
// 
//案例 2:
//输入: 
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 28
//输出: False

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool findTarget(TreeNode* root, int k) {
	if (!root)
		return false;
	vector<int>record;
	stack<TreeNode*>mystack;
	mystack.push(root);
	while (!mystack.empty())
	{
		TreeNode* pNode=mystack.top();
		mystack.pop();
		if (find(record.begin(), record.end(), pNode->val) != record.end())
			return true;
		else
		{
			record.push_back(k - pNode->val);
			if (pNode->left)
				mystack.push(pNode->left);
			if (pNode->right)
				mystack.push(pNode->right);
		}
	}
	return false;
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
	TreeNode* root = new TreeNode(5);
	TreeNode* t_3 = new TreeNode(3);
	TreeNode* t_6 = new TreeNode(6);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_4 = new TreeNode(4);
	TreeNode* t_7 = new TreeNode(7);
	root->left = t_3;
	root->right = t_6;
	t_3->left = t_2;
	t_3->right = t_4;
	t_6->right = t_7;

	bool a = findTarget(root, 9);
	//test2
	bool b = findTarget(root, 28);
	cout << a << endl << b << endl;//2,8
	//test end
	system("pause");
	return 0;
}
