#include<bits/stdc++.h>
#include<ctime>
#include<vector>
using namespace std;
void bubble_sort(vector<int>&arr,int n){
    for(int i=0;i<n-1;i++){
        int didSwap=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void input_generator(vector<pair<int,int>>&store){
    for(int i=10;i<1e4;i+=1000){
        vector<int>arr(i);
        generate(arr.begin(),arr.end(),rand);
        clock_t time_req;
        int t=0;
        for(int m=0;m<10;m++){
            time_req=clock();
            bubble_sort(arr,i);
            time_req=clock()-time_req;
            t+=time_req;
        }
        t=t/10;
        store.push_back({i,t});
    }
}
int main(){
    vector<pair<int,int>>store;
    input_generator(store);
    cout<<"Number of Inputs"<<"    "<<"Time taken"<<endl;
    for(auto i:store){
        cout<<i.first<<"                           "<<i.second<<endl;
    }
}