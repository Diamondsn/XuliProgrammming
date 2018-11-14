#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<unordered_set>
#include"time.h"
#include<bitset>
#include<map>
using namespace std;

//给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
//两棵树重复是指它们具有相同的结构以及相同的结点值。
//示例 1：
//        1
//       / \
//      2   3
//     /   / \
//    4   2   4
//       /
//      4
//下面是两个重复的子树：
//
//      2
//     /
//    4
//和
//
//    4
//因此，你需要以列表的形式返回上述重复子树的根结点。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

bool isSame(TreeNode* root1, TreeNode* root2){
	if (!root1 && !root2)return true;
	if ((root1 && !root2) || (!root1 && root2))return false;
	if (root1->val != root2->val)return false;
	if (isSame(root1->left, root2->left) && isSame(root1->right, root2->right))return true;
	return false;
}

//此种解法超时
//vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//	if (!root)return{};
//	vector<TreeNode*>res;
//	vector<TreeNode*>mylist;
//	stack<TreeNode*>mystack;
//	mylist.push_back(root);
//	mystack.push(root);
//	while (!mystack.empty()){
//		TreeNode* pNode = mystack.top();
//		mystack.pop();
//		for (int i = 0; i < mylist.size(); ++i){
//			if (mylist[i] == pNode)continue;
//			if (isSame(mylist[i], pNode)){
//				int j = 0;
//				for (; j < res.size(); ++j){
//					if (isSame(res[j], pNode))
//						break;
//				}
//				if (j == res.size())
//				{
//					res.push_back(pNode);
//				}
//			}
//		}
//		if (pNode->left){
//			mystack.push(pNode->left);
//			mylist.push_back(pNode->left);
//		}
//		if (pNode->right){
//			mystack.push(pNode->right);
//			mylist.push_back(pNode->right);
//		}
//	}
//	return res;
//}

//最初查找到的相同的以后不进入大的satck中进行轮询，但超时
//vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//	if (!root)return{};
//	vector<TreeNode*>res;
//	vector<TreeNode*>mylist;
//	stack<TreeNode*>mystack;
//	mylist.push_back(root);
//	mystack.push(root);
//	while (!mystack.empty()){
//		TreeNode* pNode = mystack.top();
//		mystack.pop();
//		int i = 0;
//		for (; i < mylist.size(); ++i){
//			if (mylist[i] == pNode)continue;
//			if (isSame(mylist[i], pNode)){
//				int j = 0;
//				for (; j < res.size(); ++j){
//					if (isSame(res[j], pNode))
//						break;
//				}
//				if (j == res.size())
//				{
//					stack<TreeNode*>tempstack;
//					tempstack.push(pNode);
//					while (!tempstack.empty()){
//						TreeNode* temp = tempstack.top();
//						tempstack.pop();
//						int k = 0;
//						for (; k < res.size(); ++k){
//							if (isSame(res[k], temp))
//								break;
//						}
//						if (k==res.size())
//						    res.push_back(temp);
//						if (temp->left)
//							tempstack.push(temp->left);
//						if (temp->right)
//							tempstack.push(temp->right);
//					}
//				}
//				break;
//			}
//		}
//		if (i == mylist.size()){
//			if (pNode->left){
//				mystack.push(pNode->left);
//				mylist.push_back(pNode->left);
//			}
//			if (pNode->right){
//				mystack.push(pNode->right);
//				mylist.push_back(pNode->right);
//			}
//		}
//	}
//	return res;
//}

//直接递归整个问题,依旧需要比对左右两棵子树
//vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){
//	if (!root)return{};
//	vector<TreeNode*>l, r,res;
//	l = findDuplicateSubtrees(root->left);
//	r = findDuplicateSubtrees(root->right);
//	res = l;
//	for (TreeNode* noder : r){
//		int i = 0;
//		for (; i < res.size(); ++i){
//			if (res[i] == noder)continue;
//			if (isSame(r[i], noder))
//				break;
//		}
//		if (i == res.size())res.push_back(noder);
//	}
//	return res;
//}

//可以参考将所有的节点进行遍历序列化为string，用string作为键来存储所有的TreeNode
//https://www.jianshu.com/p/cea679188b6d
string preorder(TreeNode*  root, map<string, list<TreeNode*>>&m_map){
	if (!root)return"#";
	string a = preorder(root->left,m_map) + "," + preorder(root->right,m_map) + "," + to_string(root->val);
	m_map[a].push_back(root);
	return a;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){
	map<string, list<TreeNode*>>mymap;
	preorder(root, mymap);
	vector<TreeNode*>res;
	for (auto it = mymap.begin(); it != mymap.end(); ++it){
		if (it->second.size() > 1){
			res.push_back(it->second.front());
		}
	}
	return res;
}

void main(){
	//test1
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t2_2 = new TreeNode(2);
	TreeNode* t4_2 = new TreeNode(4);
	TreeNode* t4_3 = new TreeNode(4);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t3->left = t2_2;
	t3->right = t4_2;
	t2_2->left = t4_3;

	vector<TreeNode*>vec = findDuplicateSubtrees(t1);
	for (TreeNode* n : vec){
		Qianxubianli(n);
		cout << endl;
	}
	//test end
	system("pause");
}