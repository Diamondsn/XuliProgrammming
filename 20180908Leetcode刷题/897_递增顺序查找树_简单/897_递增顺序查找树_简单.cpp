#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个树，按顺序重新排列树，使树中最左边的结点现在是树的根，
//并且每个结点没有左子结点，只有一个右子结点。
//
//示例 ：
//输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]
//       5
//      / \
//    3    6
//   / \    \
//  2   4    8
// /        / \ 
//1        7   9
//
//输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
//            \
//             7
//              \
//               8
//                \
//                 9  
// 
//
//提示：
//给定树中的结点数介于 1 和 100 之间。
//每个结点都有一个从 0 到 1000 范围内的唯一整数值。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//注意:此题应该给定的是二叉搜索树，而不是普通的树;
TreeNode* increasingBST(TreeNode* root) {
	if (root == NULL)return NULL;
	TreeNode* min = increasingBST(root->left);
	TreeNode* left=min;
	if (left != NULL) {
		while (left->right != NULL)
			left = left->right;
		left->right = root;
	}
	root->left = NULL;
	root->right = increasingBST(root->right);
	if (min == NULL)
		return root;
	else
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

void main() {
	//test1
	TreeNode* t = new TreeNode(5);
	TreeNode* t_3 = new TreeNode(3);
	TreeNode* t_6 = new TreeNode(6);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_4 = new TreeNode(4);
	TreeNode* t_8 = new TreeNode(8);
	TreeNode* t_1 = new TreeNode(1);
	TreeNode* t_7 = new TreeNode(7);
	TreeNode* t_9 = new TreeNode(9);

	t->left = t_3;
	t->right = t_6;
	t_3->left = t_2;
	t_3->right = t_4;
	t_2->left = t_1;
	t_6->right = t_8;
	t_8->left = t_7;
	t_8->right = t_9;

	TreeNode* res = increasingBST(t);
	Qianxubianli(res);
	//test end
	system("pause");
}
