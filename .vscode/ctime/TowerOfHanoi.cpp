#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
void TOH(int n,int A,int B,int C){  // A(from) B(using) C(to)
    if(n>0){
        TOH(n-1,A,C,B);
        cout<<"("<<A<<","<<C<<")"<<endl;
        TOH(n-1,B,A,C);
    }
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=1;i<10;i++){
        clock_t time_req;
        int A=1,B=2,C=3;
        int t=0;
        for(int m=0;m<10;m++){
            time_req=clock();
            TOH(i,A,B,C);
            time_req=clock()-time_req;
            t+=time_req;
        }
        t=t/10;
        store.push_back({i,t});
    }
}
int main(){
    vector<pair<int,int>>store;
    cout<<"Number of Inputs"<<" "<<"Time"<<endl;
    evaluate(store);
    for(auto i:store){
        cout<<i.first<<" "<<i.second<<endl;
    }
}