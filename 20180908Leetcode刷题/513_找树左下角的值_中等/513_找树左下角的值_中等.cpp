#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<queue>
using namespace std;

//给定一个二叉树，在树的最后一行找到最左边的值。
//
//示例 1:
//输入:
//
//    2
//   / \
//  1   3
//
//输出:
//1
// 
//示例 2:
//输入:
//
//        1
//       / \
//      2   3
//     /   / \
//    4   5   6
//       /
//      7
//
//输出:
//7
// 
//注意: 您可以假设树（即给定的根节点）不为 NULL。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*************************************/
//解法一
/**************************************/
//利用回溯算法，初次尝试解答，速度也较快,以下depth参数使用值引用的情况下就不用管回溯时的减一了

//思考，何时使用值传递，何时使用引用
//在整个算法执行过程中均要实时更新且维持同一份数据的用引用(相当于全局变量)
//在递归过程中，递归的每层需要重新计算的值使用值复制(局部变量）

//1.depth使用引用时的dfs函数
//void dfs(TreeNode* root, int & maxdepth,int & depth, int & left){
//	if (!root){ --depth; return; }
//	dfs(root->left, maxdepth, ++depth, left);
//	if (depth > maxdepth)
//	{
//		left = root->val;
//		maxdepth = depth;
//	}
//	dfs(root->right, maxdepth, ++depth, left);
//	--depth;
//}
//
//2.depth使用值复制的dfs函数
//void dfs(TreeNode* root,int & maxdepth,int depth,int &res){
//	if (root == NULL)return;
//	if (depth > maxdepth){
//		res = root->val;
//		maxdepth = depth;
//	}
//	dfs(root->left, maxdepth, depth+1, res);
//	dfs(root->right, maxdepth, depth+1, res);
//}
//
//int findBottomLeftValue(TreeNode* root) {
//	int maxdepth=0,depth = 0,left = root->val;
//	dfs(root, maxdepth,depth, left);
//	return left;
//}

/*************************************/
//解法二
/**************************************/
//以下方法极为巧妙，利用树的广度优先遍历或者称为层序遍历，使用队列先压右子节点，后压左子节点
//每层的最左边节点最后压入，返回最后一个压入的节点即为解
//int findBottomLeftValue(TreeNode* root){
//	queue<TreeNode*>myqueue;
//	myqueue.push(root);
//	int res;
//	while (!myqueue.empty()){
//		TreeNode* node = myqueue.front();
//		myqueue.pop();
//		res = node->val;
//		if (node->right)
//			myqueue.push(node->right);
//		if (node->left)
//			myqueue.push(node->left);
//	}
//	return res;
//}

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
	TreeNode* t_1 = new TreeNode(1);
	TreeNode* t_3 = new TreeNode(3);
	t->left = t_1;
	t->right = t_3;
	int a = findBottomLeftValue(t);

	//test2
	TreeNode* n = new TreeNode(1);
	TreeNode* n_2 = new TreeNode(2);
	TreeNode* n_3 = new TreeNode(3);
	TreeNode* n_4 = new TreeNode(4);
	TreeNode* n_5 = new TreeNode(5);
	TreeNode* n_6 = new TreeNode(6);
	TreeNode* n_7 = new TreeNode(7);
	n->left = n_2;
	n->right = n_3;
	n_2->left = n_4;
	n_3->left = n_5;
	n_3->right = n_6;
	n_5->left = n_7;
	int b = findBottomLeftValue(n);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}