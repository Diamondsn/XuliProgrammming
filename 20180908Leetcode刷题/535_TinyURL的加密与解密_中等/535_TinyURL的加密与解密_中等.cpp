#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
using namespace std;

//TinyURL是一种URL简化服务， 比如：当你输入一个URL https ://leetcode.com/problems/design-tinyurl 时，它将返回一个简化的URL http://tinyurl.com/4e9iAk.
//
//要求：设计一个 TinyURL 的加密 encode 和解密 decode 的方法。你的加密和解密算法如何设计和运作是没有限制的，
//你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。

class Solution {
public:

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {

	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {

	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
	//test1
	Solution solution;
	string res=solution.decode(solution.encode("https ://leetcode.com/problems/design-tinyurl"));
	cout << res << endl;
	//test end

	system("pause");
	return 0;
}