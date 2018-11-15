#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<stack>
using namespace std;

//给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//例如：
//给定二叉树 [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回锯齿形层次遍历如下：
//
//[
//  [3],
//  [20,9],
//  [15,7]
//]

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>>res;
	if (!root)return res;
	stack<TreeNode*>s1, s2;//s1奇数层，s2偶数层
	vector<int>temp;
	s1.push(root);
	int cur = 1;
	while (!s1.empty() || !s2.empty()){
		temp.clear();
		TreeNode* t;
		if (cur % 2){//奇数层
			while (!s1.empty()){
				t = s1.top();
				s1.pop();
				temp.push_back(t->val);
				if (t->left)
					s2.push(t->left);
				if (t->right)
					s2.push(t->right);
			}
		}
		else{
			while (!s2.empty()){
				t = s2.top();
				s2.pop();
				temp.push_back(t->val);
				if (t->right)
					s1.push(t->right);
				if (t->left)
					s1.push(t->left);
			}
		}
		cur++;
		res.push_back(temp);
	}
	return res;
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
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t9 = new TreeNode(9);
	TreeNode* t20 = new TreeNode(20);
	TreeNode* t15 = new TreeNode(15);
	TreeNode* t7 = new TreeNode(7);
	t3->left = t9;
	t3->right = t20;
	t20->left = t15;
	t20->right = t7;

	vector<vector<int>>res = zigzagLevelOrder(t3);
	for (vector<int>vec : res){
		for (int m : vec)
			cout << m << ",";
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}