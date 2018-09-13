#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//给定一个N叉树，返回其节点值的前序遍历。
//
//例如，给定一个 3叉树 :
//  1
// /|\
// 3 2 4
/// \
//5  6
//返回其前序遍历: [1, 3, 5, 6, 2, 4]。

//说明: 递归法很简单，你可以使用迭代法完成此题吗 ?

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

//N叉树的递归前序遍历版本
vector<int> preorder_digui(Node* root) {
	vector<int> result;
	if (root == NULL)
		return result;

	result.push_back(root->val);
	vector<int> temp;
	for (int i = 0; i < root->children.size(); ++i)
	{
		temp = preorder_digui((root->children)[i]);
		result.insert(result.end(), temp.begin(), temp.end());
	}

	return result;
}

//N叉树的递归前序迭代版本
vector<int> preorder_diedai(Node* root) {
	vector<int> result;
	if (root == NULL)
		return result;
	stack<Node*> mystack;
	mystack.push(root);
	while (!mystack.empty())
	{
		Node* pNode = mystack.top();
		mystack.pop();
		result.push_back(pNode->val);
		for (auto iter = pNode->children.rbegin(); iter != pNode->children.rend(); ++iter)
		{
			mystack.push(*iter);
		}
	}

	return result;
}

void main(){
	//test 1
	vector<Node*> temp;
	Node* t_5 = new Node(5, temp);
	Node* t_6 = new Node(6, temp);
	Node* t_2 = new Node(2, temp);
	Node* t_4 = new Node(4, temp);
	temp.push_back(t_5);
	temp.push_back(t_6);
	Node* t_3 = new Node(3,temp);
	temp.clear();
	temp = {t_3,t_2,t_4};
	Node* t_1 = new Node(1, temp);

	//vector<int> result = preorder_digui(t_1);
	//for (int i = 0; i < result.size(); ++i)
	//{
	//	cout << result[i] << endl;
	//}
	//test2
	vector<int> result_diedai = preorder_diedai(t_1);
	for (int i = 0; i < result_diedai.size(); ++i)
	{
		cout << result_diedai[i] << endl;
	}//1,3,5,6,2,4
	//test end
	system("pause");
}
