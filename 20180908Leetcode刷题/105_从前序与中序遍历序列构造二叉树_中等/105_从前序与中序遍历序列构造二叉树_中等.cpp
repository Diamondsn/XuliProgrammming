#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//根据一棵树的前序遍历与中序遍历构造二叉树。
//
//注意:
//你可以假设树中没有重复的元素。
//
//例如，给出
//前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7]
//返回如下的二叉树：
//    3
//   / \
//  9  20
//    /  \
//   15   7

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() <= 0 || preorder.size() != inorder.size())return NULL;
	vector<int>subpreorder1, subinorder1,subpreorder2,subinorder2;
	TreeNode* root = new TreeNode(preorder[0]);
	int count = 0;
	for (int i = 0; i < inorder.size(); ++i) {
		if (inorder[i] != preorder[0])
			count++;
		else
			break;
	}
	subpreorder1.assign(preorder.begin() + 1, preorder.begin() + 1 + count);
	subinorder1.assign(inorder.begin(), inorder.begin() + count);
	subpreorder2.assign(preorder.begin() + 1 + count, preorder.end());
	subinorder2.assign(inorder.begin() + 1 + count, inorder.end());
	TreeNode* left = buildTree(subpreorder1, subinorder1);
	TreeNode* right = buildTree(subpreorder2, subinorder2);
	root->left = left;
	root->right = right;
	return root;
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
	vector<int>preorder = { 3,9,20,15,7 }, inorder = { 9,3,15,20,7 };
	TreeNode* res = buildTree(preorder, inorder);
	cout << "前序遍历" << endl;
	Qianxubianli(res);
	cout << endl << "中序遍历" << endl;
	Zhongxubianli(res);
	//test end

	system("pause");
	return 0;
}