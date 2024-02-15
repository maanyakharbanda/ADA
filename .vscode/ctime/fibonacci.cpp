#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
int fib(int n){
    if(n==0||n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=1;i<50;i+=10){
        clock_t time_req;
        int t=0;
        for(int m=0;m<10;m++){
            time_req=clock();
            fib(i);
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
    cout<<"Number of Inputs"<<" "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<" "<<i.second<<endl;
    }
}