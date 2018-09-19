#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定两个二叉树，编写一个函数来检验它们是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
//示例 1:
//输入:       1         1
//          / \       / \
//         2   3     2   3
//
//        [1,2,3],   [1,2,3]
//
//输出: true
//
//示例 2:
//输入:      1          1
//          /           \
//         2             2
//
//        [1,2],     [1,null,2]
//
//输出: false
//
//示例 3:
//输入:       1         1
//          / \       / \
//         2   1     1   2
//
//        [1,2,1],   [1,1,2]
//
//输出: false

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == q)
		return true;
	if (p == NULL && q == NULL)
		return true;
	else if (p == NULL || q == NULL)
		return false;

	if (p->val != q->val)
		return false;
	else if (!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right))
		return false;

	return true;
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
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_3 = new TreeNode(3);
	t1->left = t1_2;
	t1->right = t1_3;

	TreeNode* t2 = new TreeNode(1);
	TreeNode* t2_2 = new TreeNode(2);
	TreeNode* t2_3 = new TreeNode(3);
	t2->left = t2_2;
	t2->right = t2_3;

	bool a = isSameTree(t1, t2);
	//test2
	TreeNode* t3 = new TreeNode(1);
	TreeNode* t3_2 = new TreeNode(2);
	t3->left = t3_2;

	TreeNode* t4 = new TreeNode(1);
	TreeNode* t4_2 = new TreeNode(2);
	t4->right = t4_2;

	bool b = isSameTree(t3, t4);
	//test3
	TreeNode* t5 = new TreeNode(1);
	TreeNode* t5_2 = new TreeNode(2);
	TreeNode* t5_1 = new TreeNode(1);
	t5->left = t5_2;
	t5->right = t5_1;

	TreeNode* t6 = new TreeNode(1);
	TreeNode* t6_1 = new TreeNode(1);
	TreeNode* t6_2 = new TreeNode(2);
	t6->left = t6_1;
	t6->right = t6_2;

	bool c = isSameTree(t5, t6);

	cout << a << endl << b << endl << c << endl;
	//test end

	system("pause");
	return 0;
}