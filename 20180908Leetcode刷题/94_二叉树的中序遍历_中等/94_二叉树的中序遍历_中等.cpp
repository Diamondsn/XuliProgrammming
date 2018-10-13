#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;

//给定一个二叉树，返回它的中序 遍历。
//
//示例:
//输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [1,3,2]
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//以下是使用队列的非常规解法
//vector<int> inorderTraversal(TreeNode* root) {
//	vector<int>res;
//	if (root == NULL)return res;
//	list<TreeNode*>mylist;
//	set<TreeNode*>hash;//表示已经插入左右节点的根节点，在下次遍历到时直接打印值即可
//	mylist.push_back(root);
//	while (!mylist.empty()) {
//		TreeNode* cur= mylist.front();
//		if (hash.find(cur) == hash.end())
//		{
//			list<TreeNode*>::iterator iter=mylist.begin();
//			if (cur->left)
//			{
//				iter=mylist.insert(mylist.begin(), cur->left);//此处插入元素会导致之前的迭代器失效
//				iter++;//++后才是原先的元素
//			}
//			if (cur->right)
//				mylist.insert(++iter, cur->right);
//			hash.insert(cur);
//		}
//		else {
//			res.push_back(cur->val);
//			mylist.pop_front();
//		}
//	}
//	return res;
//}

//以下使用栈来进行迭代求解
vector<int> inorderTraversal(TreeNode* root) {
	vector<int>res;
	if (root == NULL)return res;
	stack<TreeNode*>mystack;
	mystack.push(root);
	while (!mystack.empty()) {
		TreeNode* cur = mystack.top();
		
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
	TreeNode* t = new TreeNode(1);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_3 = new TreeNode(3);
	t->right = t_2;
	t_2->left = t_3;
	vector<int>res = inorderTraversal(t);
	for (int i = 0; i < res.size(); ++i)cout << res[i] << ",";
	cout << endl<<"递归实现的中序遍历" << endl;
	Zhongxubianli(t);

	//test2
	TreeNode* n = new TreeNode(3);
	TreeNode* n_1 = new TreeNode(1);
	TreeNode* n_2 = new TreeNode(2);
	n->left= n_1;
	n->right = n_2;
	cout <<endl<< "test2" << endl;
	vector<int>res1 = inorderTraversal(n);
	for (int i = 0; i < res1.size(); ++i)cout << res1[i] << ",";
	cout << endl << "递归实现的中序遍历" << endl;
	Zhongxubianli(n);
	//test end

	system("pause");
	return 0;
}