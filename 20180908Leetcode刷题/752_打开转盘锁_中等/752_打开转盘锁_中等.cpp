#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;

//你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
//每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
//
//锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
//
//列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
//
//字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。
//
//示例 1:
//输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
//输出：6
//
//解释：
//可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
//注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
//因为当拨动到 "0102" 时这个锁就会被锁定。
//
//示例 2:
//输入: deadends = ["8888"], target = "0009"
//输出：1
//解释：
//把最后一位反向旋转一次即可 "0000" -> "0009"。
//
//示例 3:
//输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
//输出：-1
//
//解释：
//无法旋转到目标数字且不被锁定。
//
//示例 4:
//输入: deadends = ["0000"], target = "8888"
//输出：-1
//
//提示：
//死亡列表 deadends 的长度范围为 [1, 500]。
//目标数字 target 不会在 deadends 之中。
//每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。

//以下是回溯算法，其实是深度优先遍历，要求的是广度优先遍历，使用队列来做，一次访问一层
//注意:以下搜索方法不可取，无效搜索太多，在10000个方格中做搜索，每个节点有8条分支路径
//应该在搜索的基础上加入其他引导
//void dfs(int& res, vector<vector<vector<vector<bool>>>>&vec, string cur, string &target,int num){
//	if (!vec[stoi(cur.substr(0, 1))][stoi(cur.substr(1, 1))][stoi(cur.substr(2, 1))][stoi(cur.substr(3, 1))])return;
//	if (cur.compare(target) == 0){
//		if (num < res)res = num;
//		return;
//	}
//	else if (num >= 40)return;
//	else{
//		vec[stoi(cur.substr(0, 1))][stoi(cur.substr(1, 1))][stoi(cur.substr(2, 1))][stoi(cur.substr(3, 1))] = false;
//		vector<string>path;
//		for (int i = 0; i < cur.size(); ++i){
//			string str = cur;
//			str[i] = ((stoi(str.substr(i, 1)) + 9) % 10) + '0';
//			path.push_back(str);
//			str = cur;
//			str[i] = ((stoi(str.substr(i, 1)) + 11) % 10) + '0';
//			path.push_back(str);
//		}
//		for (string st : path){
//			dfs(res, vec, st, target, num + 1);
//		}
//	}
//}
//
//int openLock(vector<string>& deadends, string target) {
//	vector<vector<vector<vector<bool>>>>vec(10, vector<vector<vector<bool>>>(10, vector<vector<bool>>(10, vector<bool>(10, true))));
//	for (int i = 0; i < deadends.size(); ++i){
//		vec[stoi(deadends[i].substr(0, 1))][stoi(deadends[i].substr(1, 1))][stoi(deadends[i].substr(2, 1))][stoi(deadends[i].substr(3, 1))] = false;
//	}
//	int res=INT_MAX,num=0;
//	string cur = "0000";
//	dfs(res, vec, cur, target,num);
//	return res==INT_MAX?-1:res;
//}

//https://blog.csdn.net/qq_26410101/article/details/82919415
//https://blog.csdn.net/QingyunAlgo/article/details/80589440
int openLock(vector<string>& deadends, string target) {
	queue<string>q;
	unordered_set<string>dead(deadends.begin(),deadends.end());
	unordered_set<string>visited;//表示访没访问可以用vector<bool>(10000,false),这更快
	string init = "0000";
	if (dead.find(target) != dead.end() || dead.find(init) != dead.end())return-1;
	q.push(init);
	int num = 0;
	while (!q.empty()){
		for (int m = q.size(); m > 0; --m){
			string cur = q.front();
			q.pop();
			if (target.compare(cur) == 0)return num;
			string temp = cur;
			for (int i = 0; i < 4; ++i){
				temp[i] = (temp[i] - '0' + 1) % 10 + '0';
				if (visited.find(temp) == visited.end() && dead.find(temp) == dead.end())
				{
					visited.insert(temp);
					q.push(temp);
				}

				temp[i] = (temp[i] - '0' + 8) % 10 + '0';
				if (visited.find(temp) == visited.end() && dead.find(temp) == dead.end())
				{
					visited.insert(temp);
					q.push(temp);
				}
				temp = cur;
			}
		}
		num++;
	}
	return -1;


	/*queue<string> q;
	string start = "0000";
	unordered_set<string> hash_dead;
	unordered_set<string> visited;
	visited.insert(start);
	for (string itm : deadends) hash_dead.insert(itm);
	if (hash_dead.find(start) != hash_dead.end()) return -1;
	int res = 0;
	q.push(start);
	while (!q.empty()) {
		for (int i = q.size(); i > 0; i--) {
			string top = q.front(); q.pop();
			if (top.compare(target) == 0) return res;
			string back = top;
			for (int j = 0; j < 4; j++) {
				top[j] = (top[j] - '0' + 1) % 10 + '0';
				if (visited.find(top) == visited.end() && hash_dead.find(top) == hash_dead.end()) {
					visited.insert(top);
					q.push(top);
				}
				top[j] = (top[j] - '0' + 8) % 10 + '0';
				if (visited.find(top) == visited.end() && hash_dead.find(top) == hash_dead.end()) {
					visited.insert(top);
					q.push(top);
				}
				top = back;
			}
		}
		res++;
	}
	return -1;*/
}

void main(){
	//test1
	vector<string>deadends = { "0201", "0101", "0102", "1212", "2002" };
	string target = "0202";
	int a = openLock(deadends, target);

	//test2
	deadends = { "8888" };
	target = "0009";
	int b = openLock(deadends, target);

	//test3
	deadends = { "8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888" };
	target = "8888";
	int c = openLock(deadends, target);

	//test4
	deadends = { "0000" };
	target = "8888";
	int d = openLock(deadends, target);
	cout << a << endl << b << endl << c << endl << d << endl;

	//test end
	system("pause");
}
