#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
//
//���磬�������������
//A:          a1 �� a2
//                   �K
//                     c1 �� c2 �� c3
//                   �J            
//B:     b1 �� b2 �� b3
//�ڽڵ� c1 ��ʼ�ཻ��
//
//ע�⣺
//�����������û�н��㣬���� null.
//�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
//�ɼٶ���������ṹ��û��ѭ����
//���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档
// 
//��л:
//�ر��л @stellari ��Ӵ����Ⲣ�������в���������

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

}

void LianBiaoBianLi(ListNode* root) {
	while (root) {
		cout << root->val << "->";
		root = root->next;
	}
}
int main() {
	//test1
	ListNode* a = new ListNode(1);
	//test end

	system("pause");
	return 0;
}