#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//我们正在玩一个猜数字游戏。 游戏规则如下：
//我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
//每次你猜错了，我会告诉你这个数字是大了还是小了。
//你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：
//
//-1 : 我的数字比较小
// 1 : 我的数字比较大
// 0 : 恭喜！你猜对了！
//
//示例 :
//输入: n = 10, pick = 6
//输出: 6

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
static int pick = 1702766719;
int guess(int num){
	if (num == pick)return 0;
	else if (num > pick)return -1;
	else return 1;
}

int guessNumber(int n) {
	long long left = 1, right = n;
	while (left <= right){
		long long mid = (left + right) / 2;//可能超出int能表达的最大数
		int res = guess(mid);
		if (res == 0)
			return mid;
		else if (res == 1)
			left = mid + 1;
		else if (res == -1)
			right = mid - 1;
	}
}

int main() {
	//test1
	int a = guessNumber(2126753390);//6
	cout << a << endl;
	//test end

	system("pause");
	return 0;
}