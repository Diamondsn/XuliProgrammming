#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<map>
#include<list>
using namespace std;

//给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 
//返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。
//
//注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 
//你可以返回任意有效的结果。
//
//例如, 
//给定二叉搜索树:
//
//        4
//       / \
//      2   7
//     / \
//    1   3
//
//和 插入的值: 5
//
//你可以返回这个二叉搜索树:
//
//         4
//       /   \
//      2     7
//     / \   /
//    1   3 5
//
//或者这个树也是有效的:
//
//         5
//       /   \
//      2     7
//     / \   
//    1   3
//         \
//          4

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
	if (!root){
		TreeNode* newroot = new TreeNode(val);
		return newroot;
	}
	else if (root && !root->left && val <= root->val)
	{
		root->left = new TreeNode(val);
		return root;
	}
	else if (root && !root->right && val > root->val){
		root->right = new TreeNode(val);
		return root;
	}
	else{
		TreeNode* res = NULL;
		if (root->val < val)
		{
		     res = insertIntoBST(root->right, val);
		}
		else{
			res = insertIntoBST(root->left, val);
		}
		if (res != root)return root;
	}
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
	list<TreeNode*>mylist;
	mylist.push_back(PNode);
	while (!mylist.empty()){
		TreeNode* node = mylist.front();
		mylist.pop_front();
		if (node)
			cout << node->val << ",";
		else
			cout << "null,";
		if (node)
		{
			mylist.push_back(node->right);
			mylist.push_back(node->left);
		}
	}
}

int main() {
	//test1
	TreeNode* t = new TreeNode(4);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_7 = new TreeNode(7);
	TreeNode* t_1 = new TreeNode(1);
	TreeNode* t_3 = new TreeNode(3);
	t->left = t_2;
	t->right = t_7;
	t_2->left = t_1;
	t_2->right = t_3;
	TreeNode* newroot = insertIntoBST(t, 5);
	CengXuBianLi(newroot);
	//test end

	system("pause");
	return 0;
}