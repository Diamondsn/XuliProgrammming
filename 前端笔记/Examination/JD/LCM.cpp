#include <iostream>
using namespace std;
int LCM(int m,int n)
{
	int r, g;
	g = m*n; //记下两数之积
	while (1) //求出最大公约，辗转相除法，放到n中 
	{
		r = m%n;
		if (r == 0)  break;
		m = n;
		n = r;
	}
	g = g / n; //最小公倍=两数相乘/最大公约 

	return g;
}
int main(){
	int N;
	cin >> N;
	int  g =1;
	for (int i = 1; i <= N; i++){
		 g = LCM(g, i);
		
	}
	cout << g;
	system("pause");
	return 0;
}