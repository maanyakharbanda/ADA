#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
void TT(int index,int n,int* arr){
    if(index==n+1){
        // for(int i=0;i<n;i++){
        //     cout<<arr[i];
        // }
        // cout<<endl;
        return;
    }
    else{
        arr[index]=1;
        TT(index+1,n,arr);
        arr[index]=0;
        TT(index+1,n,arr);
    }
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=1;i<=20;i++){
    int arr[i];
    int t=0;
    int avg=0;
    for(int m=0;m<10;m++){
        auto start=high_resolution_clock::now();
        TT(0,i,arr);
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
    cout<<"Number of inputs"<<" "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<" "<<i.second<<endl;
    }
}