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

TreeNode* depthcopy(TreeNode* prev){
	if (!prev)return NULL;
	TreeNode* newroot = new TreeNode(prev->val);
	newroot->left = depthcopy(prev->left);
	newroot->right = depthcopy(prev->right);
	return newroot;
}

vector<TreeNode*> generateTrees(int n) {
	if (n <= 0)return{};
	vector<vector<TreeNode*>>dp(n);
	TreeNode* node = new TreeNode(1);
	vector<TreeNode*>vec(1,node);
	dp[0]=vec;
	for (int i = 1; i < n; ++i){
		vec.clear();
		for (TreeNode* t : dp[i - 1]){
			TreeNode* cur1 = new TreeNode(i + 1);
			cur1->left = t;
			vec.push_back(cur1);
			TreeNode*temp=depthcopy(t);
			int num = 0;
			while (temp){
				temp = temp->right;
				num++;
			}
			for (int j = 0; j < num; ++j){
				TreeNode* newroot = depthcopy(t),*m=newroot;
				for (int k = 0; k < j; ++k){
					m = m->right;
				}
				TreeNode* cur2 = new TreeNode(i + 1);
				TreeNode* mmm = m->right;
				m->right = cur2;
				cur2->left = mmm;
				vec.push_back(newroot);
			}
		}
		dp[i] = vec;
	}
	return dp.back();
}

int main() {
	//test1
	vector<TreeNode*>res = generateTrees(4);
	for (TreeNode* n : res)
	{
		Qianxubianli(n);
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}