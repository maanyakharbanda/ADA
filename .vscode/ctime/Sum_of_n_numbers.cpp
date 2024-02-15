#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
int sum(int n){
    if(n==0){
        return 0;
    }
    return n+sum(n-1);
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=10;i<1e4;i+=1000){
        clock_t time_req;
        int t=0;
        for(int m=0;m<10;m++){
        time_req=clock();
        sum(i);
        time_req=clock()-time_req;
        t+=time_req;
    }
    t=t/10;
    store.push_back({i,t});
    }
}
int main(){
    vector<pair<int,int>>store;
    evaluate(store);
    cout<<"Number of Inputs "<<"     "<<"Time "<<endl;
    for(auto i:store){
        cout<<i.first<<"                    "<<i.second<<endl;
    }
}