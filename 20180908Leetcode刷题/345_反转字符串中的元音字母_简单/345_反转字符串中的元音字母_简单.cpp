#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//��дһ�����������ַ�����Ϊ���룬��ת���ַ����е�Ԫ����ĸ��
//
//ʾ�� 1:
//����: "hello"
//���: "holle"
//
//ʾ�� 2:
//����: "leetcode"
//���: "leotcede"
//
//˵��:
//Ԫ����ĸ��������ĸ"y"��

void swap(string& s, int i, int j)
{
	if (i == j || s[i]==s[j])
		return;

	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

bool isVowels(char s)
{
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'
		|| s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
		return true;

	return false;
}
string reverseVowels(string s) {
	if (s.size() < 1)
		return s;
	int i = -1, j = s.size();
	while (i < j)
	{
		while (i<(int)s.size() && !isVowels(s[++i]));//ǰ����ж���int��size_t�ж�-1>5
		while (j >= 1 && !isVowels(s[--j]));
		swap(s, i, j);
	}
	swap(s, i, j);
	return s;
}

int main() {
	//test1
	string a = reverseVowels("race car");

	//test2
	string b = reverseVowels("leetcode");

	cout << a << endl << b << endl;
	//test end

	system("pause");
	return 0;
}