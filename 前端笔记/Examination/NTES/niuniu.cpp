#include <iostream>
#include <string>
using namespace std;
int main(){
	int N, L = 0, R = 0;
	cin >> N;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == 'L'){
			L++;
		}
		else{
			R++;
		}
	}
	int dir = L - R;
	switch (dir){
	case 0:
		cout << "N";
		break;
	case 1:
		cout << "W";
		break;
	case 2:
		cout << "S";
		break;
	case 3:
		cout << "E";
		break;
	case -1:
		cout << "E";
		break;
	case -2:
		cout << "S";
		break;
	case -3:
		cout << "W";
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}