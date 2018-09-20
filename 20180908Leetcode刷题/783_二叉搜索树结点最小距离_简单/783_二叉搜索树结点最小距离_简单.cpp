#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个二叉搜索树的根结点 root, 返回树中任意两节点的差的最小值。
//
//示例：
//输入: root = [4,2,6,1,3,null,null]
//输出: 1
//
//解释:
//注意，root是树结点对象(TreeNode object)，而不是数组。
//
//给定的树 [4,2,6,1,3,null,null] 可表示为下图:
//
//          4
//        /   \
//      2      6
//     / \    
//    1   3  
//
//最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
//
//注意：
//二叉树的大小范围在 2 到 100。
//二叉树总是有效的，每个节点的值都是整数，且不重复。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max(TreeNode* root)
{
	if (root == NULL)
		return INT_MIN;

	int m =root->val;
	int left = INT_MIN;
	int right = INT_MIN;
	if (root->left)
		left = max(root->left);
	if (root->right)
		right = max(root->right);

	if (left > m)
		m = left;
	if (right > m)
		m = right;

	return m;
}

int min(TreeNode* root)
{
	if (root == NULL)
		return INT_MAX;

	int m = root->val;
	int left = INT_MAX;
	int right = INT_MAX;
	if (root->left)
		left = min(root->left);
	if (root->right)
		right = min(root->right);

	if (left < m)
		m = left;
	if (right < m)
		m = right;

	return m;
}

//注意:此题采用的是二叉搜索树
int minDiffInBST(TreeNode* root){
	//首先取得左子树的最大值和右子树的最小值
	if (root == NULL)
		return -1;

	if (!root->left && !root->right)
		return INT_MAX;

	int leftmax=INT_MIN;
	int rightmin=INT_MIN;
	int leftresult = INT_MAX;
	int rightresult = INT_MAX;
	if (root->left)
	{
		leftmax = max(root->left);
		leftresult = minDiffInBST(root->left);
	}
		
	if (root->right)
	{
		rightmin = min(root->right);
		rightresult = minDiffInBST(root->right);
	}
	int left = INT_MAX;
	int right = INT_MAX;
	if (leftmax >=0)
		left = abs(leftmax - root->val);
	if (rightmin>=0)
		right = abs(rightmin - root->val);

	int min = left;
	if (right < min)
		min = right;//自身的结果
	if (leftresult < min)
		min = leftresult;
	if (rightresult < min)
		min = rightresult;
	
	return min;
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
	TreeNode* n = new TreeNode(4);
	TreeNode* n_2 = new TreeNode(2);
	TreeNode* n_6 = new TreeNode(6);
	TreeNode* n_1 = new TreeNode(1);
	TreeNode* n_3 = new TreeNode(3);
	n->left = n_2;
	n->right = n_6;
	n_2->left = n_1;
	n_2->right = n_3;

	int a = minDiffInBST(n);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}
