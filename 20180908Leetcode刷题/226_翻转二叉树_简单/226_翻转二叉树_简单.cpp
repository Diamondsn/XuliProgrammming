#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//翻转一棵二叉树。
//
//示例：
//输入：
//    4
//   / \
//  2   7
// / \  / \
//1   3 6   9
//输出：
//    4
//   / \
//  7   2
// / \  / \
//9   6 3   1

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
	if (root == NULL)
		return NULL;

	TreeNode* newroot = new TreeNode(root->val);

	if (root->left)
		newroot->right = invertTree(root->left);
	if (root->right)
		newroot->left = invertTree(root->right);
	return newroot;
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
	TreeNode* t1 = new TreeNode(4);
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_7 = new TreeNode(7);
	TreeNode* t1_1 = new TreeNode(1);
	TreeNode* t1_3 = new TreeNode(3);
	TreeNode* t1_6 = new TreeNode(6);
	TreeNode* t1_9 = new TreeNode(9);

	t1->left = t1_2;
	t1->right = t1_7;
	t1_2->left = t1_1;
	t1_2->right = t1_3;
	t1_7->left = t1_6;
	t1_7->right = t1_9;
	
	TreeNode* t2 = invertTree(t1);
	//t1遍历
	cout << "t1前序遍历" << endl;
	Qianxubianli(t1);//4,2,1,3,7,6,9
	cout << endl;

	cout << "t1中序遍历" << endl;
	Zhongxubianli(t1);//1,2,3,4,6,7,9
	cout << endl;

	cout << "t1后序遍历" << endl;
	Houxubianli(t1);//1,3,2,6,9,7,4
	cout << endl;

	//t2遍历
	cout << "t2前序遍历" << endl;
	Qianxubianli(t2);//4,7,9,6,2,3,1
	cout << endl;

	cout << "t2中序遍历" << endl;
	Zhongxubianli(t2);//9,7,6,4,3,2,1
	cout << endl;

	cout << "t2后序遍历" << endl;
	Houxubianli(t2);//9,6,7,3,1,2,4
	cout << endl;
	//test end

	system("pause");
	return 0;
}