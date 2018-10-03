#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//实现 strStr() 函数。
//
//给定一个 haystack 字符串和一个 needle 字符串，
//在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
//如果不存在，则返回  -1。
//
//示例 1:
//输入: haystack = "hello", needle = "ll"
//输出: 2
//
//示例 2:
//输入: haystack = "aaaaa", needle = "bba"
//输出: -1
//
//说明:
//当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
//
//对于本题而言，当 needle 是空字符串时我们应当返回 0 。
//这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

int strStr(string haystack, string needle) {

}

int main() {
	//test1
	TreeNode* n = new TreeNode(3);
	TreeNode* n_4 = new TreeNode(4);
	TreeNode* n_5 = new TreeNode(5);
	TreeNode* n_1 = new TreeNode(1);
	TreeNode* n_2 = new TreeNode(2);
	n->left = n_4;
	n->right = n_5;
	n_4->left = n_1;
	n_4->right = n_2;

	TreeNode* t = new TreeNode(4);
	TreeNode* t_1 = new TreeNode(1);
	TreeNode* t_2 = new TreeNode(2);
	t->left = t_1;
	t->right = t_2;

	bool a = isSubtree(n, t);

	//test2
	TreeNode* n_0 = new TreeNode(0);
	n_2->left = n_0;
	bool b = isSubtree(n, t);
	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}
