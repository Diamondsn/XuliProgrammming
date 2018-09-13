#include<iostream>
#include<vector>
using namespace std;

//给定一个N叉树，找到其最大深度。
//最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
//
//例如，给定一个 3叉树 :
//  1
// /|\
// 3 2 4
/// \
//5  6
//我们应返回其最大深度，3。
//
//说明 :
//树的深度不会超过 1000。
//树的节点总不会超过 5000。

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

int maxDepth(Node* root) {
	if (root == NULL)
		return 0;

	int max = 0;
	for (int i = 0; i < root->children.size(); ++i)
	{
		if (root->children[i] == NULL)
			continue;

		int temp = maxDepth(root->children[i]);
		if (temp > max)
			max = temp;
	}
	return max + 1;
}

void main(){
	//test
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

	int depth = maxDepth(t_1);
	cout << depth << endl;
	//test end
	system("pause");
}
