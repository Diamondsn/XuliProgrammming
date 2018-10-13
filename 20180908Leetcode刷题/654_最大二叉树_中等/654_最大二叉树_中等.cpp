#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
//
//二叉树的根是数组中的最大元素。
//左子树是通过数组中最大值左边部分构造出的最大二叉树。
//右子树是通过数组中最大值右边部分构造出的最大二叉树。
//通过给定的数组构建最大二叉树，并且输出这个树的根节点。
//
//Example 1:
//输入: [3,2,1,6,0,5]
//输入: 返回下面这棵树的根节点：
//      6
//    /   \
//   3     5
//    \    / 
//     2  0   
//       \
//        1
//注意:
//给定的数组的大小在 [1, 1000] 之间。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	if (nums.size() < 1)return NULL;
	auto max = max_element(nums.begin(), nums.end());
	int maxval = *max;
	vector<int>left, right;
	left.assign(nums.begin(), max);
	right.assign(max + 1, nums.end());
	TreeNode* leftNode = constructMaximumBinaryTree(left);
	TreeNode* rightNode = constructMaximumBinaryTree(right);
	TreeNode* root = new TreeNode(maxval);
	root->left = leftNode;
	root->right = rightNode;
	return root;
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
	vector<int>nums = { 3,2,1,6,0,5 };
	TreeNode* res = constructMaximumBinaryTree(nums);
	Zhongxubianli(res);
	//test end

	system("pause");
	return 0;
}