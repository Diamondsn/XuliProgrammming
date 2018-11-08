#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
//满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//
//例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
//
//        _______3______
//       /              \
//    ___5__          ___1__
//   /      \        /      \
//   6      _2       0       8
//         /  \
//         7   4
//示例 1:
//输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//输出: 3
//解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
//
//示例 2:
//输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//输出: 5
//解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
//
//说明:
//所有节点的值都是唯一的。
//p、q 为不同节点且均存在于给定的二叉树中。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//初解用时较长
//vector<TreeNode*> path(TreeNode* find, TreeNode* cur){
//	vector<TreeNode*>vec;
//	if (cur == find){
//		vec.push_back(cur);
//		return vec;
//	}
//	else if (!cur ||(!cur->left && !cur->right)){
//		return vec;
//	}
//	else{
//		vector<TreeNode*>left,right;
//		left = path(find, cur->left);
//		right = path(find, cur->right);
//		if (left.size() > 0){
//			left.insert(left.begin(), cur);
//			return left;
//		}
//		else if(right.size()>0){
//			right.insert(right.begin(), cur);
//			return right;
//		}
//	}
//	return vec;
//}
//
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//	vector<TreeNode*>path1, path2;
//	path1=path(p, root);
//	path2=path(q, root);
//	for (int i = (int)path1.size() - 1; i >= 0;--i){
//		if (find(path2.rbegin(),path2.rend(),path1[i])!=path2.rend())return path1[i];
//	}
//	return NULL;
//}

//https://www.cnblogs.com/simplepaul/p/7702655.html
//直接以大问题进行递归
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

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
	TreeNode* t = new TreeNode(3);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t6 = new TreeNode(6);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t0 = new TreeNode(0);
	TreeNode* t8 = new TreeNode(8);
	TreeNode* t7 = new TreeNode(7);
	TreeNode* t4 = new TreeNode(4);

	t->left = t5;
	t->right = t1;
	t5->left = t6;
	t5->right = t2;
	t2->left = t7;
	t2->right = t4;
	t1->left = t0;
	t1->right = t8;

	//test1
	TreeNode* n1 = lowestCommonAncestor(t, t5, t1);
	cout << "test1" << endl << n1->val << endl;

	//test2
	TreeNode* n2 = lowestCommonAncestor(t, t5, t4);
	cout << "test2" << endl << n2->val << endl;
	//test end
	system("pause");
}
