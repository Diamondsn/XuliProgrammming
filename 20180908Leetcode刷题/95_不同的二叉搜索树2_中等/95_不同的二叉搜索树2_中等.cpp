#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<deque>
using namespace std;

//给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
//
//示例:
//输入: 3
//输出:
//[
//  [1,null,3,2],
//  [3,2,null,1],
//  [3,1,null,null,2],
//  [2,1,3],
//  [1,null,2,null,3]
//]
//解释:
//以上的输出对应以下 5 种不同结构的二叉搜索树：
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

vector<TreeNode*> generateTrees(int n) {

}

int main() {
	//test1
	vector<TreeNode*>res = generateTrees(3);
	for (TreeNode* n : res)
	{
		Qianxubianli(n);
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}