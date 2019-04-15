//#include<string>
//#include<vector>
//#include<iostream>
//#include<algorithm>
//#include<stack>
//#include<math.h>
//#include<map>
//#include<set>
//using namespace std;
//
//void jisuan(int n, int m, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int x4, int& res1, int res2)
//{
//	int chushi = n*m;
//	int chushibai = 0, chushihei = 0;
//	if (n*m % 2 == 0)
//	{
//		chushihei = n*m / 2;
//		chushibai = n*m / 2;
//	}
//	else{
//		chushibai = n*m / 2 + 1;
//		chushihei = n*m / 2;
//	}
//	
//}
//
//int main() {
//	//test1
//	int n, s, m;
//	cin >> n ;
//	vector<int>vec(n);
//	vector<int>res;
//	for (int i = 0; i < n; ++i){
//		vec[i] = i + 1;
//	}
//	int count = n;
//
//	//提问次数
//	int count;
//	vector<int>qipandaxiao;
//	vector<int>bai;
//	vector<int>hei;
//	for (int i = 0; i < count; ++i)
//	{
//		int n, m;
//		cin >> n >> m;
//		qipandaxiao.push_back(n);
//		qipandaxiao.push_back(m);
//		int b1, b2, b3, b4;
//		cin >> b1 >> b2 >> b3 >> b4;
//		bai.push_back(b1);
//		bai.push_back(b2);
//		bai.push_back(b3);
//		bai.push_back(b4);
//		int h1, h2, h3, h4;
//		cin >> h1 >> h2 >> h3 >> h4;
//		hei.push_back(h1);
//		hei.push_back(h2);
//		hei.push_back(h3);
//		hei.push_back(h4);
//	}
//
//	for (int i = 0; i < count; ++i)
//	{
//		int res1, res2;
//		jisuan(qipandaxiao[2 * i], qipandaxiao[2 * i + 1], bai[4 * i], bai[4 * i + 1], bai[4 * i + 2], bai[4 * i + 3], hei[4 * i], hei[4 * i + 1], hei[4 * i + 2], hei[4 * i + 3], res1, res2);
//		cout << res1 << " " << res2 << endl;
//	}
//	system.pause("0");
//	//test end
//	return 0;
//}


#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<set>
#define LL long long
using namespace std;
//https://www.cnblogs.com/zquzjx/p/10013995.html
LL n, m, B, W;
LL X1, Y1, X2, Y2, X3, Y3, X4, Y4;
void col(LL lx, LL ly, LL rx, LL ry, bool flag) {
	LL N = ry - ly + 1LL, M = rx - lx + 1LL, b, w;

	if ((lx + ly) % 2LL) // 最左下一格为黑色
		w = N*M / 2LL, b = w + (N*M % 2LL);
	else // 否则为白色
		b = N*M / 2LL, w = b + (N*M % 2LL);

	if (flag) W += b, B -= b; // 涂白
	else B += w, W -= w; // 涂黑
}
void cut(LL lx, LL ly, LL rx, LL ry) {
	if (lx > rx || ly > ry) return; // 矩形不合法
	if (rx<X3 || ry<Y3 || lx>X4 || ly>Y4) {
		col(lx, ly, rx, ry, 1); return;
	} // 当前矩形不会被黑色部分切割到 直接涂为白色
	if (lx < X3) cut(lx, ly, X3 - 1LL, ry), lx = X3;
	if (rx > X4) cut(X4 + 1LL, ly, rx, ry), rx = X4;
	if (ly < Y3) cut(lx, ly, rx, Y3 - 1LL), ly = Y3;
	if (ry > Y4) cut(lx, Y4 + 1LL, rx, ry), ry = Y4;
}
int main() {
	
		//提问次数
		int count;
		cin >> count;
		vector<int>qipandaxiao;
		vector<int>bai;
		vector<int>hei;
		for (int i = 0; i < count; ++i)
		{
			int n, m;
			cin >> n >> m;
			qipandaxiao.push_back(n);
			qipandaxiao.push_back(m);
			int b1, b2, b3, b4;
			cin >> b1 >> b2 >> b3 >> b4;
			bai.push_back(b1);
			bai.push_back(b2);
			bai.push_back(b3);
			bai.push_back(b4);
			int h1, h2, h3, h4;
			cin >> h1 >> h2 >> h3 >> h4;
			hei.push_back(h1);
			hei.push_back(h2);
			hei.push_back(h3);
			hei.push_back(h4);
		}
	
		for (int i = 0; i < count; ++i)
		{
			n = qipandaxiao[2 * i];
			m = qipandaxiao[2 * i + 1];
			B = n*m / 2;
			W = B + (n*m % 2);
			X1 = bai[4 * i];
			Y1 = bai[4 * i + 1];
			X2 = bai[4 * i + 2];
			Y2 = bai[4 * i + 3];
			X3 = hei[4 * i];
			Y3 = hei[4 * i + 1];
			X4 = hei[4 * i + 2];
			Y4 = hei[4 * i + 3];
			cut(X1,Y1,X2,Y2);
			col(X3,Y3,X4,Y4,0);
			cout << W << " " << B << endl;
		}
		//system("pause");
		//test end
		return 0;
	}