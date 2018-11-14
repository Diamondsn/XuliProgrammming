#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<unordered_set>
#include"time.h"
#include<bitset>
#include<map>
#include<unordered_map>
using namespace std;

//给定一个非空字符串，其中包含字母顺序打乱的英文单词表示的数字0-9。按升序输出原始的数字。
//
//注意:
//输入只包含小写英文字母。
//输入保证合法并可以转换为原始的数字，这意味着像 "abc" 或 "zerone" 的输入是不允许的。
//输入字符串的长度小于 50,000。
//
//示例 1:
//输入: "owoztneoer"
//输出: "012" (zeroonetwo)
//
//示例 2:
//输入: "fviefuro"
//输出: "45" (fourfive)

//求出次数后必须匹配,下面代码不正确
//string originalDigits(string s) {
//	vector<string>dic = { "zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
//	map<char, int>mymap;
//	for (char i : s)
//		mymap[i]++;
//	string res;
//	for (int i = 0; i < dic.size(); ++i){
//		int num = INT_MAX;
//		for (char c : dic[i]){
//			if (num>mymap[c])num = mymap[c];
//		}
//		if (num > 0)
//		{
//			res += string(num, '0' + i);
//			for (char c : dic[i]){
//				mymap[c] -= num;
//			}
//		}
//	}
//	return res;
//}

//string originalDigits(string s) {
//	vector<string>dic = { "zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
//	vector<int>shunxu = {8,4,2,6,3,5,7,0,1,9};//必须考虑顺序，顺序由所有字符映射到的数字，逐一消除得到
//	vector<int>nums(10, 0);
//	map<char, int>mymap;
//	for (char i : s)
//		mymap[i]++;
//
//	string res;
//	for (int i = 0; i < shunxu.size(); ++i){
//		int num = INT_MAX;
//		for (char c : dic[shunxu[i]]){
//			if (num>mymap[c])num = mymap[c];
//		}
//		if (num > 0)
//		{
//			nums[shunxu[i]] = num;
//			for (char c : dic[shunxu[i]]){
//				mymap[c] -= num;
//			}
//		}
//	}
//	for (int i = 0; i < nums.size(); ++i){
//		res += string(nums[i], '0' +i);
//	}
//	return res;
//}

//速度非常快，不用频繁对map进行操作
string originalDigits(string s) {
	string res = "";
	vector<int> counts(128, 0), nums(10, 0);
	for (char c : s) counts[c]++;
	nums[0] = counts['z'];
	nums[2] = counts['w'];
	nums[4] = counts['u'];
	nums[6] = counts['x'];
	nums[8] = counts['g'];
	nums[1] = counts['o'] - nums[0] - nums[2] - nums[4];
	nums[3] = counts['h'] - nums[8];
	nums[5] = counts['f'] - nums[4];
	nums[7] = counts['s'] - nums[6];
	nums[9] = counts['i'] - nums[6] - nums[8] - nums[5];
	for (int i = 0; i<nums.size(); i++)
			res += string(nums[i],('0'+i));
	return res;
}

void main(){
	//test1
	string a = originalDigits("owoztneoer");

	//test2
	string b = originalDigits("fviefuro");
	
	//test3
	//超长字符串必须分行写，否则编译器限制单行最长字符串
	string d = "zeroonetwothreefourfivesixseveneightnine";
	string c = originalDigits(d);

	cout << a << endl << b << endl<<c<<endl;
	//test end
	system("pause");
}