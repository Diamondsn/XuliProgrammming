#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<unordered_map>
#include"sstream"
using namespace std;
#pragma warning(disable:4996)
//你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
//
//空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树
//之间的一对一映射关系的空括号对。
//
//示例 1:
//输入: 二叉树: [1,2,3,4]
//       1
//     /   \
//    2     3
//   /    
//  4     
//
//输出: "1(2(4))(3)"
//解释: 原本将是“1(2(4)())(3())”，
//在你省略所有不必要的空括号对之后，
//它将是“1(2(4))(3)”。
//
//示例 2:
//输入: 二叉树: [1,2,3,null,4]
//       1
//     /   \
//    2     3
//     \  
//      4 
//输出: "1(2()(4))(3)"
//解释: 和第一个示例相似，
//除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string tree2str(TreeNode* t) {
	string res;
	if (!t)
		return res;

	stringstream ss;
	ss << t->val;
	res=ss.str();
	string temp;
	
	if(t->left && !t->right){
		temp = tree2str(t->left);
		res += "(" + temp + ")";
	}
	else if (!t->left && t->right)
	{
		temp = tree2str(t->right);
		res += "()(" + temp + ")";
	}
	else if (t->left && t->right)
	{
		temp = tree2str(t->left);
		res += "("+temp+")";
		temp = tree2str(t->right);
		res += "("+temp+")";
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
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t1_2 = new TreeNode(2);
	TreeNode* t1_3 = new TreeNode(3);
	TreeNode* t1_4 = new TreeNode(4);
	t1->left = t1_2;
	t1->right = t1_3;
	t1_2->left = t1_4;
	string a = tree2str(t1);

	//test2
	TreeNode* t2 = new TreeNode(1);
	TreeNode* t2_2 = new TreeNode(2);
	TreeNode* t2_3 = new TreeNode(3);
	TreeNode* t2_4 = new TreeNode(4);
	t2->left = t2_2;
	t2->right = t2_3;
	t2_2->right = t2_4;
	string b = tree2str(t2);

	cout << a <<endl<< b << endl;
	//test end

	system("pause");
	return 0;
}
