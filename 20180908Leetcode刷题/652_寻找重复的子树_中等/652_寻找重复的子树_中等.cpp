#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<unordered_set>
#include"time.h"
#include<bitset>
using namespace std;

//给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
//两棵树重复是指它们具有相同的结构以及相同的结点值。
//示例 1：
//        1
//       / \
//      2   3
//     /   / \
//    4   2   4
//       /
//      4
//下面是两个重复的子树：
//
//      2
//     /
//    4
//和
//
//    4
//因此，你需要以列表的形式返回上述重复子树的根结点。

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

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

}

void main(){
	//test1
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t2_2 = new TreeNode(2);
	TreeNode* t4_2 = new TreeNode(4);
	TreeNode* t4_3 = new TreeNode(4);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t3->left = t2_2;
	t3->right = t4_2;
	t2_2->left = t4_3;

	vector<TreeNode*>vec = findDuplicateSubtrees(t1);
	for (TreeNode* n : vec){
		Qianxubianli(n);
		cout << endl;
	}
	//test end
	system("pause");
}