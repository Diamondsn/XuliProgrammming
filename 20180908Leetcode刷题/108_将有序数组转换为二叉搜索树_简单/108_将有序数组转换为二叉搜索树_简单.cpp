#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
//
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//示例 :
//给定有序数组: [-10, -3, 0, 5, 9],
//一个可能的答案是：[0, -3, 9, -10, null, 5]，它可以表示下面这个高度平衡二叉搜索树：
//	0
//   / \
// -3   9
///    /
//-10  5

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.size() < 1)
		return NULL;

	int m;
	/*if (nums.size() % 2 == 0)
		m = nums.size();
	else*/
	    m = (nums.size()) / 2;

	TreeNode* root = new TreeNode(nums[m]);
	vector<int> left,right;
	for (int i = 0; i < m; ++i)
	{
		left.push_back(nums[i]);
	}
	for (int i = m + 1; i < nums.size(); ++i)
	{
		right.push_back(nums[i]);
	}
	root->left= sortedArrayToBST(left);
	root->right = sortedArrayToBST(right);

	return root;
}

void Qianxubianli(TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	cout << pNode->val << " ,";
	if(pNode->left)
	Qianxubianli(pNode->left);
	if(pNode->right)
	Qianxubianli(pNode->right);
}

void main() {
	//test
	vector<int> nums = { -10,-3,0,5,9 };
	TreeNode* root=sortedArrayToBST(nums);
	Qianxubianli(root);
	
	 //test end
	system("pause");
}
