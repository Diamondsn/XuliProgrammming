#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：
//
//行数 m 应当等于给定二叉树的高度。
//列数 n 应当总是奇数。
//根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。根节点所在的行与列会将剩余空间划分为两部分（左下部分和右下部分）。你应该将左子树输出在左下部分，右子树输出在右下部分。左下和右下部分应当有相同的大小。即使一个子树为空而另一个非空，你不需要为空的子树输出任何东西，但仍需要为另一个子树留出足够的空间。然而，如果两个子树都为空则不需要为它们留出任何空间。
//每个未使用的空间应包含一个空的字符串""。
//使用相同的规则输出子树。
//
//示例 1:
//输入:
//     1
//    /
//   2
//输出:
//[["", "1", ""],
// ["2", "", ""]]
//
//示例 2:
//输入:
//     1
//    / \
//   2   3
//    \
//     4
//输出:
//[["", "", "", "1", "", "", ""],
// ["", "2", "", "", "", "3", ""],
// ["", "", "4", "", "", "", ""]]
//
//示例 3:
//输入:
//      1
//     / \
//    2   5
//   / 
//  3 
// / 
//4 
//输出:
//[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
// ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
// ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
// ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
//注意: 二叉树的高度在范围 [1, 10] 中。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<string>> printTree(TreeNode* root) {
	vector<vector<string>>res,res1,res2;
	vector<string>vec;
	if (!root)return res;
	if (!root->left && !root->right){
		vec.push_back(to_string(root->val));
		res.push_back(vec);
		return res;
	}
	res1 = printTree(root->left);
	res2 = printTree(root->right);
	int weight1 = res1.size()>0?res1[0].size():0,height1=res1.size();
	int weight2 = res2.size()>0?res2[0].size():0, height2 = res2.size();
	res.resize(std::max(height1, height2) + 1, vector<string>(2 * std::max(weight1, weight2) + 1));
	res[0][res[0].size() / 2] = to_string(root->val);
	for (int i = 0; i < res1.size(); ++i){
		for (int j = 0; j < res1[i].size(); ++j){
			if (res1[i][j].size() <= 0)continue;
			res[i + 1][weight1 < weight2 ? (j + (weight2 - weight1)/2) : j] = res1[i][j];
		}
	}
	for (int i = 0; i < res2.size(); ++i){
		for (int j = 0; j < res2[i].size(); ++j){
			if (res2[i][j].size() <= 0)continue;
			res[i + 1][weight2 < weight1 ? (j + res[0].size()/2+(weight1 - weight2)/2+1) : j+res[0].size()/2+1] = res2[i][j];
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
	TreeNode* t1_1 = new TreeNode(1);
	TreeNode*t1_2 = new TreeNode(2);
	t1_1->left = t1_2;
	vector<vector<string>>res = printTree(t1_1);
	for (vector<string>vec : res){
		for (string str : vec){
			if (str.size() <= 0)
				cout << " ,";
			else
				cout << str << ",";
		}
		cout << endl;
	}

	//test2
	cout << endl << "test2" << endl;
	TreeNode* t2_1 = new TreeNode(1);
	TreeNode* t2_2 = new TreeNode(2);
	TreeNode*t2_3 = new TreeNode(3);
	TreeNode* t2_4 = new TreeNode(4);
	t2_1->right = t2_2;
	t2_1->left = t2_3;
	t2_2->right = t2_4;
	res = printTree(t2_1);
	for (vector<string>vec : res){
		for (string str : vec){
			if (str.size() <= 0)
				cout << " ,";
			else
				cout << str << ",";
		}
		cout << endl;
	}

	//test3
	cout << endl << "test3" << endl;
	TreeNode* t3_1 = new TreeNode(1);
	TreeNode* t3_2 = new TreeNode(2);
	TreeNode* t3_3 = new TreeNode(3);
	TreeNode* t3_4 = new TreeNode(4);
	TreeNode* t3_5 = new TreeNode(5);
	t3_1->left = t3_2;
	t3_2->left = t3_3;
	t3_3->left = t3_4;
	t3_1->right = t3_5;
	res = printTree(t3_1);
	for (vector<string>vec : res){
		for (string str : vec){
			if (str.size() <= 0)
				cout << " ,";
			else
				cout << str << ",";
		}
		cout << endl;
	}
	//test end

	system("pause");
	return 0;
}