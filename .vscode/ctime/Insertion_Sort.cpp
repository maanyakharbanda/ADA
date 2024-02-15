#include<bits/stdc++.h>
#include<vector>
#include<ctime>
using namespace std;

void insertion_sort(vector<int>&arr,int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
            insertion_sort(arr,i);
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
    cout<<"Number of inputs"<<"       "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<"               "<<i.second<<endl;
    }
}