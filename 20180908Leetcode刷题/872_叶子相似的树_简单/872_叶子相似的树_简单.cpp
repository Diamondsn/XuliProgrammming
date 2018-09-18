#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个叶值序列。
//举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。
//如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
//如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。
//
//提示：
//给定的两颗树可能会有 1 到 100 个结点。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL || root2 == NULL)
		return false;

	if (root1 == root2)
		return true;
	stack<TreeNode*>t1;
	stack<TreeNode*>t2;
	t1.push(root1);
	t2.push(root2);
	vector<TreeNode*>vec1;
	vector<TreeNode*>vec2;
	while (!t1.empty())
	{
		TreeNode* pNode=t1.top();
		t1.pop();

		if (pNode->right == NULL && pNode->left == NULL)
		{
			vec1.push_back(pNode);
			continue;
		}
		if (pNode->right)
			t1.push(pNode->right);
		if (pNode->left)
			t1.push(pNode->left);
	}

	while (!t2.empty())
	{
		TreeNode* pNode = t2.top();
		t2.pop();

		if (pNode->right == NULL && pNode->left == NULL)
		{
			vec2.push_back(pNode);
			continue;
		}
		if (pNode->right)
			t2.push(pNode->right);
		if (pNode->left)
			t2.push(pNode->left);
	}

	if (vec1.size() != vec2.size())
		return false;

	for (int i = 0; i < vec1.size();++i)
	{
		if (vec1[i]->val != vec2[i]->val)
			return false;
	}
	return true;
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

void main(){
	//test1
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t1_5 = new TreeNode(5);
	TreeNode* t1_1 = new TreeNode(1);
	TreeNode* t1_6 = new TreeNode(6);
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_9 = new TreeNode(9);
	TreeNode* t1_8 = new TreeNode(8);
	TreeNode* t1_7 = new TreeNode(7);
	TreeNode* t1_4 = new TreeNode(4);

	t1->left = t1_5;
	t1->right = t1_1;
	t1_5->left = t1_6;
	t1_5->right = t1_2;
	t1_2->left = t1_7;
	t1_2->right = t1_4;
	t1_1->left = t1_9;
	t1_1->right = t1_8;

	TreeNode* t2 = new TreeNode(6);

	bool a = leafSimilar(t1, t2);
	cout << a << endl;
	//test end
	system("pause");
}
