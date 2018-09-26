#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个二叉树，检查它是否是镜像对称的。
//
//例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//    1
//   / \
//  2   2
//   \   \
//   3    3
//说明:
//如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isCoreSymmetric(TreeNode* t1, TreeNode* t2)
{
	if (!t1 && !t2)
		return true;
	if ((t1 && !t2) || (!t1 && t2))
		return false;

	if (t1->val != t2->val)
		return false;

	return isCoreSymmetric(t1->left, t2->right) && isCoreSymmetric(t1->right, t2->left);
}
bool isSymmetric(TreeNode* root) {
	if (!root)
		return true;

	return isCoreSymmetric(root->left, root->right);
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
	TreeNode* t_2_1 = new TreeNode(2);
	TreeNode* t_2_2 = new TreeNode(2);
	TreeNode* t_3_1 = new TreeNode(3);
	TreeNode* t_4_1 = new TreeNode(4);
	TreeNode* t_4_2 = new TreeNode(4);
	TreeNode* t_3_2 = new TreeNode(3);

	t->left = t_2_1;
	t->right = t_2_2;
	t_2_1->left = t_3_1;
	t_2_1->right = t_4_1;
	t_2_2->left = t_4_2;
	t_2_2->right = t_3_2;

	bool a = isSymmetric(t);

	//test2
	TreeNode* n = new TreeNode(1);
	TreeNode* n_2_1 = new TreeNode(2);
	TreeNode* n_2_2 = new TreeNode(2);
	TreeNode* n_3_1 = new TreeNode(3);
	TreeNode* n_3_2 = new TreeNode(3);
	n->left = n_2_1;
	n->right = n_2_2;
	n_2_1->right = n_3_1;
	n_2_2->right = n_3_2;
	bool b = isSymmetric(n);
	cout << a << endl<<b<<endl;
	//test end

	system("pause");
	return 0;
}