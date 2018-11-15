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

//在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的
//单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
//
//现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。
//如果继承词有许多可以形成它的词根，则用最短的词根替换它。
//
//你需要输出替换之后的句子。
//
//示例 1:
//输入: dict(词典) = ["cat", "bat", "rat"]
//sentence(句子) = "the cattle was rattled by the battery"
//输出: "the cat was rat by the bat"
//
//注:
//输入只包含小写字母。
//1 <= 字典单词数 <=1000
//1 <=  句中词语数 <= 1000
//1 <= 词根长度 <= 100
//1 <= 句中词语长度 <= 1000

//构建的字典树不能区分正常前缀和最短前缀
//struct dicnode{
//	dicnode(){ vec.resize(26, NULL); };
//	vector<dicnode*>vec;
//};
//
//string replaceWords(vector<string>& dict, string sentence) {
//	//分隔字符串
//	int pos;
//	vector<string>senvec;
//	while ((pos = sentence.find_first_of(" ")) != sentence.npos){
//		if (pos > 0){
//			senvec.push_back(sentence.substr(0, pos));
//		}
//		sentence = sentence.substr(pos + 1);
//	}
//	if (sentence.size() > 0){
//		senvec.push_back(sentence);
//	}
//	//构建字典树
//	dicnode* head = new dicnode(),*cur=head;
//	for (string s : dict){
//		cur = head;
//		for (char c : s){
//			if (cur->vec[c - 'a'] == NULL){
//				cur->vec[c - 'a'] = new dicnode();
//				cur = cur->vec[c - 'a'];
//			}
//			else{
//				cur = cur->vec[c - 'a'];
//				break;//只保留最短的前缀
//			}
//		}
//		for (int i = 0; i < cur->vec.size();++i)
//			cur->vec[i] = NULL;
//	}
//	//替换
//	cur = head;
//	for (int i = 0; i < senvec.size(); ++i){
//		if (head->vec[senvec[i][0]-'a'] == NULL)
//			continue;
//		cur = head->vec[senvec[i][0] - 'a'];
//		//cur = head->vec[senvec[i][0]-'a'];
//		string tihuan;
//		//string tihuan = string(1,senvec[i][0]);
//		int j = 0;
//		for (; j+1 < senvec[i].size(); ++j){
//			if (cur == NULL){
//				
//				break;
//			}
//			else{
//				tihuan += string(1, senvec[i][j]);
//				cur = cur->vec[senvec[i][j+1] - 'a'];
//			}
//		}
//		
//		senvec[i] = tihuan;
//	}
//	//合成
//	string res;
//	if (senvec.size()>=1)
//	res += senvec[0];
//	for (int i = 1; i < senvec.size(); ++i){
//		res += " " + senvec[i];
//	}
//	return res;
//}

void main(){
	//test1
	vector<string>dict = {"cat","c", "bat", "rat" };
	string sentence = "the cattle was rattled by the battery";
	string res = replaceWords(dict, sentence);
	cout << res << endl;

	//test2
	dict = { "a", "aa", "aaa", "aaaa" };
	sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
	res = replaceWords(dict, sentence);
	cout << res << endl;
	//test end
	system("pause");
}