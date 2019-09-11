#include <iostream>
#include<vector>
#include<set>
using namespace std;

long compute(long m){
    if(m%4==1){
        return 1;
    }else if(m%4==2){
        return m+1;
    }else if(m%4==3){
        return 0;
    }else{
        return m;
    }
}
long test1(long m,long n){
    if(m==n){
        return 0;
    }else if(m==1){
        return compute(n);
    }else{
        long res1=compute(m-1);
        long res2=compute(n);
        return res1^res2;
    }
}

int main(){
    long m,n;
    cin>>m>>n;
    cout<<test1(m,n);
    system("pause");
}