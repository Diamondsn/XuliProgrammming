#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//给定一个二叉树，返回它的 前序 遍历。
//
//示例:
//输入: [1,null,2,3]  
//   1
//    \
//     2
//    /
//   3 
//
//输出: [1,2,3]
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root) {
	vector<int>res;
	if (!root)return res;
	stack<TreeNode*>mystack;
	mystack.push(root);
	while (!mystack.empty()) {
		TreeNode* pNode = mystack.top();
		mystack.pop();
		if (pNode->right)
			mystack.push(pNode->right);
		if (pNode->left)
			mystack.push(pNode->left);
		res.push_back(pNode->val);
	}
	return res;
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
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_3 = new TreeNode(3);
	t1->right = t1_2;
	t1_2->left = t1_3;
	vector<int>res=preorderTraversal(t1);
	for (int t : res) {
		cout << t << ",";
	}
	cout << endl << "内置前序遍历" << endl;
	//内置前序遍历
	Qianxubianli(t1);
	//test end

	system("pause");
	return 0;
}