#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

int test(vector<pair<int,int>>&vec){
    int result=0;
    map<pair<int,int>,pair<bool,bool>>mymap;
    for(int i=0;i<vec.size();++i){
        int x=vec[i].first;
        int y=vec[i].second;
        //横向
        for(int j=1;j<=x;++j){
            if(mymap.find(make_pair(j,y))==mymap.end()){
                mymap.insert(make_pair(make_pair(j,y),make_pair(1,0)));
            }else{
                mymap[make_pair(j,y)].first=1;
            }
        }
        //纵向
        for(int k=0;k<=y;++k){
            if(mymap.find(make_pair(x,k))==mymap.end()){
                mymap.insert(make_pair(make_pair(x,k),make_pair(0,1)));
            }else{
                mymap[make_pair(x,k)].second=1;
            }
        }
    }
    map<pair<int,int>,pair<bool,bool>>::iterator iter;
    for(iter=mymap.begin();iter!=mymap.end();++iter){
        if(iter->second.first==1&&iter->second.second==1){
            result++;
        }
    }
    return result;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>vec;
        while(n--){
            int x,y;
            cin>>x>>y;
            vec.push_back(make_pair(x,y));
        }
        int res=test(vec);
        cout<<res<<endl;
    }
    //system("pause");
}

// 输入
// 5
// 4
// 1 1
// 2 2
// 3 3
// 4 4
// 4
// 1 4
// 2 3
// 3 2
// 4 1
// 4
// 2 1
// 1 2
// 3 1
// 1 3
// 5
// 1 5
// 5 1
// 5 5
// 1 1
// 5 5
// 5
// 1 3
// 1 4
// 1 2
// 1 1
// 1 5

//输出
// 4
// 10
// 5
// 4
// 5