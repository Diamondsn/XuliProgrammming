#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个二叉树，返回所有从根节点到叶子节点的路径。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//输入:
//   1
// /   \
//2     3
// \
//  5
//输出: ["1->2->5", "1->3"]
//
//解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string>result;
	if (root == NULL)
		return result;

	if (root->left == NULL && root->right == NULL)
	{
		result.push_back(to_string(root->val));
		return result;
	}

	vector<string>left;
	vector<string>right;
	if (root->left)
		left = binaryTreePaths(root->left);
	if (root->right)
		right = binaryTreePaths(root->right);

	for (int i = 0; i < left.size(); ++i)
	{
		result.push_back(to_string(root->val)+"->" + left[i]);
	}
	for (int j = 0; j < right.size(); ++j)
	{
		result.push_back(to_string(root->val) + "->" + right[j]);
	}
	return result;
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
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_3 = new TreeNode(3);
	TreeNode* t1_5 = new TreeNode(5);

	t1->left = t1_2;
	t1->right = t1_3;
	t1_2->right = t1_5;

	//t1遍历
	cout << "t1前序遍历" << endl;
	Qianxubianli(t1);//1,2,5,3
	cout << endl;

	cout << "t1中序遍历" << endl;
	Zhongxubianli(t1);//2,5,1,3
	cout << endl;

	cout << "t1后序遍历" << endl;
	Houxubianli(t1);//5,2,3,1
	cout << endl;

	vector<string> result = binaryTreePaths(t1);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}