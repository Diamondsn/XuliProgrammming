#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include"math.h"
using namespace std;

//����Ħ��˹���붨��һ�ֱ�׼���뷽ʽ����ÿ����ĸ��Ӧ��һ����һϵ�е�Ͷ�����ɵ��ַ�����
//���� : "a" ��Ӧ ".-", "b" ��Ӧ "-...", "c" ��Ӧ "-.-.", �ȵȡ�
//
//Ϊ�˷��㣬����26��Ӣ����ĸ��ӦĦ��˹��������£�
//
//[".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
//����һ�������б�ÿ�����ʿ���д��ÿ����ĸ��ӦĦ��˹�������ϡ����磬"cab" ����д�� "-.-.-....-"��(�� "-.-." + "-..." + ".-"�ַ����Ľ��)�����ǽ�����һ�����ӹ��̳������ʷ��롣
//
//�������ǿ��Ի�����дʲ�ͬ���ʷ����������
//
//���� :
//����: words = ["gin", "zen", "gig", "msg"]
//��� : 2
//���� :
//�����ʷ������� :
//"gin" -> "--...-."
//"zen" -> "--...-."
//"gig" -> "--...--."
//"msg" -> "--...--."
//
//���� 2 �ֲ�ͬ����, "--...-." �� "--...--.".

int uniqueMorseRepresentations(vector<string>& words) {

}

int main() {
	//test1
	vector<string> words;
	words.push_back("gin");
	words.push_back("zen");
	words.push_back("gig");
	words.push_back("msg");

	int a = uniqueMorseRepresentations(words);
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}