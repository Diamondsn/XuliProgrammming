#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
//
//示例 1:
//给定二叉树 [3,9,20,null,null,15,7]
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回 true 。
//
//示例 2:
//给定二叉树 [1,2,2,3,3,null,null,4,4]
//
//       1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
//返回 false 。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//得到树的深度时，判断子树是否平衡
int GetTreeDepthAndTest(TreeNode* root,bool& res)
{
	res = true;
	if (!root)
	{
		return 0;
	}
	int left = 0, right = 0;
	bool leftres = true,rightres=true;
	if (root->left)
		left = GetTreeDepthAndTest(root->left,leftres);
	if (root->right)
		right = GetTreeDepthAndTest(root->right,rightres);

	if (!leftres || !rightres || abs(left-right)>1)
	{
		res = false;
	}
	return left > right ? left+1:right+1 ;
}

bool isBalanced(TreeNode* root) {
	bool res = true;
	GetTreeDepthAndTest(root, res);
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
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t1_9 = new TreeNode(9);
	TreeNode* t1_20 = new TreeNode(20);
	TreeNode* t1_15 = new TreeNode(15);
	TreeNode* t1_7 = new TreeNode(7);

	t1->left = t1_9;
	t1->right = t1_20;
	t1_20->left = t1_15;
	t1_20->right = t1_7;

	bool a = isBalanced(t1);

	//test2
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t2_2_1 = new TreeNode(2);
	TreeNode* t2_2_2 = new TreeNode(2);
	TreeNode* t2_3_1 = new TreeNode(3);
	TreeNode* t2_3_2 = new TreeNode(3);
	TreeNode* t2_4_1 = new TreeNode(4);
	TreeNode* t2_4_2 = new TreeNode(4);
	t2->left = t2_2_1;
	t2->right = t2_2_2;
	t2_2_1->left = t2_3_1;
	t2_2_1->right = t2_3_2;
	t2_3_1->left = t2_4_1;
	t2_3_1->right=t2_4_2;

	bool b = isBalanced(t2);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}