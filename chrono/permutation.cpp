#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
void gen(vector<int>&arr,int n){
    for(int i=1;i<=n;i++){
        arr[i-1]=i;
    }
}
void PG(vector<int>&arr,int s,int n){
    if(s==n){
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        return;
    }
    else{
        for(int i=s;i<n;i++){
            swap(arr[i],arr[s]);
            PG(arr,s+1,n);
            swap(arr[i],arr[s]);
        }
    }
}
void solve(vector<pair<int,int>>&store){
    for(int i=1;i<10;i++){
        vector<int>arr(i);
        gen(arr,i);
        int t=0;
        int avg=0;
    for(int m=0;m<10;m++){
        auto start=high_resolution_clock::now();
        PG(arr,0,i);
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
    solve(store);
    cout<<"Number of Inputs"<<" "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<" "<<i.second<<endl;
    }
}