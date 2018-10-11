#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 -1。
//
//举个例子，A = "abcd"，B = "cdabcdab"。
//
//答案为 3， 因为 A 重复叠加三遍后为 “abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B 并不是其子串。
//
//注意:
//A 与 B 字符串的长度在1和10000区间范围内。

/*******************************/
//注意:以下代码为错误示范，深入字符串内部进行裁剪，会出现越界，首尾字符相同导致问题复杂性骤增
/*******************************/
//bool isrepeated(string A, string B){
//	if (B.size() % A.size() != 0)return false;
//	for (int i = 0; i < B.size(); i += A.size())
//	{
//		if (A.compare(B.substr(i, A.size())) != 0)
//			return false;
//	}
//	return true;
//}
//
//int repeatedStringMatch(string A, string B) {
//	if (A.size() >= B.size() && A.find(B) !=string::npos)
//		return 1;
//	int i, j;
//	for (i = 0; i < B.size(); ++i){
//		if (B[i] == A[0])break;
//	}
//	for (j = B.size() - 1; j >= 0; --j){
//		if (B[j] == A[A.size() - 1])break;
//	}
//	if (i>A.size()||j<(int)B.size()-(int)A.size()|| !isrepeated(A, B.substr(i, j - i + 1)))
//		return -1;
//	int res = (j - i + 1) /A.size();
//	if (i != 0){
//		string left = B.substr(0, i );
//		for (int m = 0; m < i; ++m){
//			if (A[A.size() - 1 - m] != left[left.size() - 1 - m])
//				return -1;
//		}
//		res += 1;
//	}
//	if (j != B.size() - 1){
//		string right = B.substr(j+1, B.size() - j);
//		for (int m = 0; m < right.size(); ++m){
//			if (A[m] != right[m])return -1;
//		}
//		res += 1;
//	}
//	return res;
//}

/**************************/
//正确思路，在A的长度小于B的长度时，不断累积A，判断累加后的A是不是B的子串
/**************************/
int repeatedStringMatch(string A, string B){
	string temp = A;
	int count = 1;
	while (A.size() < B.size()){
		A += temp;
		count++;
	}
	if (A.find(B) != string::npos)//string::npos是size_t的最大值，其实类似于（unsighed int）-1;
		return count;
	A += temp;//此处需要再次累加，防止"abcd"，"cdabcdab"测试用例，累积两次不行，三次就行
	if (A.find(B) != string::npos)
		return count + 1;
	return -1;
}

int main() {
	//test1
	int a = repeatedStringMatch("abcd", "cdabcdab");

	//test2
	int b = repeatedStringMatch("aaaaaaaaaaaaaaaaaaaaaab","ba");
	cout << a << endl<<b<<endl ;
	//test end

	system("pause");
	return 0;
}