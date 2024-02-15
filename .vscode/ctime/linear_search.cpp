#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
bool linear_search(vector<int>&arr,int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}
void random_generator(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        arr.push_back(rand());
    }
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=10;i<1e4;i+=1000){
        vector<int>arr;
        random_generator(arr,i);
        clock_t time_req;
        int t=0;
        for(int m=0;m<10;m++){
            time_req=clock();
            linear_search(arr,i,arr[rand()%i]);
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
    cout<<"Number of inputs"<<" "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<" "<<i.second<<endl;
    }
}