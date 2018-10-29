#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<stack>
using namespace std;

//给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
//
//例如，从根到叶子节点路径 1->2->3 代表数字 123。
//
//计算从根到叶子节点生成的所有数字之和。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例 1:
//输入: [1,2,3]
//    1
//   / \
//  2   3
//输出: 25
//解释:
//从根到叶子节点路径 1->2 代表数字 12.
//从根到叶子节点路径 1->3 代表数字 13.
//因此，数字总和 = 12 + 13 = 25.
//
//示例 2:
//输入: [4,9,0,5,1]
//    4
//   / \
//  9   0
// / \
//5   1
//输出: 1026
//解释:
//从根到叶子节点路径 4->9->5 代表数字 495.
//从根到叶子节点路径 4->9->1 代表数字 491.
//从根到叶子节点路径 4->0 代表数字 40.
//因此，数字总和 = 495 + 491 + 40 = 1026.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(int & res, int path, TreeNode* cur){
	path = path * 10 + cur->val;
	if (!cur->left&& !cur->right)
	{
		res += path;
	}
	else{
		if (cur->left)
		    dfs(res, path, cur->left);
		if (cur->right)
			dfs(res, path, cur->right);
	}
}

//用回溯算法来做深度遍历，就不用对已访问过的节点进行标记了
int sumNumbers(TreeNode* root) {
	if (!root)return 0;
	int res=0;
	int path = 0;
	dfs(res, path, root);
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

//兼容LeetCode的层序遍历
void CengXuBianLi(TreeNode* PNode){
	list<TreeNode*>mystack;
	mystack.push_back(PNode);
	while (!mystack.empty()){
		TreeNode* node = mystack.front();
		mystack.pop_front();
		if (node)
			cout << node->val << ",";
		else
			cout << "null,";
		if (node)
		{
			mystack.push_back(node->right);
			mystack.push_back(node->left);
		}
	}
}

int main() {
	//test1
	TreeNode* t = new TreeNode(1);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_3 = new TreeNode(3);
	t->left = t_2;
	t->right = t_3;
	int a = sumNumbers(t);

	//test2
	TreeNode* n = new TreeNode(4);
	TreeNode* n_9 = new TreeNode(9);
	TreeNode* n_0 = new TreeNode(0);
	TreeNode* n_5 = new TreeNode(5);
	TreeNode* n_1 = new TreeNode(1);
	n->left = n_9;
	n->right = n_0;
	n_9->left = n_5;
	n_9->right = n_1;
	int b = sumNumbers(n);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}