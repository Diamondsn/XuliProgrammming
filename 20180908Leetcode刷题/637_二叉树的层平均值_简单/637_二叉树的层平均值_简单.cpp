#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

//给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
//
//示例 1:
//输入:
//    3
//   / \
//  9  20
//    /  \
//   15   7
//输出: [3, 14.5, 11]
//解释:
//第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
//注意：
//
//节点值的范围在32位有符号整数范围内。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<double> averageOfLevels(TreeNode* root) {
	vector<double>result;
	if (root == NULL)
		return result;

	queue<TreeNode*>myqueue;
	myqueue.push(root);
	int hasadd = 0;//已经累加到temp的上层节点个数;
	double shang = 1;//上层节点总数;
	int xia = 0;
	double temp=0;
	while (!myqueue.empty())
	{
		TreeNode* pNode = myqueue.front();
		myqueue.pop();

		if (shang == hasadd)
		{
			result.push_back(temp/shang);
			shang = xia;
			hasadd = 0;
			xia = 0;
			temp = 0;
		}

		temp += pNode->val;
		hasadd ++;
		if (pNode->left)
		{
			myqueue.push(pNode->left);
			xia++;
		}
		if (pNode->right)
		{
			myqueue.push(pNode->right);
			xia++;
		}
	}
	result.push_back(temp/shang);
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
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t1_9 = new TreeNode(9);
	TreeNode* t1_20 = new TreeNode(20);
	TreeNode* t1_15 = new TreeNode(15);
	TreeNode* t1_7 = new TreeNode(7);

	t1->left = t1_9;
	t1->right = t1_20;
	t1_20->left = t1_15;
	t1_20->right = t1_7;

	//t1遍历
	cout << "t1前序遍历" << endl;
	Qianxubianli(t1);//3,9,20,15,7
	cout << endl;

	cout << "t1中序遍历" << endl;
	Zhongxubianli(t1);//9,3,15,20,7
	cout << endl;

	cout << "t1后序遍历" << endl;
	Houxubianli(t1);//9,15,7,20,3
	cout << endl;

	vector<double>result = averageOfLevels(t1);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	//test end

	system("pause");
	return 0;
}