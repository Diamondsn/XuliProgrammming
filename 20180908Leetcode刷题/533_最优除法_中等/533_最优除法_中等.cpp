#include<iostream>
#include<string>
#include<vector>
using namespace std;

//给定一组正整数，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4 。
//
//但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。你需要找出怎么添加括号，才能得到最大的结果，并且返回相应的字符串格式的表达式。你的表达式不应该含有冗余的括号。
//
//示例：
//输入: [1000,100,10,2]
//输出: "1000/(100/10/2)"
//解释:
//1000/(100/10/2) = 1000/((100/10)/2) = 200
//但是，以下加粗的括号 "1000/((100/10)/2)" 是冗余的，
//因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。
//
//其他用例:
//1000/(100/10)/2 = 50
//1000/(100/(10/2)) = 50
//1000/100/10/2 = 0.5
//1000/100/(10/2) = 2
//
//说明:
//输入数组的长度在 [1, 10] 之间。
//数组中每个元素的大小都在 [2, 1000] 之间。
//每个测试用例只有一个最优除法解。

//这题triky
//初步思路:维护两个二维数组，分别存储从横坐标到纵坐标范围内的数经过
//除法加括号以后运算出的最小值和最大值，再动态规划，而且只能算出值很难知道路径
//x1/x2/…/xn,无论在之间加多少个括号,x1总是作为被除数,x2总是作为除数,因此结果最大的做法是将x3到xn的所有除法转换为乘法,即x1/(x2/…/xn)=x1/x2*x3*…*xn.
string optimalDivision(vector<int>& nums) {
	string res;
	if (nums.size() == 1)
	{
		res = to_string(nums[0]);
	}
	else if (nums.size() == 2) {
		res = to_string(nums[0]) + "/" + to_string(nums[1]);
	}
	else {
		string temp=to_string(nums[1]);
		for (int i = 2; i < nums.size(); ++i) {
			temp += "/" + to_string(nums[i]);
		}
		res = to_string(nums[0]) + "/(" + temp + ")";
	}
	return res;
}

void main(){
	//test
	vector<int>nums = { 1000, 100, 10, 2 };
	string a = optimalDivision(nums);
	cout << a << endl;
	//test end
	system("pause");
}
