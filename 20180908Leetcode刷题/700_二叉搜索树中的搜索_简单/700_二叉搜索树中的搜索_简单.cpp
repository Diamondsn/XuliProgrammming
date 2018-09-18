#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
//
//例如，
//给定二叉搜索树:
//
//        4
//       / \
//      2   7
//     / \
//    1   3
//
//和值: 2
//你应该返回如下子树:
//
//      2     
//     / \   
//    1   3
//在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
	if (root == NULL)
		return NULL;

	if (root->val == val)
		return root;

	TreeNode* left=NULL;
	TreeNode* right=NULL;
	if (root->left)
		left = searchBST(root->left, val);
	if (root->right)
		right = searchBST(root->right, val);

	if (left == NULL && right == NULL)
		return NULL;
	else if (left == NULL)
		return right;
	else if (right == NULL)
		return left;
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

void main(){
	//test1
	TreeNode* t1 = new TreeNode(4);
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_7 = new TreeNode(7);
	TreeNode* t1_1 = new TreeNode(1);
	TreeNode* t1_3 = new TreeNode(3);

	t1->left = t1_2;
	t1->right = t1_7;
	t1_2->left = t1_1;
	t1_2->right = t1_3;

	TreeNode* n1 = searchBST(t1,2);
	Qianxubianli(n1);

	//test2
	TreeNode* n2 = searchBST(t1, 5);
	Qianxubianli(n2);
	//test end
	system("pause");
}
