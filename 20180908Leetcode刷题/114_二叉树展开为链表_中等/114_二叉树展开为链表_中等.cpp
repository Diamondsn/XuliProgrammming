#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个二叉树，原地将它展开为链表。
//
//例如，给定二叉树
//    1
//   / \
//  2   5
// / \   \
//3   4   6
//将其展开为：
//
//1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
        
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
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_3 = new TreeNode(3);

	t1->left = t1_2;
	t1->right = t1_3;

	int a = findTilt(t1);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}