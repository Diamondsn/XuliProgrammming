#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
#include<list>
#include<stack>
using namespace std;

//满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。
//
//返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。
//
//答案中每个树的每个结点都必须有 node.val=0。
//
//你可以按任何顺序返回树的最终列表。
//
//示例：
//输入：7
//输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
//解释：
////图链接https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/08/24/fivetrees.png
//
//提示：
//1 <= N <= 20

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> allPossibleFBT(int N) {
	vector<TreeNode*>res,left,right;
	if (N & 1 == 0)return res;
	if (N == 1){
		TreeNode* r = new TreeNode(0);
		res.push_back(r);
		return res;
	}
	for (int i = 1; i < N - 1; i += 2){
		left = allPossibleFBT(i);
		right = allPossibleFBT(N - 1 - i);
		for (int i = 0; i < left.size(); ++i){
			for (int j = 0; j < right.size(); ++j){
				TreeNode* newroot = new TreeNode(0);
				newroot->left = left[i];
				newroot->right = right[j];
				res.push_back(newroot);
			}
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

//兼容LeetCode的层序遍历
void CengXuBianLi(TreeNode* PNode){
	list<TreeNode*>mystack;
	mystack.push_back(PNode);
	while (!mystack.empty()){
		TreeNode* node=mystack.front();
		mystack.pop_front();
		if (node)
			cout << node->val << ",";
		else
			cout << "null,";
		if (node)
		{
			mystack.push_back(node->right);
			mystack.push_back(node->left);
		}
	}
}

int main() {
	//test1
	vector<TreeNode*>res = allPossibleFBT(7);
	for (int i = 0; i < res.size(); ++i){
		cout << "test"<<i << endl;
		CengXuBianLi(res[i]);
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}