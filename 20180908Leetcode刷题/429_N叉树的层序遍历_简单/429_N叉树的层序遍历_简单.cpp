#include<iostream>
#include<vector>
#include<stack>
#include<deque>
using namespace std;

//给定一个N叉树，返回其节点值的前序遍历。
//
//例如，给定一个 3叉树 :
//  1
// /|\
// 3 2 4
/// \
//5  6
//返回其层序遍历:
//
//[
//     [1],
//     [3,2,4],
//     [5,6]
//]
//
//说明:
//树的深度不会超过 1000。
//树的节点总数不会超过 5000。

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

vector<vector<int>> levelOrder(Node* root) {
	vector<vector<int>>result;
	if (root == NULL)
		return result;

	vector<int>temp;
	deque<Node*>mydeque;
	mydeque.push_back(root);
	int shang = 1;
	int xia = 0;
	while (!mydeque.empty())
	{
		Node* pNode = mydeque.front();
		mydeque.pop_front();
 
		if (shang == 0)
		{
			result.push_back(temp);
			temp.clear();
			shang = xia;
			xia = 0;
		}

		temp.push_back(pNode->val);
		shang--;

		for (int i = 0; i < pNode->children.size(); ++i)
		{
			if (pNode->children[i])
			{
				mydeque.push_back(pNode->children[i]);
				xia++;
			}
		}
	}
	result.push_back(temp);
	return result;
}

void main() {
	//test 1
	vector<Node*> temp;
	Node* t_5 = new Node(5, temp);
	Node* t_6 = new Node(6, temp);
	Node* t_2 = new Node(2, temp);
	Node* t_4 = new Node(4, temp);
	temp.push_back(t_5);
	temp.push_back(t_6);
	Node* t_3 = new Node(3, temp);
	temp.clear();
	temp = { t_3,t_2,t_4 };
	Node* t_1 = new Node(1, temp);

	vector<vector<int>> result = levelOrder(t_1);
	for (int i = 0; i < result.size(); ++i)
	{
		for(int j = 0;j < result[i].size(); ++j)
		{
			cout << result[i][j] << ",";
		}
		cout << endl;
	}
	 //test end
	system("pause");
}
