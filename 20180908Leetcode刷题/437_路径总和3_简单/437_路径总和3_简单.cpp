#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//给定一个二叉树，它的每个结点都存放着一个整数值。
//
//找出路径和等于给定数值的路径总数。
//
//路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的
//（只能从父节点到子节点）。
//
//二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
//
//示例：
//root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//      10
//     /  \
//    5   -3
//   / \    \
//  3   2   11
// / \   \
//3  -2   1
//
//返回 3。和等于 8 的路径有:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3.  -3 -> 11

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//连续的路径查找
int pathSumLianXu(TreeNode* root, int sum)
{
	int count = 0;
	if (!root)
		return count;

	count += pathSumLianXu(root->left, sum - root->val);
	count += pathSumLianXu(root->right, sum - root->val);

	if (root->val == sum)
	{
		count++;
	}

	return count;
}

int pathSum(TreeNode* root, int sum) {

	int count = 0;
	if (!root)
		return 0;

	count += pathSumLianXu(root->left, sum - root->val);
	count += pathSumLianXu(root->right, sum - root->val);
	count += pathSum(root->left, sum);
	count += pathSum(root->right, sum);

	if (root->val == sum)
		count++;
	return  count;
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
	TreeNode* t1 = new TreeNode(10);
	TreeNode* t1_5 = new TreeNode(5);
	TreeNode* t1__3 = new TreeNode(-3);
	TreeNode* t1_3 = new TreeNode(3);
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_11 = new TreeNode(11);
	TreeNode* t1_3_2 = new TreeNode(3);
	TreeNode* t1__2 = new TreeNode(-2);
	TreeNode* t1_1 = new TreeNode(1);

	t1->left = t1_5;
	t1->right = t1__3;
	t1__3->right = t1_11;
	t1_5->left = t1_3;
	t1_5->right = t1_2;
	t1_3->left = t1_3_2;
	t1_3->right = t1__2;
	t1_2->right = t1_1;

	//t1遍历
	cout << "t1前序遍历" << endl;
	Qianxubianli(t1);//10,5,3,3,-2,2,1,-3,11
	cout << endl;

	cout << "t1中序遍历" << endl;
	Zhongxubianli(t1);//3,3,-2,5,2,1,10,-3,11
	cout << endl;

	cout << "t1后序遍历" << endl;
	Houxubianli(t1);//3,-2,3,1,2,5,11,-3,10
	cout << endl;

	cout << endl;
	int result = pathSum(t1,8);
	cout << result << endl;
	//test end

	system("pause");
	return 0;
}