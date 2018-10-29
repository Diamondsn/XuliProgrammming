#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
using namespace std;

//您需要在二叉树的每一行中找到最大的值。
//
//示例：
//
//输入: 
//          1
//         / \
//        3   2
//       / \   \  
//      5   3   9 
//输出: [1, 3, 9]

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> largestValues(TreeNode* root) {
	vector<int>res;
	if (!root)return res;
	list<TreeNode*>mylist;
	mylist.push_back(root);
	int shang = 1, xia = 0;
	int curmax=INT_MIN;
	while (!mylist.empty()){
		TreeNode* pNode=mylist.front();
		mylist.pop_front();
		if (pNode->val > curmax)
			curmax = pNode->val;
	
		shang--;
		if (pNode->left){
			mylist.push_back(pNode->left);
			xia++;
		}
		if (pNode->right){
			mylist.push_back(pNode->right);
			xia++;
		}
		if (shang == 0){
			res.push_back(curmax);
			curmax = INT_MIN;
			shang = xia;
			xia = 0;
		}
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
	TreeNode* t = new TreeNode(1);
	TreeNode* t_3 = new TreeNode(3);
	TreeNode* t_2 = new TreeNode(2);
	TreeNode* t_5 = new TreeNode(5);
	TreeNode* t_3_2 = new TreeNode(3);
	TreeNode* t_9 = new TreeNode(9);

	t->left = t_3;
	t->right = t_2;
	t_3->left = t_5;
	t_3->right = t_3_2;
	t_2->right = t_9;

	vector<int>vec = largestValues(t);
	for (int t : vec){
		cout << t << endl;
	}

	//test2
	cout << "test2" << endl;
	TreeNode* n = new TreeNode(43);
	TreeNode* n_35 = new TreeNode(35);
	TreeNode* n_77 = new TreeNode(-77);
	TreeNode* n_40 = new TreeNode(40);
	n->left = n_35;
	n->right = n_77;
	n_77->right = n_40;
	vec = largestValues(n);
	for (int t : vec)cout << t << endl;
	//test end

	system("pause");
	return 0;
}