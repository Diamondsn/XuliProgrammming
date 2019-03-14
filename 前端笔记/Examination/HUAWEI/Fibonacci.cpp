// #include <iostream>
// #include <vector>
// using namespace std;
// int fibonac(int n)；
// int main(){
	// int n;
	// cin>>n;
	// cout<<fibonac(n);
// }
// int fibonac(int n){
	// if(n==1||n==2){
		// return 1;	
	// }else{
		// return fibonac(n-1)+fibonac(n-2);
	// }
// }

#include <iostream>
#include <vector>
using namespace std;
int fibonac(int n);
int main(){
	int N;
	cin>>N;
	cout<<fibonac(n);
}
int fibonac(int n){
	vector <int>fib=[1,1];
	for(int i=2;i<n;i++){
		int temp=fib[i-1]+fib[i-2]
	}
	return *(fib.end()-1);
}
