#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;

//给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
//
//说明：
//你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
//
//示例 1:
//输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 1
//
//示例 2:
//输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 3
//
//进阶：
//如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthSmallest(TreeNode* root, int k) {

}

void Qianxubianli(TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	cout << pNode->val << ",";
	Qianxubianli(pNode->left);
	Qianxubianli(pNode->right);
}

void Zhongxubianli(TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	Zhongxubianli(pNode->left);
	cout << pNode->val << ",";
	Zhongxubianli(pNode->right);
}

void Houxubianli(TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	Houxubianli(pNode->left);
	Houxubianli(pNode->right);
	cout << pNode->val << ",";
}

int main() {
	//test1
	TreeNode* t = new TreeNode(3);
	TreeNode* t_1 = new TreeNode(1);
	TreeNode* t_4 = new TreeNode(4);
	TreeNode* t_2 = new TreeNode(2);
	t->left = t_1;
	t->right = t_4;
	t_1->right = t_2;

	int a = kthSmallest(t, 1);//1

	//test2
	TreeNode* n = new TreeNode(5);
	TreeNode* n_3 = new TreeNode(3);
	TreeNode* n_6 = new TreeNode(6);
	TreeNode* n_2 = new TreeNode(2);
	TreeNode* n_4 = new TreeNode(4);
	TreeNode* n_1 = new TreeNode(1);
	n->left = n_3;
	n->right = n_6;
	n_3->left = n_2;
	n_3->right = n_4;
	n_2->left = n_1;

	int b = kthSmallest(n,3);//3
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}