#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<unordered_set>
#include"time.h"
using namespace std;

//�ڱ�������, ��ָ����һ����ͨ���޻�������ͼ��
//
//����һ��ͼ����ͼ��һ������N���ڵ� (�ڵ�ֵ���ظ�1, 2, ..., N) ������һ�����ӵı߹��ɡ����ӵıߵ��������������1��N�м䣬�������ӵı߲����������Ѵ��ڵıߡ�
//
//���ͼ��һ���Ա���ɵĶ�ά���顣ÿһ���ߵ�Ԫ����һ��[u, v] ������ u < v����ʾ���Ӷ���u ��v������ͼ�ıߡ�
//
//����һ������ɾȥ�ıߣ�ʹ�ý��ͼ��һ������N���ڵ����������ж���𰸣��򷵻ض�ά�����������ֵıߡ��𰸱� [u, v] Ӧ������ͬ�ĸ�ʽ u < v��
//
//ʾ�� 1��
//����: [[1,2], [1,3], [2,3]]
//���: [2,3]
//����: ����������ͼΪ:
//  1
// / \
//2 - 3
//
//ʾ�� 2��
//����: [[1,2], [2,3], [3,4], [1,4], [1,5]]
//���: [1,4]
//����: ����������ͼΪ:
//5 - 1 - 2
//    |   |
//    4 - 3
//
//ע��:
//����Ķ�ά�����С�� 3 �� 1000��
//��ά�����е�������1��N֮�䣬����N����������Ĵ�С��

//����ʹ�ò��鼯��Ҳ���Ǽ��ϵĲ�����ϲ��������ڽӱ��ʾ��ͨ��ϵ
//���²��÷����϶�
//https://www.cnblogs.com/grandyang/p/7628977.html
//��������ò��鼯���������С������С
//https://blog.csdn.net/gl486546/article/details/79780126


//��1:���ý�С�Ŀռ�
//int find(int num, vector<int>&biao){
//	return num == biao[num] ? num : biao[num] = find(biao[num],biao);
//}
//
//vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//	vector<int>biao(edges.size() + 1);
//	for (int i =1; i < biao.size(); ++i){
//		biao[i] = i;
//	}
//	for (vector<int>edge : edges){
//		int res1 = find(edge[0], biao);
//		int res2 = find(edge[1], biao);
//		if (res1 == res2)return edge;
//		biao[res1] = res2;
//	}
//	return{};
//}

//���ò��鼯�����
int find(int num, vector<int>& biao){
	while (biao[num] != -1){
		num = biao[num];
	}
	return num;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	vector<int>biao(edges.size() + 1, -1);
	for (vector<int> edge : edges){
		int res1 = find(edge[0], biao);
		int res2 = find(edge[1], biao);
		if (res1 == res2)return edge;
		biao[res1] = res2;
	}
	return{};
}

void main(){
	//test1
	vector<vector<int>>edges = { { 1, 2 }, { 1, 3 }, { 2, 3 } };
	vector<int>res1 = findRedundantConnection(edges);
	cout << "test1" << endl;
	for (int m : res1)
		cout << m << endl;

	//test2
	cout << "test2" << endl;
	edges = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 4 }, { 1, 5 } };
	res1 = findRedundantConnection(edges);
	for (int m : res1)
		cout << m << endl;
	//test end
	system("pause");
}
