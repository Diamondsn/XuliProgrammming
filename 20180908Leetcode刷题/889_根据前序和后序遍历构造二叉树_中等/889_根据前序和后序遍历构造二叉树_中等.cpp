﻿#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<deque>
using namespace std;

//返回与给定的前序和后序遍历匹配的任何二叉树。
//
//pre 和 post 遍历中的值是不同的正整数。
//
//示例：
//输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
//输出：[1,2,3,4,5,6,7]
//
//提示：
//1 <= pre.length == post.length <= 30
//pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
//每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
	if (pre.size() == 0 && post.size() == 0)return NULL;
	if (pre.size() == 1 && post.size() == 1){
		TreeNode* node = new TreeNode(pre.back());
		return node;
	}
	TreeNode* root = new TreeNode(pre.front());
	int num = 0;
	while (post[num] != pre[1]){
		num++;
	}
	vector<int>pre1, pre2, post1, post2;
	for (int i = 1; i < pre.size(); ++i){
		if (i <= num + 1)
		{
			pre1.push_back(pre[i]);
			post1.push_back(post[i - 1]);
		}
		else
		{
			pre2.push_back(pre[i]);
			post2.push_back(post[i - 1]);
		}
	}
	root->left = constructFromPrePost(pre1, post1);
	root->right = constructFromPrePost(pre2, post2);
	return root;
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
	vector<int>pre={1,2,4,5,3,6,7},post={4,5,2,6,7,3,1};
	TreeNode* res=constructFromPrePost(pre,post);
	cout<<"前序遍历结果"<<endl;
    Qianxubianli(res);
	cout<<endl<<"后序遍历结果"<<endl;
	Houxubianli(res);
	//test end

	system("pause");
	return 0;
}