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

//给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
//
//说明：
//你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
//
//示例 1:
//输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 1
//
//示例 2:
//输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 3
//
//进阶：
//如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//初始解法:用到了vec遍历以及插入，虽能AC但速度较慢，未应用二叉搜索树相关性质
//void zhongxubianli(TreeNode* root,vector<int>& vec,int k){
//	if (root==NULL || vec.size() == k)
//		return;
//	zhongxubianli(root->left,vec,k);
//	if (vec.size() == k)return;
//	if (vec.size() == 0 || vec[vec.size() - 1]<root->val)
//		vec.push_back(root->val);
//	else{
//		for (auto it = vec.begin(); it != vec.end(); ++it){
//			if (*it== root->val)
//				break;
//			else if (*it > root->val)
//			{
//				vec.insert(it, root->val);
//				break;
//			}
//		}
//	}
//	if (vec.size() == k)return;
//	zhongxubianli(root->right,vec,k);
//	if (vec.size() == k)return;
//}
//
//int kthSmallest(TreeNode* root, int k) {
//	vector<int>vec;
//	zhongxubianli(root,vec,k);
//	return (vec.size()==k?vec[k - 1]:-1);
//}

//改进解法
//博客上解法需统计子树数量
//以下解法来自Leetcode 4ms范例，代码简洁，思路清晰，在中序遍历的情况下同时计数

//思路感想：为何同样计数，程序运行效率会不一样
//平常计数，需统计根节点左子树数量，若数量大于k，证明应从根节点的左子节点继续递归，这之中会有重复遍历
//而带有引用值得中序遍历，在查找到符合条件的结果后所有的都会直接返回，不存在任何多余遍历
int inOrder(TreeNode* root, int &k){//注意:此处的k'是引用，不是原函数的值传递
	if (!root)return -1;
	int val = inOrder(root->left, k);
	if (k == 0)return val;//此行不能省略
	if (--k == 0)return root->val;//不能用else if，每次到root时均需减一
	return inOrder(root->right, k);
}
int kthSmallest(TreeNode* root, int k){
	return inOrder(root, k);
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
	TreeNode* t = new TreeNode(3);
	TreeNode* t_1 = new TreeNode(1);
	TreeNode* t_4 = new TreeNode(4);
	TreeNode* t_2 = new TreeNode(2);
	t->left = t_1;
	t->right = t_4;
	t_1->right = t_2;

	int a = kthSmallest(t, 1);//1

	//test2
	TreeNode* n = new TreeNode(5);
	TreeNode* n_3 = new TreeNode(3);
	TreeNode* n_6 = new TreeNode(6);
	TreeNode* n_2 = new TreeNode(2);
	TreeNode* n_4 = new TreeNode(4);
	TreeNode* n_1 = new TreeNode(1);
	n->left = n_3;
	n->right = n_6;
	n_3->left = n_2;
	n_3->right = n_4;
	n_2->left = n_1;

	int b = kthSmallest(n,3);//3
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}