#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
//
//百度百科中最近公共祖先的定义为：
//“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//
//例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
//
//        _______6______
//       /              \
//    ___2__          ___8__
//   /      \        /      \
//   0      _4       7       9
//         /  \
//         3   5
//示例 1:
//输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//输出: 6 
//解释: 节点 2 和节点 8 的最近公共祖先是 6。
//
//示例 2:
//输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
//输出: 2
//解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
//
//说明:
//所有节点的值都是唯一的。
//p、q 为不同节点且均存在于给定的二叉搜索树中。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> path(TreeNode* root, TreeNode* p)
{
	vector<TreeNode*> result;
	if (root == NULL)
		return result;

	if (root->val == p->val)
	{
		result.push_back(p);
		return result;
	}

	vector<TreeNode*>left;
	vector<TreeNode*>right;
	if (root->left)
		left = path(root->left, p);
	if (root->right)
		right = path(root->right, p);

	if (left.size() > 0)
	{
		result.push_back(root);
		for (int i = 0; i < left.size(); ++i)
		{
			result.push_back(left[i]);
		}
	}
	if (right.size()>0)
	{
		result.clear();
		result.push_back(root);
		for (int i = 0; i < right.size(); ++i)
		{
			result.push_back(right[i]);
		}
	}
	return result;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	vector<TreeNode*>p1 = path(root, p);
	vector<TreeNode*>p2 = path(root, q);
	reverse(p1.begin(), p1.end());
	reverse(p2.begin(), p2.end());
	bool flag = true;
	TreeNode* pNode = NULL;
	if (p1.size()>0 && p2.size() > 0)
	{
		for (int i = 0; flag && i < p1.size(); ++i)
		{
			for (int j = 0; flag && j < p2.size(); ++j)
			{
				if (p1[i]->val == p2[j]->val)
				{
					flag = false;
					pNode = p1[i];
				}
			}
		}
	}
	return pNode;
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
	TreeNode* t1 = new TreeNode(6);
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_8 = new TreeNode(8);
	TreeNode* t1_0 = new TreeNode(0);
	TreeNode* t1_4 = new TreeNode(4);
	TreeNode* t1_7 = new TreeNode(7);
	TreeNode* t1_9 = new TreeNode(9);
	TreeNode* t1_3 = new TreeNode(3);
	TreeNode* t1_5 = new TreeNode(5);

	t1->left = t1_2;
	t1->right = t1_8;
	t1_2->left = t1_0;
	t1_2->right = t1_4;
	t1_8->left = t1_7;
	t1_8->right = t1_9;
	t1_4->left = t1_3;
	t1_4->right = t1_5;

	//测试查找路径
	//vector<TreeNode*> p1=path(t1, t1_3);

	//vector<TreeNode*>p2 = path(t1, t1_9);
	////path1
	//cout << "path1" << endl;
	//for (int i = 0; i < p1.size(); ++i)
	//{
	//	cout << p1[i]->val << ",";
	//}
	//cout << endl;
	////path2
	//cout << "path2" << endl;
	//for (int i = 0; i < p2.size(); ++i)
	//{
	//	cout << p2[i]->val << ",";
	//}
	//cout << endl;

	TreeNode* n1 = lowestCommonAncestor(t1, t1_2, t1_8);
	cout <<"test1"<<endl<< n1->val << endl;

	//test2
	TreeNode* n2 = lowestCommonAncestor(t1, t1_2, t1_4);
	cout <<"test2"<<endl<< n2->val << endl;
	//test end
	system("pause");
}
