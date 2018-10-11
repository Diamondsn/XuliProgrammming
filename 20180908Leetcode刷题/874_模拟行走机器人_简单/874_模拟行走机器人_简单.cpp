#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

//机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。
//该机器人可以接收以下三种类型的命令：
//
//-2：向左转 90 度
//-1：向右转 90 度
//1 <= x <= 9：向前移动 x 个单位长度
//在网格上有一些格子被视为障碍物。
//
//第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])
//
//如果机器人试图走到障碍物上方，那么它将停留在障碍物的前一个网格方块上，
//但仍然可以继续该路线的其余部分。
//
//返回从原点到机器人的最大欧式距离的平方。
//
//示例 1：
//输入: commands = [4,-1,3], obstacles = []
//输出: 25
//解释: 机器人将会到达 (3, 4)
//
//示例 2：
//输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
//输出: 65
//解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
// 
//提示：
//
//0 <= commands.length <= 10000
//0 <= obstacles.length <= 10000
//-30000 <= obstacle[i][0] <= 30000
//-30000 <= obstacle[i][1] <= 30000
//答案保证小于 2 ^ 31

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
	int direction = 1;//默认北方;
	int x = 0, y = 0;
	for (int i = 0; i < commands.size(); ++i) {
		if (commands[i] == -1) {
			if (direction == 4)
				direction = 1;
			else
				direction += 1;
		}
		else if (commands[i] == -2) {
			if (direction == 1)
				direction = 4;
			else
				direction -= 1;
		}else if (commands[i] > 0) {
			bool flag = true;
			if (direction == 1) {//北方
				int maxy = y + commands[i];
				while (flag &&y+1 <= maxy) {
					for (int m = 0; m < obstacles.size(); ++m) {
						if (obstacles[m][0] == x && obstacles[m][1] == y+1)
						{
							flag = false;
							break;
						}
					}
					if (flag)y++;
				}
			}
			else if (direction == 2) {//东方
				int maxx = x + commands[i];
				while (flag &&x + 1 <= maxx) {
					for (int m = 0; m < obstacles.size(); ++m) {
						if (obstacles[m][0] == x+1 && obstacles[m][1] == y )
						{
							flag = false;
							break;
						}
					}
					if (flag)x++;
				}
			}
			else if (direction == 3) {//南方
				int miny = y - commands[i];
				while (flag &&y - 1 >= miny) {
					for (int m = 0; m < obstacles.size(); ++m) {
						if (obstacles[m][0] == x && obstacles[m][1] == y-1)
						{
							flag = false;
							break;
						}
					}
					if (flag)y--;
				}
			}
			else if (direction == 4) {//西方
				int minx = x - commands[i];
				while (flag &&x - 1 >= minx) {
					for (int m = 0; m < obstacles.size(); ++m) {
						if (obstacles[m][0] == x-1 && obstacles[m][1] == y )
						{
							flag = false;
							break;
						}
					}
					if (flag)x--;
				}
			}
		}
	}
	return x*x + y*y;
}

int main() {
	//test1
	vector<int>commands = { 4,-1,3 };
	vector<vector<int>>obstacles = {};
	int a = robotSim(commands,obstacles);

	//test2
	commands = { 4,-1,4,-2,4 };
	obstacles = { {2,4} };
	int b = robotSim(commands, obstacles);

	//test3
	commands = { -2, -1, 4, 7, 8 };
	obstacles = { {1, 1}, {2, 1}, {4, 4}, {5, -5}, {2, -3}, {-2, -3}, {-1, -3}, {-4, -1}, {-4, 3}, {5, 1} };
	int c = robotSim(commands, obstacles);
	cout << a << endl << b << endl<<c<<endl;
	//test end

	system("pause");
	return 0;
}