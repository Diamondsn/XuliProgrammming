#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//我们想要使用一棵四叉树来储存一个 N x N 的布尔值网络。网络中每一格的值只会是真或假。
//树的根结点代表整个网络。对于每个结点, 它将被分等成四个孩子结点直到这个区域内的值都是相同的.
//
//每个结点还有另外两个布尔变量: isLeaf 和 val。isLeaf 当这个节点是一个叶子结点时为真。val 变量储存叶子结点所代表的区域的值。
//
//你的任务是使用一个四叉树表示给定的网络。下面的例子将有助于你理解这个问题：
//
//给定下面这个8 x 8 网络，我们将这样建立一个对应的四叉树：
//
//由上文的定义，它能被这样分割：
//
//对应的四叉树应该像下面这样，每个结点由一对 (isLeaf, val) 所代表.
//
//对于非叶子结点，val 可以是任意的，所以使用 * 代替。
//
//提示：
//N 将小于 1000 且确保是 2 的整次幂。
//如果你想了解更多关于四叉树的知识，你可以参考这个 wiki 页面。

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

void IsLeaf(vector<vector<int>>& grid, int xMin, int xMax,int yMin,int yMax,bool& isLeaf,bool& val)
{
	if (xMax- xMin==1 && yMax- yMin==1)
	{
		isLeaf = true;
		val = grid[yMin][xMin];
		return;
	}

	bool yu = true;//存储与值
	bool huo = false;//存储或值
	for (int i = yMin; i <yMax; ++i)
	{
		for (int j = xMin; j <xMax; ++j)
		{
			yu &= grid[i][j];
			huo |= grid[i][j];
		}
	}
	if (yu == true || huo == false)
	{
		isLeaf = true;
		val = yu == true ? true:false ;
		return;
	}
	isLeaf = false;
	val = false;
}

Node* construct(vector<vector<int>>& grid) {
	int r = grid.size();
	int c = grid[0].size();

	if (r == 0 || c == 0)
		return NULL;

	bool leaf;
	bool val;
	IsLeaf(grid, 0, c, 0, r,leaf,val);
	if (leaf == true)
	{
		Node* pNode = new Node(val, leaf, NULL, NULL, NULL, NULL);
		return pNode;
	}
	else
	{
		vector<vector<int>> vectopLeft, vectopRight, vecbottomLeft, vecbottomRight;
		vector<int> topLefttemp, topRighttemp, bottomLefttemp,bottomRighttemp;
		for (int i = 0; i < r; ++i)
		{
			topLefttemp.clear();
			topRighttemp.clear();
			bottomLefttemp.clear();
			bottomRighttemp.clear();
			for (int j = 0; j <c; ++j)
			{
				if (i < r / 2 && j < c / 2)
				{
					topLefttemp.push_back(grid[i][j]);
				}
				else if (i < r / 2 && j >= c / 2)
				{
					topRighttemp.push_back(grid[i][j]);
				}
				else if (i >= r / 2 && j < c/2)
				{
					bottomLefttemp.push_back(grid[i][j]);
				}
				else if (i >= r / 2 && j >= c / 2)
				{
					bottomRighttemp.push_back(grid[i][j]);
				}
			}
			if (topLefttemp.size() > 0)
				vectopLeft.push_back(topLefttemp);
			if (topRighttemp.size() > 0)
				vectopRight.push_back(topRighttemp);
			if (bottomLefttemp.size() > 0)
				vecbottomLeft.push_back(bottomLefttemp);
			if (bottomRighttemp.size() > 0)
				vecbottomRight.push_back(bottomRighttemp);
		}
		Node* topLeft = construct(vectopLeft);
		Node* topRight = construct(vectopRight);
		Node* bottomLeft = construct(vecbottomLeft);
		Node* bottomRight = construct(vecbottomRight);
		Node* pNode = new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
		return pNode;
	}
}

//前序遍历四叉树
void QianxuBianLiSiChashu(Node* pNode)
{
	if (pNode == NULL)
		return;

	cout << "值：" << pNode->val << "，是否是叶子节点" << pNode->isLeaf << endl;
	if (pNode->topLeft)
		QianxuBianLiSiChashu(pNode->topLeft);
	if(pNode->topRight)
		QianxuBianLiSiChashu(pNode->topRight);
	if(pNode->bottomLeft)
		QianxuBianLiSiChashu(pNode->bottomLeft);
	if (pNode->bottomRight)
		QianxuBianLiSiChashu(pNode->bottomRight);
}
void main() {
	//test
	vector<vector<int>>grid = {
		{1,1,1,1,0,0,0,0},
		{1,1,1,1,0,0,0,0},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,0,0,0,0},
	   { 1,1,1,1,0,0,0,0 },
	   { 1,1,1,1,0,0,0,0 },
	   { 1,1,1,1,0,0,0,0 } };
	Node* pNode = construct(grid);
	QianxuBianLiSiChashu(pNode);
	//test end
	system("pause");
}
