#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//编写一个程序，找到两个单链表相交的起始节点。
//
//例如，下面的两个链表：
//A:          a1 → a2
//                   ↘
//                     c1 → c2 → c3
//                   ↗            
//B:     b1 → b2 → b3
//在节点 c1 开始相交。
//
//注意：
//如果两个链表没有交点，返回 null.
//在返回结果后，两个链表仍须保持原有的结构。
//可假定整个链表结构中没有循环。
//程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
// 
//致谢:
//特别感谢 @stellari 添加此问题并创建所有测试用例。

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//第一种解法:先分别遍历链表，得到两个链表的元素数量，后长的链表先走多的步数，知道两个指针相遇
//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//	if (headA == NULL || headB == NULL)return NULL;
//	int count1 = 0,count2 = 0;
//	ListNode* p1 = headA;
//	ListNode* p2 = headB;
//	while (p1 != NULL)
//	{
//		count1++;
//		p1 = p1->next;
//	}
//	while (p2 != NULL)
//	{
//		count2++;
//		p2 = p2->next;
//	}
//	p1 = headA; p2 = headB;
//	if (count1 > count2)
//	{
//		while (count1 != count2)
//		{
//			p1 = p1->next;
//			count1--;
//		}
//	}
//	else if (count1 < count2)
//	{
//		while (count1 != count2)
//		{
//			p2 = p2->next;
//			count2--;
//		}
//	}
//	while (p1 && p2 &&p1 != p2)
//	{
//		p1 = p1->next;
//		p2 = p2->next;
//	}
//	return p1==NULL || p2==NULL?NULL:p1;
//}

//第二种解法:巧法
//当链表到尾部以后自动跳转到另一条链表，当两个指针均跳转后相遇的就是相交的元素
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL)return NULL;
	ListNode* p1 = headA;
	ListNode* p2 = headB;
	bool flag = true;
	while (p1->next && p2->next) {
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1->next == NULL) {
		p1 = headB;
	}
	else {
		flag = false;
		p2 = headA;
	}
	while (p1->next && p2->next) {
		p1 = p1->next;
		p2 = p2->next;
	}
	if (flag &&p2->next == NULL)
		p2 = headA;
	else if(!flag&&p1->next==NULL)
		p1 = headB;
	while (p1 && p2 && p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1 == NULL || p2 == NULL ? NULL : p1;
}

//第二种解法的代码精简版
//参考https://blog.csdn.net/qq_33168253/article/details/79922441
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	//这个思路就是 ListA + ListB = A + intersection + Bb + intersection
	//             ListB + ListA = Bb + intersection + A + intersection
	//           用大A表示ListA里面非共有 Bb表示listB里面非共有的，可以看到在第二个intersection的开头两个链表长度是一样的，必然相等
	//           所以我们可以遍历A再遍历B，另一个遍历B再遍历A，两个指针必定在第二个交集处相遇，没有交集就是空指针
	ListNode *cursorA = headA;
	ListNode *cursorB = headB;
	if (!cursorA || !cursorB)
		return NULL;
	while (cursorA != cursorB)
	{
		if (!cursorA)
			cursorA = headB;
		else
			cursorA = cursorA->next;
		if (!cursorB)
			cursorB = headA;
		else
			cursorB = cursorB->next;
	}
	return cursorA;
}

	
void LianBiaoBianLi(ListNode* root) {
	while (root) {
		cout << root->val << "->";
		root = root->next;
	}
}
int main() {
	//test1
	ListNode* a1 = new ListNode(1);
	ListNode* a2 = new ListNode(2);
	ListNode* c1 = new ListNode(1);
	ListNode* c2 = new ListNode(2);
	ListNode* c3 = new ListNode(3);
	ListNode* b1 = new ListNode(1);
	ListNode* b2 = new ListNode(2);
	ListNode* b3 = new ListNode(3);
	a1->next = a2;
	a2->next = c1;
	c1->next = c2;
	c2->next = c3;
	b1->next = b2;
	b2->next = b3;
	b3->next = c1;
	ListNode* res = getIntersectionNode(a1, b1);
	LianBiaoBianLi(res);
	//test end

	system("pause");
	return 0;
}