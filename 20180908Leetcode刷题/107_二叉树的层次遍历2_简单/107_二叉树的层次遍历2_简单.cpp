#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

//给定一个二叉树，返回其节点值自底向上的层次遍历。 
//（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//
//例如：
//给定二叉树[3, 9, 20, null, null, 15, 7],
//
//  3
// / \
//9  20
//   / \
//  15   7
//返回其自底向上的层次遍历为：
//[
//  [15,7],
//  [9,20],
//  [3]
//]

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>>result;
	if (root == NULL)
		return result;

	queue<TreeNode*>myqueue;
	vector<int>temp;
	myqueue.push(root);
	int shangcount = 1;
	int xiacount = 0;
	while (!myqueue.empty())
	{
		TreeNode* pNode = myqueue.front();
		myqueue.pop();

		if (shangcount == 0)
		{
			result.push_back(temp);
			temp.clear();
			shangcount = xiacount;
			xiacount = 0;
		}

		temp.push_back(pNode->val);
		shangcount--;
		if (pNode->left)
		{
			myqueue.push(pNode->left);
			xiacount++;
		}
		if (pNode->right)
		{
			myqueue.push(pNode->right);
			xiacount++;
		}

	}
	result.push_back(temp);
	reverse(result.begin(), result.end());
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
	TreeNode* t = new TreeNode(3);
	TreeNode* t_39 = new TreeNode(9);
	TreeNode* t_20 = new TreeNode(20);
	TreeNode* t_15 = new TreeNode(15);
	TreeNode* t_7 = new TreeNode(7);

	t->left = t_39;
	t->right = t_20;
	t_20->left = t_15;
	t_20->right = t_7;

	//t遍历
	cout << "t前序遍历" << endl;
	Qianxubianli(t);//3,9,20,15,7
	cout << endl;

	cout << "t中序遍历" << endl;
	Zhongxubianli(t);//9,3,15,20,7
	cout << endl;

	cout << "t后序遍历" << endl;
	Houxubianli(t);//9,15,7,20,3
	cout << endl;

	cout << "t自底向上层序遍历结果" << endl;
	vector<vector<int>> result = levelOrderBottom(t);//3
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}