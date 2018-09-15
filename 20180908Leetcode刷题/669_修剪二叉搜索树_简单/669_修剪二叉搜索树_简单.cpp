#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。
//通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。
//你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。
//
//示例 1:
//
//输入: 
//    1
//   / \
//  0   2
//
//  L = 1
//  R = 2
//
//输出: 
//    1
//      \
//       2
//
//示例 2:
//输入: 
//    3
//   / \
//  0   4
//   \
//    2
//   /
//  1
//
//  L = 1
//  R = 3
//
//输出: 
//      3
//     / 
//   2   
//  /
// 1

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* trimBST(TreeNode* root, int L, int R) {
	if (root == NULL)
		return NULL;

	TreeNode* Left = NULL;
	TreeNode* Right = NULL;
	if (root->left)
		Left = trimBST(root->left, L, R);
	if (root->right)
		Right = trimBST(root->right, L, R);

	if (root->val >= L && root->val <= R)
	{
		root->left = Left;
		root->right = Right;
		return root;
	}
	else
	{
		if (Left && !Right)
			return Left;
		else if (Right && !Left)
			return Right;
	}
	return NULL;
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
	//tree1
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t1_0 = new TreeNode(0);
	TreeNode* t1_2 = new TreeNode(2);

	t1->left = t1_0;
	t1->right = t1_2;

	//t1遍历
	cout << "t1前序遍历" << endl;
	Qianxubianli(t1);//1,0,2
	cout << endl;

	cout << "t1中序遍历" << endl;
	Zhongxubianli(t1);//0,1,2
	cout << endl;

	cout << "t1后序遍历" << endl;
	Houxubianli(t1);//0,2,1
	cout << endl;

	TreeNode* t = trimBST(t1, 1, 2);

	//t遍历
	cout << "t前序遍历" << endl;
	Qianxubianli(t);//1,2
	cout << endl;

	cout << "t中序遍历" << endl;
	Zhongxubianli(t);//1,2
	cout << endl;

	cout << "t后序遍历" << endl;
	Houxubianli(t);//2,1
	cout << endl;

	//test2
	//tree2
	TreeNode* t2 = new TreeNode(3);
	TreeNode* t2_0 = new TreeNode(0);
	TreeNode* t2_4 = new TreeNode(4);
	TreeNode* t2_2 = new TreeNode(2);
	TreeNode* t2_1 = new TreeNode(1);

	t2->left = t2_0;
	t2->right = t2_4;
	t2_0->right = t2_2;
	t2_2->left = t2_1;

	//t2遍历
	cout << "t2前序遍历" << endl;
	Qianxubianli(t2);//3,0,2,1,4
	cout << endl;

	cout << "t2中序遍历" << endl;
	Zhongxubianli(t2);//0,1,2,3,4
	cout << endl;

	cout << "t2后序遍历" << endl;
	Houxubianli(t2);//1,2,0,4,3
	cout << endl;

	TreeNode* t3 = trimBST(t2, 1, 3);

	//t3遍历
	cout << "t3前序遍历" << endl;
	Qianxubianli(t3);//3,2,1
	cout << endl;

	cout << "t3中序遍历" << endl;
	Zhongxubianli(t3);//1,2,3
	cout << endl;

	cout << "t3后序遍历" << endl;
	Houxubianli(t3);//1,2,3
	cout << endl;
	//test end

	system("pause");
	return 0;
}