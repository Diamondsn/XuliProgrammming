#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//ʵ�� strStr() ������
//
//����һ�� haystack �ַ�����һ�� needle �ַ�����
//�� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)��
//��������ڣ��򷵻�  -1��
//
//ʾ�� 1:
//����: haystack = "hello", needle = "ll"
//���: 2
//
//ʾ�� 2:
//����: haystack = "aaaaa", needle = "bba"
//���: -1
//
//˵��:
//�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣
//
//���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ��
//����C���Ե� strstr() �Լ� Java�� indexOf() ���������

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
