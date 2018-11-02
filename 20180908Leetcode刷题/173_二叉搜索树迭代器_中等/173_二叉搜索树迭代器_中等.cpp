#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;

//实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
//
//调用 next() 将返回二叉搜索树中的下一个最小的数。
//
//注意: next() 和hasNext() 操作的时间复杂度是O(1)，并使用 O(h) 内存，其中 h 是树的高度。

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//初解即想到标准解法，不断push左节点
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root)
		{
			mystack.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !mystack.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* pNode=mystack.top();
		mystack.pop();
		TreeNode* node = pNode->right;
		while (node){
			mystack.push(node);
			node = node->left;
		}
		return pNode->val;
	}
	stack<TreeNode*>mystack;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

int main() {
	//test1
	TreeNode* root = new TreeNode(5);
	TreeNode* r3 = new TreeNode(3);
	TreeNode* r8 = new TreeNode(8);
	TreeNode* r1 = new TreeNode(1);
	TreeNode* r4 = new TreeNode(4);
	TreeNode* r6 = new TreeNode(6);
	TreeNode* r9 = new TreeNode(9);
	root->left = r3;
	root->right = r8;
	r3->left = r1;
	r3->right = r4;
	r8->left = r6;
	r8->right = r9;
	BSTIterator it = BSTIterator(root);
	while (it.hasNext())cout << it.next() << endl;//输出结果为1,3,4,5,6,8,9,
	//test end
	system("pause");
	return 0;
}