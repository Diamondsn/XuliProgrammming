#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
//
//假定 BST 有如下定义：
//
//结点左子树中所含结点的值小于等于当前结点的值
//结点右子树中所含结点的值大于等于当前结点的值
//左子树和右子树都是二叉搜索树
//例如：
//给定 BST [1,null,2,2],
//
//   1
//    \
//     2
//    /
//   2
//返回[2].
//
//提示：如果众数超过1个，不需考虑输出顺序
//
//进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//参考https://blog.csdn.net/hy971216/article/details/81322549
//注意全局需要更新的值可以使用全局变量
//只需要上轮和下轮传递的值使用函数参数

//全局变量定义
class Solution {
public:
	vector<int> res;
	int mx = 0, cnt = 1;
	vector<int> findMode(TreeNode* root) {
		TreeNode* pre = NULL;
		inorder(root, pre);
		return res;
	}
	void inorder(TreeNode* root, TreeNode*& pre)
	{
		if (root == NULL)return;
		inorder(root->left, pre);
		if (pre) {
			cnt = (pre->val == root->val) ? cnt+1: 1;
		}
		if (cnt >= mx) {
			if (cnt > mx) {
				res.clear();
			}
			res.push_back(root->val);
			mx = cnt;
		}
		pre = root;
		inorder(root->right, pre);
	}
};

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
	TreeNode* t = new TreeNode(1);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_2_2 = new TreeNode(2);
	
	t->right = t_2;
	t_2->left = t_2_2;

	Solution mysolution;
	vector<int>res = mysolution.findMode(t);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	//test end

	system("pause");
	return 0;
}