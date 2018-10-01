#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
//这条路径可能穿过根结点。
//
//示例 :
//给定二叉树
//          1
//         / \
//        2   3
//       / \     
//      4   5    
//返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
//
//注意：两结点之间的路径长度是以它们之间边的数目表示。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int longestpath(TreeNode* root)
{
	if (root == NULL)return 0;
	int a=0,b=0;
	if(root->left)
	   a = longestpath(root->left)+1;
	if(root->right)
	   b = longestpath(root->right)+1;
	int res= (a > b ? a : b);
	return res;
}

int diameterOfBinaryTree(TreeNode* root) {
	if (root == NULL)return 0;
	int leftpath = 0, rightpath = 0, leftdia = 0,rightdia=0;
	if (root->left)
		leftpath = longestpath(root->left) + 1;
	if (root->right)
		rightpath = longestpath(root->right) + 1;
	int max = 0;
	leftdia = diameterOfBinaryTree(root->left);
	rightdia = diameterOfBinaryTree(root->right);
	if (leftpath + rightpath > max)
		max = leftpath + rightpath;
	if (leftdia > max)
		max = leftdia;
	if (rightdia > max)
		max = rightdia;
	return max;
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
	TreeNode* t = new TreeNode(1);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_3 = new TreeNode(3);
	TreeNode* t_4 = new TreeNode(4);
	TreeNode* t_5 = new TreeNode(5);

	t->left = t_2;
	t->right = t_3;
	t_2->left = t_4;
	t_2->right = t_5;

	int a = diameterOfBinaryTree(t);//3
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}