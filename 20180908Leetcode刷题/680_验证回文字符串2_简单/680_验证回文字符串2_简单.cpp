#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
//
//示例 1:
//输入: "aba"
//输出: True
//
//示例 2:
//输入: "abca"
//输出: True
//解释: 你可以删除c字符。
//
//注意:
//字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

bool isHuiWen(string s){
	int left = 0, right = s.size() - 1;
	while (left <= right){
		if (s[left] != s[right])
			return false;
		else{
			left++;
			right--;
		}
	}
	return true;
}

//注意:此种方法无法通过test3，在删除哪一个字符时有判断的先后顺序，可能导致错误
//bool validPalindrome(string s) {
//	int left = 0, right = s.size() - 1;
//	int cur = 1;
//	while (left <= right){
//		if (s[left] == s[right])
//		{
//			left++;
//			right--;
//		}
//		else{
//			if (cur && left + 1 < s.size() && s[left + 1] == s[right]){//如果这两种情况都能满足
//				cur--;
//				left += 2;
//				right--;
//			}
//			else if (cur && right - 1 >= 0 && s[left] == s[right - 1])
//			{
//				cur--;
//				right -= 2;
//				left++;
//			}
//			else
//				return false;
//		}
//	}
//	return true;
//}

bool validPalindrome(string s) {
	int left = 0, right = s.size() - 1;
	while (left <= right){
		if (s[left] == s[right])
		{
			left++;
			right--;
		}
		else{
			if (isHuiWen(s.substr(left, right - left)) || isHuiWen(s.substr(left + 1, right - left)))
				return true;
			else
				return false;
		}
	}
	return true;
}

int main() {
	//test1
	bool a = validPalindrome("aba");

	//test2
	bool b = validPalindrome("abca");

	//test3
	bool c = validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
	cout << a << endl << b << endl << c << endl;
	//test end

	system("pause");
	return 0;
}