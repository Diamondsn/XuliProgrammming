#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	//int first = M;
	int first = int(M*pow(2,(N-1))/double(pow(2,N)-1));
		while (1) {
			int s = 0;
			for (int i = 0; i < N; i++) {
				int temp = pow(2, i);
				if (first%temp == 0) {
					s += first / temp;
					if (s > M) break;
				}
				else {
					s += first / temp + 1;
					if (s > M) break;
				}
			}
			if (s <= M)
				break;
			first--;
		}
	cout << first;
	system("pause");
	return 0;
}