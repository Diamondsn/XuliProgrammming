/*
timu
*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<set>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    if(y>=(2*x))
    cout<<0;
    else if(x>=y){
        if(y%2==0){
            cout<<(y/2-1);
        }
        else{
            cout<<(y/2);
        }
    }else{
        cout<<(x-(y/2));
    }
    return 0;
}