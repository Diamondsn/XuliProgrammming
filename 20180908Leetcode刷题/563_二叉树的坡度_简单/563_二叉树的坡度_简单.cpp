#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个二叉树，计算整个树的坡度。
//
//一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。
//
//整个树的坡度就是其所有节点的坡度之和。
//
//示例:
//输入: 
//         1
//       /   \
//      2     3
//输出: 1
//
//解释: 
//结点的坡度 2 : 0
//结点的坡度 3 : 0
//结点的坡度 1 : |2-3| = 1
//树的坡度 : 0 + 0 + 1 = 1
//
//注意:
//任何子树的结点的和不会超过32位整数的范围。
//坡度的值不会超过32位整数的范围。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//参数说明:函数返回树的坡度，count返回树结点的总和
int corefindTilt(TreeNode* root,int& count)
{
	if (!root)
	{
		count = 0;
		return 0;
	}
	int left=0,right=0,leftcount = 0, rightcount = 0;
	left = corefindTilt(root->left, leftcount);
	right = corefindTilt(root->right, rightcount);

	count = root->val + leftcount + rightcount;
	return abs(leftcount-rightcount)+left + right;
}

int findTilt(TreeNode* root) {
	if (!root)
		return 0;

	int left=0,right=0,leftcount = 0, rightcount = 0;
	left=corefindTilt(root->left, leftcount);
	right = corefindTilt(root->right, rightcount);
	
	return abs(leftcount - rightcount) + left + right;
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

	int a = findTilt(t1);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}