#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<map>
using namespace std;

//给出二叉树的根，找出出现次数最多的子树元素和。一个结点的子树元素和定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
//然后求出出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的元素（不限顺序）。
//
//示例 1
//输入:
//  5
// /  \
//2   -3
//返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。
//
//示例 2
//输入:
//  5
// /  \
//2   -5
//返回 [2]，只有 2 出现两次，-5 只出现 1 次。
//
//提示： 假设任意子树元素和均可以用 32 位有符号整数表示。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//方法类似，时间改进方向，在TreeSum时直接使用map找到出现最大次数一级最大次数的res，当更新max时清空res
void TreeSum(vector<int>& vec, TreeNode* root){
	if (!root)return;
	int left = 0, right = 0;
	if (!root->left && !root->right){
		vec.push_back(root->val);
		return;
	}
	TreeSum(vec, root->left);
	if (root->left)
		left = vec.back();

	TreeSum(vec, root->right);
	if (root->right)
		right = vec.back();

	vec.push_back(root->val + left + right);
}

vector<int> findFrequentTreeSum(TreeNode* root) {
	vector<int>res;
	if (!root)return res;
	TreeSum(res, root);
	map<int, int>hash;
	int max = 1;
	for (int i : res){
		if (hash.find(i) == hash.end())
		{
			hash.insert(pair<int, int>(i, 1));
		}
		else{
			hash[i]++;
			if (hash[i] > max)max = hash[i];
		}
	}
	res.clear();
	for (auto it = hash.begin(); it != hash.end(); ++it){
		if (it->second == max)
			res.push_back(it->first);
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
	TreeNode* t = new TreeNode(5);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_3 = new TreeNode(-3);

	t->left = t_2;
	t->right = t_3;
	vector<int>res = findFrequentTreeSum(t);
	for (int i : res)cout << i << endl;
	
	//test2
	cout << endl << "test2" << endl;
	TreeNode* n = new TreeNode(5);
	TreeNode* n_2 = new TreeNode(2);
	TreeNode* n_5 = new TreeNode(-5);
	n->left = n_2;
	n->right = n_5;
	res = findFrequentTreeSum(n);
	for (int i : res){
		cout << i << endl;
	}
	//test end

	system("pause");
	return 0;
}