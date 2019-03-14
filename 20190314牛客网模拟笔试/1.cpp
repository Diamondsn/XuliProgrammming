#include<iostream>
#include<string>
using namespace std;

int main(){
	int  n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	int result=0;
	for(int i=0;i<a.size();++i){
       int temp= abs(a[i]-b[i]);
	   int t=temp>10-temp?10-temp:temp;
	   result+=t;
}
	cout<<result;
	system("pause");
}