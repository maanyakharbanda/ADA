#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=0;i<15;i++){
        int t=0;
        int avg=0;
    for(int m=1;m<10;m++){
        auto start=high_resolution_clock::now();
        fact(i);
        auto stop=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(stop-start);
        t+=duration.count();
    }
    avg=t/10;
    store.push_back({i,avg});
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